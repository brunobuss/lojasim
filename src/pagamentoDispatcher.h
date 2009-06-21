#ifndef PAGAMENTODISPATCHER_H
#define PAGAMENTODISPATCHER_H

#include <QtCore>
#include <globaldef.h>
#include <cliente.h>
#include <caixa.h>

//Thread que faz o match de um cliente com um caixa disponivel e dispara a thread de pagamento.
class pagamentoDispatcher: public QThread
{
    Q_OBJECT

public:
    pagamentoDispatcher();

protected:
    void run();

signals:
    void registerLog(QString str);

public slots:
    void adicionaCliente(Cliente *c);
    void retornaCaixa(Caixa *c);

private:
	void iniciaThreadPagamento(Cliente *c, Caixa *cx);
	
	QMutex mutex;
    QList<Cliente*> lC; //Lista dos clientes esperando para efetuarem o pagamento de seus produtos.
    QList<Caixa*> lCL; //Lista dos caixas livres 
    
	
};

#endif //PAGAMENTODISPATCHER_H
