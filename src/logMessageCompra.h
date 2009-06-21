#ifndef LOGMESSAGECOMPRA_H
#define LOGMESSAGECOMPRA_H

#include <globaldef.h>
#include <QString>

class logMessageCompra
{
public:
	logMessageCompra();
	void setProdutoComprado(int produtoID, int qnt);
	int getProdutoComprado(int produtoID);
	QString getLogMessage();
	
private:
	int cID;
	int vID;
	int prodRestoque[QTDPROD];
};


#endif
