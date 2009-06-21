#include <lojaSim.h>

void lojaSim::executaSimulador(int argc, char* argv[])
{
    QCoreApplication* app = new QCoreApplication(argc, argv);
    QSharedMemory* prdDispSM = new QSharedMemory("produtosDisponiveis");
    
    if(prdDispSM->create(sizeof(int)*40))
    {
        int* p = (int*)prdDispSM->data();
        qsrand(time(NULL));
        for(int i = 0; i < QTDPROD; i++)p[i] = 20+qrand()%11;
    }
    else
    {
        qDebug("Falha ao criar a região de memória compartilhada.");
        exit(ERROR_SHAREDMEMORY_FAILED);
    }

    /* Prepara e lanca todas as threads */
    logSys* ls = new logSys();
    
    vendaDispatcher* vd = new vendaDispatcher();
    pagamentoDispatcher* pd = new pagamentoDispatcher();
    pedidoDispatcher* ped = new pedidoDispatcher();

    //geradorCliente* gc = new geradorCliente();
    
    connect(vd, SIGNAL(registerLog(QString)), ls, SLOT(receiveLog(QString)));
    connect(vd, SIGNAL(registerLogVenda(logMessageVenda)), ls, SLOT(receiveLogVenda(logMessageVenda)));

    connect(pd, SIGNAL(registerLog(QString)), ls, SLOT(receiveLog(QString)));

    connect(ped, SIGNAL(registerLog(QString)), ls, SLOT(receiveLog(QString)));
    connect(ped, SIGNAL(registerLog(logMessageCompra)), ls, SLOT(receiveLogCompra(logMessageCompra)));

    //connect(gc, SIGNAL(geraRelatorioDiario()), ls, SLOT(geraRelatorioDiario()));

    ls->start();
    vd->start();
    pd->start();
    ped->start();


    app->exec();



}

int main(int argc, char* argv[])
{

	lojaSim* sim = new lojaSim();
    
	sim->executaSimulador(argc, argv);
    
}
