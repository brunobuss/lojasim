#include <pagamentoDispatcher.h>

pagamentoDispatcher::pagamentoDispatcher()
{
   	Caixa *a;

	a = new Caixa();
	a->setID(0);
	a->setName(caixaNames[0]);
	lCL.push_back(a);

	a = new Caixa();
	a->setID(1);
	a->setName(caixaNames[1]);
	lCL.push_back(a);

}

void pagamentoDispatcher::run()
{
    exec();
}

void pagamentoDispatcher::adicionaCliente(Cliente *c)
{
    mutex.lock();

    emit registerLog("Cliente " + c->getNomeID() + " entrou na fila do caixa.");

    if(!lCL.isEmpty())
    {
        Caixa *cx = lCL.takeFirst();
        iniciaThreadPagamento(c, cx);
    }
    else
    {
        lC.append(c);
    }

    mutex.unlock();
}

void pagamentoDispatcher::retornaCaixa(Caixa *cx)
{
    mutex.lock();
    if(!lC.isEmpty())
    {
        Cliente *c = lC.takeFirst();
        iniciaThreadPagamento(c, cx);
    }
    else
    {
        lCL.append(cx);
    }
    mutex.unlock();
}

void pagamentoDispatcher::iniciaThreadPagamento(Cliente *c, Caixa *cx)
{
    /* TODO: Disparar uma nova thread */
}
