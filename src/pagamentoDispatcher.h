#ifndef PAGAMENTODISPATCHER_H
#define PAGAMENTODISPATCHER_H

#include <QThread>

//Thread que faz o match de um cliente com um caixa disponivel e dispara a thread de pagamento.
class pagamentoDispatcher : public QThread
{
    Q_OBJECT

public:
    void run();

signals:
    void chegouCliente(cliente c, QTime tempo);
    void chegouCaixa(caixa c, QTime tempo);
    void iniciouPagamento(caixa cx, cliente c, QTime tempo);

public slot:
    void adicionaCliente(cliente c);
    void retornaCaixa(caixa c);

private:
    QList<vendedor> lV; //Lista dos caixas livres
    QList<caixa> lC; //Lista dos clientes esperando para efetuarem o pagamento de seus produtos.
};

#endif