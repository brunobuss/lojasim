/*
INSTRUCOES DO TRABALHO
######################

5 � Loja de Departamentos

Desenvolva um aplicativo com a finalidade de controlar a opera��o de uma loja de material
esportivo que trabalha com 10 vendedores de balc�o e tr�s compradores para reposi��o do
estoque. As regras de neg�cio s�o as seguintes:

a)  A loja comercializa 15 itens distintos e o estoque inicial de cada item deve ser inici-
ado de forma aleat�ria variando entre 20 e 30 unidades cada.
b)  A informa��o do estoque � mantida com apenas tr�s campos � o c�digo do produto,
a quantidade em estoque e a demanda reprimida (pedidos n�o atendidos por falta em
estoque).
c)  Os vendedores formam uma fila circular para cada cliente que der entrada na loja.
d)  Cada vendedor pode atender at� 3 clientes sem respeitar a fila circular, ou seja, a-
tender cliente exclusivo que chegue � loja e solicite seu atendimento de forma expl�-
cita;
e)  A chegada de clientes deve ser simulada segundo um crit�rio aleat�rio de espa�o de
tempo entre um e outro variando de 1 a 5 unidades de tempo.
f)  Cada cliente que chega deseja fazer uma ou mais compras de produtos escolhidos
aleatoriamente e em quantidades tamb�m aleat�rias variando de 5 a 15 unidades.
g)  A venda s� pode ser realizada se houver itens em estoque. Caso o estoque existente
seja insuficiente, o campo demanda reprimida deve ser atualizado e o cliente n�o �
atendido naquela venda espec�fica.
h)  Quando uma venda n�o puder ser realizada por falta de estoque o vendedor deve a-
brir um pedido de compra contendo o c�digo do produto a ser adquirido.
i)  Quando a venda tornar o estoque abaixo do ponto de ressuprimento (3 unidades), o
sistema deve providenciar o pedido de reposi��o automaticamente.
j)  A compra � feita pelo comprador da vez de forma a atender a demanda reprimida
somada de uma quantidade aleat�ria entre 20 e 50% acima da demanda.
k)  Um registro deve ser gerado para conter o hist�rico cronol�gico das opera��es de
venda e de compra realizadas durante a opera��o.

A aplica��o deve terminar quando a loja encerrar as atividades, isto �, quando os compradores
terminarem suas opera��es de compra, todos os vendedores conclu�rem seus atendimentos e ne-
nhum novo comprador surgir dentro de um intervalo de tempo determinado.

*/

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

