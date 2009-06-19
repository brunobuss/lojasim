#ifndef PEDIDODISPATCHER_H
#define PEDIDODISPATCHER_H

#include <QThread>

//Thread que faz o match dos pedidos pendentes e os estoquistas e dispara a thread de re-estoque
class pedidoDispatcher : public QThread
{
    Q_OBJECT

public:
    void run();

signals:
    void chegouPedido(pedido p, QTime tempo);
    void chegouEstoquista(estoquista e, QTime tempo);
    void iniciouReestoque(estoquista e, pedido p, QTime tempo);

public slot:
    void adicionaPedido(pedido p);
    void retornaEstoquista(estoquista e);

private:
    QList<pedido> lP; //Lista dos pedidos de re-estoque pendentes.
    QList<estoquista> lE; //Lista dos estoquistas livres.
};

#endif