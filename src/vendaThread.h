#ifndef VENDATHREAD_H
#define VENDATHREAD_H

#include<QtCore>
#include<cliente.h>
#include<vendedor.h>
#include<pedido.h>
#include<logMessageVenda.h>
#include<globaldef.h>

//Thread responsavel pro simular a operacao de venda
class vendaThread : public QThread
{
    Q_OBJECT

public:
    vendaThread(Cliente *cl, Vendedor *sl);
    void run();

signals:
    //Sinais indicando que a venda foi finalizada
    void finalizouVenda(Vendedor *s);
    void finalizouVenda(Cliente *c);

    //Sinal para pedido de reposicao
    void fazPedidoReposicao(Pedido* p);

    //Sinais para envio de mensagens de log ao sistema de log.
    void registerLog(QString log);
    void registerLogVenda(logMessageVenda* lm);

private:
   QSharedMemory dsm; // Estoque int[QTDPROD]
   QSharedMemory rsm; // reprimidos int[QTDPROD]
   QSharedMemory qsm; // Total pedidos int[QTDPROD]
   QSharedMemory nsm; // Pessoas compraram int[QTDPRD]
   
   int* pD; //Acesso ao dsm
   int* dR; //Acesso ao rsm
   int* pT; //Acesso ao qsm
   int* pN; //Acesso ao nsm

   Cliente* c;
   Vendedor* s;
};

#endif
