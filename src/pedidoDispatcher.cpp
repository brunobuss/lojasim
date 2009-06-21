#include <pedidoDispatcher.h>    

pedidoDispatcher::pedidoDispatcher()
{
    estoquista a;
    
    a.setID(MAXSELLER);
    a.setName(estoquistaName[0]);
    lE.push_back(a);

    a.setID(MAXSELLER+1);
    a.setName(estoquistaName[1]);
    lE.push_back(a);

    a.setID(MAXSELLER+2);
    a.setName(estoquistaName[2]);
    lE.push_back(a);
}

void pedidoDispatcher::run()
{
    exec();
}

void pedidoDispatcher::adicionaPedido(pedido p)
{
    mutex.lock();
    lP.push_back(p);
    if(!lE.isEmpty())
    {
	    if(lP.size() > QTDMINPEDIDOS)
	    {
		iniciaThreadReposicao(lP, lE.takeFirst());
		lP.clear();
	    }

    }
    mutex.unlock();
}

void pedidoDispatcher::retornaEstoquista(estoquista e)
{
    mutex.lock();
    if(lP.size() > QTDMINPEDIDOS)
    {
	iniciaThreadReposicao(lP, lE.takeFirst());
	lP.clear();
    }

    mutex.unlock();
}

void pedidoDispatcher::iniciaThreadReposicao(QList<pedido> lP, estoquista p)
{
    /* TODO: Disparar uma nova thread */
}
