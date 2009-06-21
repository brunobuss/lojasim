#include <logSys.h>

void logSys::run()
{
    exec();
}


void logSys::geraRelatorioDiario()
{
	gmut.lock();
	cmut.lock();
	vmut.lock();

	/* TODO: Escrever os trecos aqui */
		

	vmut.unlock();
	cmut.unlock();
	gmut.unlock();
}

void logSys::receiveLog(QString msg)
{
    gmut.lock();
    log.append(msg);

    /* TODO: Escrever na tela o que ta acontecendo */

    gmut.unlock();
}

void logSys::receiveLogCompra(logMessageCompra lc)
{
    cmut.lock();
    lCompra.append(lc);
    receiveLog(lc.getLogMessage());
    cmut.unlock();
}

void logSys::receiveLogVenda(logMessageVenda lv)
{
    vmut.lock();
    lVenda.append(lv);
    receiveLog(lv.getLogMessage());
    vmut.unlock();
}
