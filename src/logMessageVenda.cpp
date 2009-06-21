#include <logMessageVenda.h>

logMessageVenda::logMessageVenda(int clientID, int vendedorID)
{
	for(int i = 0; i < QTDPROD; i++) prodVendidos[i] = 0;
	cID = clientID;
	vID = vendedorID;
}

void logMessageVenda::setProdutoVendido(int produtoID, int qnt)
{
	if(produtoID < 0 || produtoID >= QTDPROD) return;

	prodVendidos[produtoID] += qnt;

}

int logMessageVenda::getProdutoVendido(int produtoID)
{
	if(produtoID < 0 || produtoID >= QTDPROD) return 0;

	return prodVendidos[produtoID];
}

QString logMessageVenda::getLogMessage()
{
	QString msg;

	msg = QString::fromAscii("Venda realizada pelo vendedor ") + QString::number(vID) +
	      QString::fromAscii(" para o cliente ") + QString::number(cID) +
	      QString::fromAscii(":\n");

	for(int i = 0; i < QTDPROD; i++)
	{
		if(prodVendidos[i] == 0) continue;
		msg += QString::fromAscii("\titem id = ") + QString::number(i) +
		       QString::fromAscii(" - quantidade = ") + QString::number(prodVendidos[i]) +
		       QString::fromAscii(".\n");
	}

	msg += QString::fromAscii("\n");

	return msg;
}
