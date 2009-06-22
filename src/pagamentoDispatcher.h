#ifndef PAGAMENTODISPATCHER_H
#define PAGAMENTODISPATCHER_H

#include <QtCore>
#include <globaldef.h>
#include <cliente.h>
#include <caixa.h>
#include <pagamentoThread.h>

//Thread que faz o match de um cliente com um caixa disponivel e dispara a thread de pagamento.
class pagamentoDispatcher: public QThread
{
    Q_OBJECT

public:
    pagamentoDispatcher();

protected:
    void run();

signals:
    void registerLog(QString str);       // Envia uma mesagem de log

public slots:
    void adicionaCliente(Cliente *c);    // Recebe um cliente para pagamento
    void retornaCaixa(Caixa *c);         // Recebe um caixa liberado

private:
    void iniciaThreadPagamento(Cliente *c, Caixa *cx);  // Dispara uma thread para processar um pagamento
	
    QMutex mutex;
    QList<Cliente*> lC; //Lista dos clientes esperando para efetuarem o pagamento de seus produtos.
    QList<Caixa*> lCL; //Lista dos caixas livres 
    
	
};

#endif //PAGAMENTODISPATCHER_H
