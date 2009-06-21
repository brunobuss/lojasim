#include <pedidoDispatcher.h>    

pedidoDispatcher::pedidoDispatcher(relatorio* relatorio)
{
    rlt = relatorio;

    /* TODO: Criar os 3 estoquistas */
}

void pedidoDispatcher::run()
{
	
    mutex.lock();
    if(!lE.isEmpty())
    {
	    if(lP.size() > QTDMINPEDIDOS)
	    {
		iniciaThreadReposicao(lP, lE.takeFirst());
		lP.clear();
	    }
    }
    mutex.unlock();
    exec();
}

void pedidoDispatcher::adicionaPedido(pedido p)
{
    mutex.lock();
    lP.push_back(p);
    mutex.unlock();
}

void pedidoDispatcher::retornaEstoquista(estoquista e)
{
    mutex.lock();
    lE.push_back(e);
    mutex.unlock();
}

void pedidoDispatcher::iniciaThreadReposicao(QList<pedido> lP, estoquista p)
{
    /* TODO: Disparar uma nova thread */
}
