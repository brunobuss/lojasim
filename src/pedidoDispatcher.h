#ifndef PEDIDODISPATCHER_H
#define PEDIDODISPATCHER_H

#include <QtCore>
#include <pedido.h>
#include <estoquista.h>
#include <logMessageCompra.h>
#include <pedidoThread.h>

//Thread que delega pedidos pendentes a estoquistas livres 
//e dispara a thread de re-estoque.
class pedidoDispatcher : public QThread
{
    Q_OBJECT

public:
    pedidoDispatcher();
    void run();

signals:
    //Registra a mensagem 'log' no log do sistema/output.
    void registerLog(QString str);
    //Registra um log de Compra de produtos.
    void registerLogCompra(logMessageCompra* lc);

public slots:
    //Metodo para tratar a chegada de um novo pedido de re-estoque
    void adicionaPedido(Pedido *p);
    //Metodo para tratar quando um estoquista fica livre novamente
    void retornaEstoquista(Estoquista *e);

private:
    //Semaforo de exclusao mutua para controle de acesso as listas
    QMutex mutex;

    int lP[QTDPROD]; //Lista dos pedidos de re-estoque pendentes.
    QList<Estoquista*> lE; //Lista dos estoquistas livres.

    //Dispara thread para reposicao de estoque
    void iniciaThreadReposicao(Pedido *p, Estoquista *e);
};

#endif
