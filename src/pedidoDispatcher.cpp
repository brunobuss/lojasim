#include <pedidoDispatcher.h>    

pedidoDispatcher::pedidoDispatcher(relatorio* relatorio)
{
    rlt = relatorio;

    /* TODO: Criar os 3 estoquistas */
}

void pedidoDispatcher::run()
{
    exec();
}

void pedidoDispatcher::adicionaPedido(pedido p)
{
    mutex.lock();
    mutex.unlock();
}

void pedidoDispatcher::retornaEstoquista(estoquista e)
{
    mutex.lock();
    mutex.unlock();
}

void pedidoDispatcher::iniciaThreadReposicao(QList<pedido> lP, estoquista p)
{
    /* TODO: Disparar uma nova thread */
}