#ifndef VENDADISPATCHER_H
#define VENDADISPATCHER_H

#include <QThread>

//Thread que faz o match de um cliente com um vendedor e dispara uma thread de venda
class vendaDispatcher : public QThread
{
    Q_OBJECT

public:
    void run();

signals:
    void chegouCliente(cliente c, QTime tempo);
    void chegouVendedor(vendedor v, QTime tempo);
    void iniciouVenda(vendedor v, cliente c, QTime tempo);

public slot:
    void adicionaCliente(cliente c);
    void retornaVendedor(vendedor v);

private:
    QList<vendedor> lV; //Lista dos vendedores disponíveis.
    QList<cliente> lC; //Lista dos clientes esperando para serem atendidos.

    //Verifica de algum cliente da fila de espera tem o vendedor v como vendedor preferencial.
    int verificaVendedorPreferencial(vendedor v);
};


#endif