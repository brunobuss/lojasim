#include <pagamentoDispatcher.h>

pagamentoDispatcher()
{
   	Caixa a;

	a.setID(0);
	a.setName(caixaNames[0]);
	lCL.push_back(a);

	a.setID(1);
	a.setName(caixaNames[1]);
	lCL.push_back(a);

}

void pagamentoDispatcher::run()
{
    exec();
}

void pagamentoDispatcher::adicionaCliente(Cliente c)
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

void pagamentoDispatcher::retornaCaixa(Caixa cx)
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

void pagamentoDispatcher::iniciaThreadPagamento(Cliente c, Caixa cx)
{
    /* TODO: Disparar uma nova thread */
}
