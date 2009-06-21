#include<vendaDispatcher.h>

vendaDispatcher::vendaDispatcher()
{
	int i;
	Seller *a;

	for(i = 0; i < QTDVENDEDORES; i++)
	{
		a = new Seller();
		a->setID(i);
		a->setName(sellerName[i]);
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
            emit registerLog("Cliente " + c->getNomeID() + " chegou e foi embora pois a loja estava cheia. [" +
			   	QString::number(lC.size()) + "][" + QString::number(lV.size()) + "]");
	    return;
    }

    emit registerLog("Cliente " + c->getNomeID() + " chegou a loja. [" + QString::number(lC.size()) + "][" +
	   QString::number(lV.size()) + "]");

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
        Seller *v = lV.takeFirst();
        iniciaThreadVenda(c, v);
    }
    else
    {
        lC.append(c);
    }

    mutex.unlock();
    return;
}

void vendaDispatcher::retornaVendedor(Seller *v)
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
int vendaDispatcher::verificaVendedorPreferencial(Seller *v)
{   
    for(int i = 0; i < lC.size(); i++)
    {
        if(lC[i]->getVendedorPref() == v->getID())return i;
    }

    return -1;
}

void vendaDispatcher::iniciaThreadVenda(Cliente *c, Seller *v)
{
    vendaThread* novaThread = new vendaThread(c, v);
    novaThread->start();
    emit registerLog("Atendendo cliente " + c->getNomeID());
}
