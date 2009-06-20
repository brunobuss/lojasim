#include <pagamentoDispatcher.h>

pagamentoDispatcher(relatorio* relatorio)
{
    rlt = relatorio;

    /* TODO: Gera os 2 operadores de caixas */
}

void pagamentoDispatcher::run()
{
    exec();
}

void pagamentoDispatcher::adicionaCliente(cliente c)
{
    mutex.lock();

    if(!lCL.isEmpty())
    {
        caixa cx = lCL.takeFirst();
        iniciaThreadPagamento(c, cx);
    }
    else
    {
        lC.append(c);
    }

    mutex.unlock();
}

void pagamentoDispatcher::retornaCaixa(caixa cx)
{
    mutex.lock();
    if(!lC.isEmpty())
    {
        cliente c = lC.takeFirst();
        iniciaThreadPagamento(c, cx);
    }
    else
    {
        lCL.append(cx);
    }
    mutex.unlock();
}

void pagamentoDispatcher::iniciaThreadPagamento(cliente c, caixa cx)
{
    /* TODO: Disparar uma nova thread */
}