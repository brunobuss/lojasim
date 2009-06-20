#include<QtCore>

#include<logsys.h>
#include<relatorio.h>
#include<pagamentoDispatcher.h>
#include<pedidoDispatcher.h>
#include<vendaDispatcher.h>

int main(int argc, char* argv[])
{
    QCoreApplication* app = new QCoreApplication(argc, argv);
    QSharedMemory* prdDispSM = new QSharedMemory("produtosDisponiveis");
    
    if(prdDispSM->create(sizeof(int)*40))
    {
        int* p = (int*)prdDispSM->data();
        qsrand(time(NULL));
        for(int i = 0; i < 20; i++)p[i] = qrand()%30;
    }
    else
    {
        qDebug("Falha ao criar a região de memória compartilhada.");
        exit(1);
    }

    /* Prepara e lanca todas as threads */
    logSys* ls = new logSys();
    
    relatorio* rel = new relatorio();

    vendaDispatcher* vd = new vendaDispatcher();
    pagamentoDispatcher* pd = new pagamentoDispatcher();
    pedidoDispatcher* ped = new pedidoDispatcher();

    geradorCliente* gc = new geradorCliente();

    ls->start();
    rel->start();
    vd->start();
    pd->start();
    ped->start();

    app.exec();
}