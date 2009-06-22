#include <vendaThread.h>

vendaThread::vendaThread(Cliente* cl, Seller* sl)
{
	c = cl;
	s = sl;

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
}

void vendaThread::run()
{
	emit registerLog("Atendendo cliente " + c->getNomeID() + "...");

	qsrand(time(NULL));

	QThread::msleep(100 * (1 + qrand()%4) );

	pD = (int*)dsm.data();
	dR = (int*)rsm.data();
	
	logMessageVenda* log = new logMessageVenda(c->getID(), s->getID());


	for(int i = 0; i < c->getNumProdutos(); i++)
	{
		int j = c->getProduto(i);
		int qnt = c->getQtdProduto(i);

		dsm.lock();
			if(pD[j] == 0 || (pD[j] < qnt && c->getCompraMenos() == false))
			{
				rsm.lock();
				dR[j] += qnt;
				rsm.unlock();
			}
			else
			{
				if(pD[j] <= qnt)
				{
					setProdutoVendido(j, pD[j]);
					pD[j] = 0;
				}
				else
				{
					setProdutoVendido(j, qnt);
					pD[j] -= qnt;	
				}


			}
		dsm.unlock();

		if(pD[j] <= PONTO_RESUP)
		{
			Pedido* rep = new Pedido();
			rep->setID(j);
			emit fazPedidoReposicao(rep);
		}	
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

