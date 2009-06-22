#ifndef VENDATHREAD_H
#define VENDATHREAD_H

#include<QtCore>
#include<cliente.h>
#include<seller.h>
#include<pedido.h>
#include<logMessageVenda.h>
#include<globaldef.h>

class vendaThread : public QThread
{

    Q_OBJECT

public:
    vendaThread(Cliente *cl, Seller *sl);
    void run();

signals:
    void finalizouVenda(Seller *s);
    void finalizouVenda(Cliente *c);
    void fazPedidoReposicao(Pedido* p);
    void registerLog(QString log);
    void registerLogVenda(logMessageVenda* lm);

private:
   QSharedMemory dsm;
   QSharedMemory rsm;
   QSharedMemory qsm;
   QSharedMemory nsm;
   
   int* pD;
   int* dR;
   int* pT;
   int* pN;

   Cliente* c;
   Seller* s;
};

#endif
