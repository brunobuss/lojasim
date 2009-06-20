#include<vendaDispatcher.h>

vendaDispatcher::vendaDispatcher()
{

    /*TODO: Criar os 10 vendedores */

}

void vendaDispatcher::run(relatorio* relatorio)
{
    rlt = relatorio;
    exec();
}


void vendaDispatcher::adicionaCliente(cliente c)
{  
    //Para garantir que é thread-safe... só deixa que 1 modifique a lista por vez.
    mutex.lock();

    if(lC.size() > QNT_MAX_CLIENTES)
    {
            emit registerLog("Cliente " + c.getNomeID() + " chegou e foi embora pois a loja estava cheia.");
    }

    emit registerLog("Cliente " + c.getNomeID() + " chegou a loja.");

    for(int i = 0; i < lV.size(); i++)
    {
        if(lV[i].getId() == c.getVendedorPref() && lV[i].podeAtenderClientePref())
        {
            iniciaThreadVenda(c, lV[i]);
            mutex.unlock();
            return;
        }
    }

    if(!lV.isEmpty())
    {
        cliente v = lV.takeFirst();
        iniciaThreadVenda(c, v);
    }
    else
    {
        lC.append(c);
    }

    mutex.unlock();
}

void vendaDispatcher::retornaVendedor(vendedor v)
{
    //Para garantir que é thread-safe... só deixa que 1 modifique a lista por vez.
    mutex.lock();

    int c = verificaVendedorPreferencial(v);

    if(c != -1 && v.podeAtenderClientePref())
    {
        iniciaThreadVenda(lC[c], v);
    }
    else if(!lC.isEmpty())
    {
        cliente c = lC.takeFirst();
        iniciaThreadVenda(c, v);
    }
    else
    {
        lV.append(v);
    }
    mutex.unlock();
}

//Verifica de algum cliente da fila de espera tem o vendedor v como vendedor preferencial.
int vendaDispatcher::verificaVendedorPreferencial(vendedor v)
{   
    for(int i = 0; i < lC.size(); i++)
    {
        if(lC[i].getVendedorPref() == v.getId())return i;
    }

    return -1;
}

void vendaDispatcher::iniciaThreadVenda(cliente c, vendedor v)
{
    /* TODO: Disparar uma nova thread */
}
