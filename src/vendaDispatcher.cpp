#include<vendaDispatcher.h>

vendaDispatcher::vendaDispatcher()
{
	int i;
	Vendedor *a;

	for(i = 0; i < QTDVENDEDORES; i++)
	{
		a = new Vendedor();
		a->setID(i);
		a->setName(vendedorName[i]);
		lV.push_back(a);
	}
}

void vendaDispatcher::run()
{
    emit registerLog("Thread do venda Dispatcher sendo iniciada!\n");

    exec();
}


void vendaDispatcher::adicionaCliente(Cliente *c)
{  
    //Para garantir que é thread-safe... só deixa que 1 modifique a lista por vez.
    mutex.lock();

    if(lC.size() > QNT_MAX_CLIENTES)
    {
            emit registerLog("Cliente " + c->getNomeID() + " chegou e foi embora pois a loja estava cheia.");
	    return;
    }

    emit registerLog("Cliente " + c->getNomeID() + " chegou a loja.");

    for(int i = 0; i < lV.size(); i++)
    {
        if(lV[i]->getID() == c->getVendedorPref() && lV[i]->podeAtenderClientePref())
        {
            iniciaThreadVenda(c, lV.takeAt(i));
            mutex.unlock();
            return;
        }
    }

    if(!lV.isEmpty())
    {
        Vendedor *v = lV.takeFirst();
        iniciaThreadVenda(c, v);
    }
    else
    {
        lC.append(c);
    }

    mutex.unlock();
    return;
}

void vendaDispatcher::retornaVendedor(Vendedor *v)
{
    //Para garantir que é thread-safe... só deixa que 1 modifique a lista por vez.
    mutex.lock();

    int c = verificaVendedorPreferencial(v);

    if(c != -1 && v->podeAtenderClientePref())
    {
        iniciaThreadVenda(lC[c], v);
    }
    else if(!lC.isEmpty())
    {
        Cliente *c = lC.takeFirst();
        iniciaThreadVenda(c, v);
    }
    else
    {
        lV.append(v);
    }
    mutex.unlock();
}

//Verifica de algum cliente da fila de espera tem o vendedor v como vendedor preferencial.
int vendaDispatcher::verificaVendedorPreferencial(Vendedor *v)
{   
    for(int i = 0; i < lC.size(); i++)
    {
        if(lC[i]->getVendedorPref() == v->getID())return i;
    }

    return -1;
}

void vendaDispatcher::iniciaThreadVenda(Cliente *c, Vendedor *v)
{
    vendaThread* novaThread = new vendaThread(c, v);
    connect(novaThread, SIGNAL(registerLog(QString)), this, SIGNAL(registerLog(QString)));
    connect(novaThread, SIGNAL(registerLogVenda(logMessageVenda*)), this, SIGNAL(registerLogVenda(logMessageVenda*)));
    connect(novaThread, SIGNAL(finalizouVenda(Vendedor*)), this, SLOT(retornaVendedor(Vendedor*)));
    connect(novaThread, SIGNAL(finalizouVenda(Cliente*)), this, SIGNAL(passaClienteParaCaixa(Cliente*)));
    connect(novaThread, SIGNAL(fazPedidoReposicao(Pedido*)), this, SIGNAL(passaPedidoParaEstoque(Pedido*)));
    novaThread->start();
}
