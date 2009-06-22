#include <pagamentoThread.h>

pagamentoThread::pagamentoThread(Cliente* cl, Caixa* caixa)
{
	c = cl;
	cx = caixa;
}

void pagamentoThread::run()
{
	
	qsrand(time(NULL));
	
	QThread::msleep(UNIDTEMPO * (qrand()%2) + 1);
	
	emit registerLog("O cliente " + c->getNomeID() + " efetuou o pagameno e saiu da loja");	
	emit finalizouPagamento(cx);
	
	delete c;
}
