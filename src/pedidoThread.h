#ifndef VENDATHREAD_H
#define VENDATHREAD_H

#include<QtCore>
#include<pedido.h>
#include<estoquista.h>

class pedidoThread : public QThread
{

	Q_OBJECT

public:
    pedidoThread(QList<Pedido> pedidos, Estoquista estoq);
    void run();

signals:
    void finalizouPedido(Estoquista e);
    void registerLog(QString log);

public slots:
    void realizaPedido();

private:
   QList<Pedido> lP;
   Estoquista e;

};

#endif
