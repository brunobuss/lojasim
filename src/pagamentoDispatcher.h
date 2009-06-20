#ifndef PAGAMENTODISPATCHER_H
#define PAGAMENTODISPATCHER_H

#include <QThread>

//Thread que faz o match de um cliente com um caixa disponivel e dispara a thread de pagamento.
class pagamentoDispatcher : public QThread
{
    Q_OBJECT

public:
    pagamentoDispatcher(relatorio* relatorio);
    void run();

signals:
    void registerLog(QString str);

public slot:
    void adicionaCliente(cliente c);
    void retornaCaixa(caixa c);

private:
    QMutex mutex;
    relatorio* rlt;

    QList<cliente> lC; //Lista dos clientes esperando para efetuarem o pagamento de seus produtos.
    QList<caixa> lCL; //Lista dos caixas livres
    
    void iniciaThreadPagamento(cliente c, caixa cx);
};

#endif