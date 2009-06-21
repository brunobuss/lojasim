#ifndef VENDADISPATCHER_H
#define VENDADISPATCHER_H

#include <QtCore>
#include <globaldef.h>
#include <cliente.h>
#include <seller.h>
#include <pedido.h>
#include <sellerNames.h>
#include <logMessageVenda.h>
#include <vendaThread.h>

//Thread que faz o match de um cliente com um vendedor e dispara uma thread de venda
class vendaDispatcher : public QThread
{
    Q_OBJECT

public:
    vendaDispatcher();
    void run();

public slots:
    void adicionaCliente(Cliente *c);
    void retornaVendedor(Seller *v);
	
signals:
    void registerLog(QString str);
    void registerLogVenda(logMessageVenda* lm);
    void passaClienteParaCaixa(Cliente* c);
    void passaPedidoParaEstoque(Pedido* p);

private:
    QMutex mutex;
    
    QList<Seller*> lV; //Lista dos vendedores disponíveis.
    QList<Cliente*> lC; //Lista dos clientes esperando para serem atendidos.

    //Verifica de algum cliente da fila de espera tem o vendedor v como vendedor preferencial.
    int verificaVendedorPreferencial(Seller *v);
    void iniciaThreadVenda(Cliente *c, Seller *v);
};
#endif
