#include <vendaThread.h>

pedidoThread::pedidoThread(QList<Pedido> pedidos, Estoquista estoq)
{
	lP = pedidos;
	e = estoq;
}

void pedidoThread::run()
{
	exec();
}

void pedidoThread::realizaPedido()
{
	/* TODO: Prepara a venda */

	/* TODO: Faz a venda */

	emit finalizouPedido(e);
}
