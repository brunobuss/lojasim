#include <pedidoDispatcher.h>    

pedidoDispatcher::pedidoDispatcher()
{
    Estoquista *a;
    int i;
    
    a = new Estoquista();
    a->setID(QTDVENDEDORES);
    a->setName(estoquistaNames[0]);
    lE.push_back(a);

    a = new Estoquista();
    a->setID(QTDVENDEDORES+1);
    a->setName(estoquistaNames[1]);
    lE.push_back(a);

    a = new Estoquista();
    a->setID(QTDVENDEDORES+2);
    a->setName(estoquistaNames[2]);
    lE.push_back(a);
    
    for(i = 0; i < QTDPROD; i++)
    {
    	lP[i] = 0;
    }
    
}

void pedidoDispatcher::run()
{
    exec();
}

void pedidoDispatcher::adicionaPedido(Pedido *p)
{
    int i;
    Pedido *ped;
    mutex.lock();
    emit registerLog("Chegou pedido de reposicao para o produto " + QString::number(p->getID()));

    lP[p->getID()]++;
    delete p;
    
    for(i = 0 ; i< QTDPROD && !lE.empty(); i++)
    {
    	if(lP[i] >= MINPEDIDOS)
    	{
    		lP[i] = 0;
    		ped = new Pedido();
    		ped->setID(i);
    		iniciaThreadReposicao(ped, lE.takeFirst());
    	}
    }
    
    mutex.unlock();
}

void pedidoDispatcher::retornaEstoquista(Estoquista *e)
{
    Pedido *ped;
    int i;
    
    mutex.lock();
    
    lE.push_back(e);
    emit registerLog("Um Estoquista foi liberado " + QString::number(e->getID()));
    
    for(i = 0 ; i<QTDPROD && !lE.empty(); i++)
    {
    	if(lP[i] >= MINPEDIDOS)
    	{
    		lP[i] = 0;
    		ped = new Pedido();
    		ped->setID(i);
    		iniciaThreadReposicao(ped, lE.takeFirst());
    	}
    }

    mutex.unlock();
}

void pedidoDispatcher::iniciaThreadReposicao(Pedido* p, Estoquista *e)
{
    pedidoThread *pedido = new pedidoThread(p,e);
    connect(pedido, SIGNAL(registerLog(QString)), this, SIGNAL(registerLog(QString)));
    connect(pedido, SIGNAL(registerLogCompra(logMessageCompra*)), this, SIGNAL(registerLogCompra(logMessageCompra*)));
    connect(pedido, SIGNAL(retornaEstoquista()), this, SLOT(retornaEstoquista()));
    pedido->start();
}
