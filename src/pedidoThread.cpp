#include <pedidoThread.h>

pedidoThread::pedidoThread(Pedido* pedidos, Estoquista *estoq)
{
	p = pedidos;
	e = estoq;
	
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

void pedidoThread::run()
{
	int qtdCompra;
	int idprod;
	int tot;
	int qtd;
	
	logMessageCompra* lc = new logMessageCompra();
	
	qsrand(time(NULL));
	
	QThread::msleep(200 * (qrand()%4 + 1));
	
	idprod = p->getID();
	
	pD = (int*)dsm.data();
	dR = (int*)rsm.data();
	pT = (int*)qsm.data();
	pN = (int*)nsm.data();

	dsm.lock();
		qsm.lock();

			tot = pT[idprod];
			nsm.lock();
				qtd = pN[idprod];
			nsm.unlock();

		qsm.unlock();

		if(qtd == 0)qtd = 1;	
		qtdCompra = ((tot*1.0)/(qtd*1.0))*1.2;
	
		rsm.lock();
		dR[idprod] = 0;
		rsm.unlock();
	
		pD[idprod]+= qtdCompra;
	dsm.unlock();

	emit registerLog("Comprados " + QString::number(qtdCompra) + " para o produto " + QString::number(idprod));
	
	lc->setProdutoComprado(idprod, qtdCompra);
	
	emit registerLogCompra(lc);
	emit finalizouPedido(e);

	delete p;
}


