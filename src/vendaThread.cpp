#include <vendaThread.h>

vendaThread::vendaThread(Cliente* cl, Seller* sl)
{
	c = cl;
	s = sl;
}

void vendaThread::run()
{
	emit registerLog("Atendendo cliente " + c->getNomeID() + "...");

	qsrand(time(NULL));

	QThread::msleep(100 * (1 + qrand()%4) );

	/* TODO: Prepara a venda */

	/* TODO: Faz a venda */


	emit registerLog("Cliente " + c->getNomeID() + " atendido.");
	emit finalizouVenda(s);
	emit finalizouVenda(c);
}

