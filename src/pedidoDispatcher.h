#ifndef PEDIDODISPATCHER_H
#define PEDIDODISPATCHER_H

#include <QThread>
#include <pedido.h>
#include <estoquista.h>


//Thread que faz o match dos pedidos pendentes e os estoquistas e dispara a thread de re-estoque
class pedidoDispatcher : public QThread
{
    Q_OBJECT

public:
    pedidoDispatcher();
    void run();

signals:
    void registerLog(QString str);

public slots:
    void adicionaPedido(Pedido p);
    void retornaEstoquista(Estoquista e);

private:
    QMutex mutex;

    QList<Pedido> lP; //Lista dos pedidos de re-estoque pendentes.
    QList<Estoquista> lE; //Lista dos estoquistas livres.

    void iniciaThreadReposicao(QList<Pedido> lP, Estoquista p);
};

#endif
