#ifndef LOGMESSAGEVENDA_H
#define LOGMESSAGEVENDA_H

#include <globaldef.h>
#include <QString>

class logMessageVenda
{
public:
	logMessageVenda(int clientID, int vendedorID);
	void setProdutoVendido(int produtoID, int qnt);
	int getProdutoVendido(int produtoID);
	QString getLogMessage();
	
private:
	int cID;
	int vID;
	int prodVendidos[QTDPROD];
};


#endif
