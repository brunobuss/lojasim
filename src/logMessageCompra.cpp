#include <logMessageCompra.h>

logMessageCompra::logMessageCompra()
{
	for(int i = 0; i < QTDPROD; i++) prodRestoque[i] = 0;
}

void logMessageCompra::setProdutoComprado(int produtoID, int qnt)
{
	if(produtoID < 0 || produtoID >= QTDPROD) return;

	prodRestoque[produtoID] += qnt;
}

int logMessageCompra::getProdutoComprado(int produtoID)
{
	if(produtoID < 0 || produtoID >= QTDPROD) return 0;

	return prodRestoque[produtoID];
}

QString logMessageCompra::getLogMessage()
{
	QString msg;

	msg = QString::fromAscii("Pedido de re-estoque feito para o seguinte item:\n");
	for(int i = 0; i < QTDPROD; i++)
	{
		if(prodRestoque[i] == 0) continue;
		msg += QString::fromAscii("\titem id = ") + QString::number(i) +
		       QString::fromAscii(" - quantidade = ") + QString::number(prodRestoque[i]) +
		       QString::fromAscii( ".\n");
	}

	msg += QString::fromAscii("\n");

	return msg;
}
