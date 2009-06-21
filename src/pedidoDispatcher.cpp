#include <pedidoDispatcher.h>    

pedidoDispatcher::pedidoDispatcher()
{
    Estoquista a;
    
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

void pedidoDispatcher::adicionaPedido(Pedido p)
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

void pedidoDispatcher::retornaEstoquista(Estoquista e)
{
    mutex.lock();
    if(lP.size() > QTDMINPEDIDOS)
    {
	iniciaThreadReposicao(lP, lE.takeFirst());
	lP.clear();
    }

    mutex.unlock();
}

void pedidoDispatcher::iniciaThreadReposicao(QList<Pedido> lP, Estoquista p)
{
    /* TODO: Disparar uma nova thread */
}
