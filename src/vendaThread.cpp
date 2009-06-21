#include <vendaThread.h>

vendaThread::vendaThread(Cliente cl, Seller sl)
{
	c = cl;
	s = sl;
}

void vendaThread::run()
{
	exec();
}

void vendaThread::realizaVenda()
{
	/* TODO: Prepara a venda */

	/* TODO: Faz a venda */

	emit finalizouVenda(s);
	emit finalizouVenda(c);
}
