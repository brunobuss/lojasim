#ifndef VENDATHREAD_H
#define VENDATHREAD_H

#include<QtCore>
#include<pedido.h>
#include<estoquista.h>
#include<logMessageCompra.h>

//Classe responsavel pela simulacao de re-estocagem
class pedidoThread : public QThread
{

	Q_OBJECT

public:
    pedidoThread(Pedido* pedidos, Estoquista *estoq);
    void run();

signals:
    //Sinal avisando que o pedido de re-estocagem foi finalizado
    void finalizouPedido(Estoquista *e);
    //Envia uma mensagem de log para o log do sistema.
    void registerLog(QString log);
    //Envia um mensagem de log de Compra para o log do sistema
    void registerLogCompra(logMessageCompra* lc);

private:
   
   QSharedMemory dsm; // Estoque int[QTDPROD]
   QSharedMemory rsm; // reprimidos int[QTDPROD]
   QSharedMemory qsm; // Total pedidos int[QTDPROD]
   QSharedMemory nsm; // Pessoas compraram int[QTDPRD]
   
   int* pD; //Acessa a Shared Memory dsm
   int* dR; //Acessa a Shared Memory rsm
   int* pT; //Acessa a Shared Memory qsm
   int* pN; //Acessa a Shared Memory nsm

   Pedido *p;
   Estoquista *e;

};

#endif
