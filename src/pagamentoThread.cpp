#include <pagamentoThread.h>

pagamentoThread::pagamentoThread(Cliente* cl, Caixa* caixa)
{
	c = cl;
	cx = caixa;
}

void pagamentoThread::run()
{
	
	qsrand(time(NULL));
	
	QThread::msleep(200 * (qrand()%4) + 1);
	
	emit registerLog("O cliente " + c->getNomeID() + " efetuou o pagameno e saiu da loja");
	
	emit finalizouPagamento(cx);
	
	delete c;
}
