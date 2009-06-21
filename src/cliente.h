#include <QtCore>
#include <clientsNames.h>
#include <globaldef.h>

class Cliente : public QObject {

	Q_OBJECT
	
  QString nome;
  QString sobrenome;
  QString nomeCompleto;
  int idProdDesejado[QTDPROD]; //Vetor de produtos desejados possui entre 5 e 15 posicoes
  int qtdProdDesejados[QTDPROD];
  int idVendedorPreferido;
  int numProdutos;
  bool desejaVendedor;
  bool compraMenos;

 public:
 
 Cliente();
 
 bool getDesejaVendedor(void)const;
 bool getCompraMenos(void)const;
 int getNumProdutos(void)const;
 int getProduto(const int)const;
 int getQtdProduto(const int)const;
     
};

