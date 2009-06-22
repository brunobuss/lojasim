#include <vendaThread.h>

vendaThread::vendaThread(Cliente* cl, Vendedor* sl)
{
	c = cl;
	s = sl;

	//Preparando o acesso as Shared Memories
	dsm.setKey(SM_PROD_ESTOQUE);
	if(!dsm.attach())
	{
		QString msg = dsm.errorString();
		qDebug() << msg;
		exit(ERROR_SHAREDMEMORY_FAILED);
	}

	rsm.setKey(SM_PROD_REPRIMIDO);
	if(!rsm.attach())
	{
		QString msg = rsm.errorString();
		qDebug() << msg;
		exit(ERROR_SHAREDMEMORY_FAILED);
	}

	qsm.setKey(SM_PROD_TOTAL);
	if(!qsm.attach())
	{
		QString msg = qsm.errorString();
		qDebug() << msg;
		exit(ERROR_SHAREDMEMORY_FAILED);
	}

	nsm.setKey(SM_PROD_NRO);
	if(!nsm.attach())
	{
		QString msg = nsm.errorString();
		qDebug() << msg;
		exit(ERROR_SHAREDMEMORY_FAILED);
	}
}

void vendaThread::run()
{
	emit registerLog("Atendendo cliente " + c->getNomeID() + "...");

	qsrand(time(NULL));

	QThread::msleep(UNIDTEMPO * (1 + qrand()%2) );

	pD = (int*)dsm.data();
	dR = (int*)rsm.data();
	pT = (int*)qsm.data();
	pN = (int*)nsm.data();
	
	logMessageVenda* log = new logMessageVenda(c->getID(), s->getID());


	for(int i = 0; i < c->getNumProdutos(); i++)
	{
		int j = c->getProduto(i);
		int qnt = c->getQtdProduto(i);

		dsm.lock();
			//Verifica se o estoque esta vazio e/ou se o cliente nao
			//aceita comprar menos itens do que os disponiveis
			if(pD[j] <= 0 || (pD[j] < qnt && c->getCompraMenos() == false))
			{
				rsm.lock();
				dR[j] += pD[j] - qnt;
				rsm.unlock();
			}
			else
			{
				//Cliente quer mais itens que os disponiveis, vende o que tiver
				if(pD[j] <= qnt)
				{
					log->setProdutoVendido(j, pD[j]);
					rsm.lock();
					dR[j] += pD[j] - qnt;
					rsm.unlock();

					qsm.lock();
					pT[j] += pD[j];
					qsm.unlock();

					pD[j] = 0;
				}
				//Venda normal
				else
				{
					log->setProdutoVendido(j, qnt);
					pD[j] -= qnt;	

					qsm.lock();
					pT[j] += qnt;
					qsm.unlock();
				}

				nsm.lock();
				pN[j]++;
				nsm.unlock();			
	
			}

		//Verifica necessidade de fazer um pedido de resuprimento
		rsm.lock();
		if(pD[j] <= PONTO_RESUP || dR[j] >= PONTO_RESUP)
		{
			Pedido* rep = new Pedido();
			rep->setID(j);
			emit fazPedidoReposicao(rep);
		}
		rsm.unlock();

		dsm.unlock();
	}

	if(c->getVendedorPref() == s->getID())
	{
		s->atendeuClientePreferencial();
	}
	else
	{
		s->atendeuCliente();
	}

	emit registerLog("Cliente " + c->getNomeID() + " atendido.");
	emit finalizouVenda(s);
	emit finalizouVenda(c);
	emit registerLogVenda(log);
}

