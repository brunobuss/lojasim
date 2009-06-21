#ifndef PEDIDODISPATCHER_H
#define PEDIDODISPATCHER_H

#include <QThread>

//Thread que faz o match dos pedidos pendentes e os estoquistas e dispara a thread de re-estoque
class pedidoDispatcher : public QThread
{
    Q_OBJECT

public:
    pedidoDispatcher(relatorio* relatorio);
    void run();

signals:
    void registerLog(QString str);

public slot:
    void adicionaPedido(pedido p);
    void retornaEstoquista(estoquista e);

private:
    QMutex mutex;
    relatorio* rlt;

    QList<pedido> lP; //Lista dos pedidos de re-estoque pendentes.
    QList<estoquista> lE; //Lista dos estoquistas livres.

    void iniciaThreadReposicao(QList<pedido> lP, estoquista p);
};

#endif
