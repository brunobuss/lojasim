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

//Thread que faz delega um vendedor para atender um cliente
//e dispara uma thread de venda
class vendaDispatcher : public QThread
{
    Q_OBJECT

public:
    vendaDispatcher();
    void run();

public slots:
    //Metodo responsavel por tratar a chegada de um novo cliente na loja
    void adicionaCliente(Cliente *c);
    //Metodo responsavel por tratar a volta de um vendedor que estava
    //ocupado
    void retornaVendedor(Seller *v);
	
signals:
    //Registra uma mensagem de log no sistema.
    void registerLog(QString str);
    //Registra uma mensagem de log de Venda no sistema.
    void registerLogVenda(logMessageVenda* lm);
    //Envia o cliente para a fila dos caixas.
    void passaClienteParaCaixa(Cliente* c);
    //Envia pedido de re-estoque para os estoquistas
    void passaPedidoParaEstoque(Pedido* p);

private:
    //Semaforo de exlcusao mutua, para controle de acesso as listas.
    QMutex mutex;
    
    QList<Seller*> lV; //Lista dos vendedores disponíveis.
    QList<Cliente*> lC; //Lista dos clientes esperando para serem atendidos.

    //Verifica de algum cliente da fila de espera tem o vendedor v como vendedor preferencial.
    int verificaVendedorPreferencial(Seller *v);

    //Prepara e dispara a thread de venda
    void iniciaThreadVenda(Cliente *c, Seller *v);
};

#endif
