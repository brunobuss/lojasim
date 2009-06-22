#ifndef LOGMESSAGECOMPRA_H
#define LOGMESSAGECOMPRA_H

#include <globaldef.h>
#include <QString>

class logMessageCompra
{
public:
	logMessageCompra();
	void setProdutoComprado(int produtoID, int qnt);  // Cadastra a quantidade comprada de um produto
	int getProdutoComprado(int produtoID);            // Retorna a quantidade e o produtos cadastrados
	QString getLogMessage();                          // Retorna uma string com os dados cadastrados
	
private:
	int cID;
	int vID;
	int prodRestoque[QTDPROD];
};


#endif
