#ifndef VENDATHREAD_H
#define VENDATHREAD_H

#include<QtCore>
#include<pedido.h>
#include<estoquista.h>
#include<logMessageCompra.h>

class pedidoThread : public QThread
{

	Q_OBJECT

public:
    pedidoThread(Pedido* pedidos, Estoquista *estoq);
    void run();

signals:
    void finalizouPedido(Estoquista *e);
    void registerLog(QString log);
    void registerLogCompra(logMessageCompra* lc);

private:
   
   QSharedMemory dsm; // Estoque int[QTDPROD]
   QSharedMemory rsm; // reprimidos int[QTDPROD]
   QSharedMemory qsm; // Total pedidos int[QTDPROD]
   QSharedMemory nsm; // Pessoas compraram int[QTDPRD]
   
   int* pD;
   int* dR;
   int* pT;
   int* pN;

   Pedido *p;
   Estoquista *e;

};

#endif
