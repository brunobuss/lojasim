#include <vendaThread.h>

pagamentoThread::pagamentoThread(Cliente cl, Caixa caixa)
{
	c = cl;
	cx = caixa;
}

void pagamentoThread::run()
{
	exec();
}

void pagamentoThread::realizaPagamento()
{
	/* TODO: Prepara o pagamento */

	/* TODO: Faz o pagamento */

	emit finalizouVenda(c);
	emit finalizouVenda(cx);
}