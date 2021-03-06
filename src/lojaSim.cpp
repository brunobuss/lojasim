#include <lojaSim.h>

lojaSim::lojaSim(int argc, char* argv[])
{

    QCoreApplication* app = new QCoreApplication(argc, argv);

    QTimer::singleShot(500, this, SLOT(executaSimulador()));

    app->exec();
}

void lojaSim::executaSimulador()
{

    // Prepara regioes de memoria compartilhada */
    dsm.setKey(SM_PROD_ESTOQUE);
    if(dsm.create(sizeof(int)*QTDPROD*2))
    {
	qDebug("Regiao de memoria criada.");
    }
    else
    {
        qDebug("Falha ao criar a regiao de memoria compartilhada.");
	QString msg = dsm.errorString();
	qDebug() << msg;
	if(!dsm.attach())
	{
            exit(ERROR_SHAREDMEMORY_FAILED);
	}
    }

    int* p = (int*)dsm.data();
    qsrand(time(NULL));
    for(int i = 0; i < QTDPROD; i++)p[i] = 20+qrand()%11;
 
    rsm.setKey(SM_PROD_REPRIMIDO);
    if(rsm.create(sizeof(int)*QTDPROD*2))
    {
	qDebug("Regiao de memoria criada.");
    }
    else
    {
        qDebug("Falha ao criar a regiao de memoria compartilhada.");
	QString msg = rsm.errorString();
	qDebug() << msg;
	if(!rsm.attach())
	{
            exit(ERROR_SHAREDMEMORY_FAILED);
	}
    }

    p = (int*)rsm.data();
    qsrand(time(NULL));
    for(int i = 0; i < QTDPROD; i++)p[i] = 0;

    qsm.setKey(SM_PROD_TOTAL);
    if(qsm.create(sizeof(int)*QTDPROD*2))
    {
	qDebug("Regiao de memoria criada.");
    }
    else
    {
        qDebug("Falha ao criar a regiao de memoria compartilhada.");
	QString msg = qsm.errorString();
	qDebug() << msg;
	if(!qsm.attach())
	{
            exit(ERROR_SHAREDMEMORY_FAILED);
	}
    }

    p = (int*)qsm.data();
    qsrand(time(NULL));
    for(int i = 0; i < QTDPROD; i++)p[i] = 0;


    nsm.setKey(SM_PROD_NRO);
    if(nsm.create(sizeof(int)*QTDPROD*2))
    {
	qDebug("Regiao de memoria criada.");
    }
    else
    {
        qDebug("Falha ao criar a regiao de memoria compartilhada.");
	QString msg = nsm.errorString();
	qDebug() << msg;
	if(!nsm.attach())
	{
            exit(ERROR_SHAREDMEMORY_FAILED);
	}
    }

    p = (int*)nsm.data();
    qsrand(time(NULL));
    for(int i = 0; i < QTDPROD; i++)p[i] = 0;


    /* Prepara e lanca todas as threads */
    logSys* ls = new logSys();
    
    vendaDispatcher* vd = new vendaDispatcher();
    pagamentoDispatcher* pd = new pagamentoDispatcher();
    pedidoDispatcher* ped = new pedidoDispatcher();

    geradorCliente* gc = new geradorCliente();
    
    connect(vd, SIGNAL(registerLog(QString)), ls, SLOT(receiveLog(QString)));
    connect(vd, SIGNAL(registerLogVenda(logMessageVenda*)), ls, SLOT(receiveLogVenda(logMessageVenda*)));
    connect(vd, SIGNAL(passaClienteParaCaixa(Cliente*)), pd, SLOT(adicionaCliente(Cliente*)));
    connect(vd, SIGNAL(passaPedidoParaEstoque(Pedido*)), ped, SLOT(adicionaPedido(Pedido*)));

    connect(pd, SIGNAL(registerLog(QString)), ls, SLOT(receiveLog(QString)));

    connect(ped, SIGNAL(registerLog(QString)), ls, SLOT(receiveLog(QString)));
    connect(ped, SIGNAL(registerLogCompra(logMessageCompra*)), ls, SLOT(receiveLogCompra(logMessageCompra*)));

    connect(gc, SIGNAL(geraRelatorioDiario()), ls, SLOT(geraRelatorioDiario()));
    connect(gc, SIGNAL(geraCliente(Cliente*)), vd, SLOT(adicionaCliente(Cliente*)));

    ls->start();
    vd->start();
    pd->start();
    ped->start();
}

int main(int argc, char* argv[])
{
	lojaSim* sim = new lojaSim(argc, argv);
}
