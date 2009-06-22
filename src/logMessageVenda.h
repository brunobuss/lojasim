#ifndef LOGMESSAGEVENDA_H
#define LOGMESSAGEVENDA_H

#include <globaldef.h>
#include <QString>

class logMessageVenda
{
public:
	logMessageVenda(int clientID, int vendedorID);   // Construtor: cadastra o cliente e seu vendedor
	void setProdutoVendido(int produtoID, int qnt);  // Cadastra a quantidade de produtos vendidos de um tipo
	int getProdutoVendido(int produtoID);            // Retorna a quantidade vendida de um produto
	int getVendedor();                               // Retorna o Vendedor
	QString getLogMessage();                         // Retorna uma string com todos os dados cadastrados
	
private:
	int cID;
	int vID;
	int prodVendidos[QTDPROD];
};


#endif
