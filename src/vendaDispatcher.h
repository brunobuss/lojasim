#ifndef VENDADISPATCHER_H
#define VENDADISPATCHER_H

#include <QThread>
#include <globaldef.h>

//Thread que faz o match de um cliente com um vendedor e dispara uma thread de venda
class vendaDispatcher : public QThread
{
    Q_OBJECT

public:
    vendaDispatcher();
    void run();

signals:
    void registerLog(QString str);

public slot:
    void adicionaCliente(cliente c);
    void retornaVendedor(vendedor v);

private:
    QMutex mutex;
    
    QList<vendedor> lV; //Lista dos vendedores disponíveis.
    QList<cliente> lC; //Lista dos clientes esperando para serem atendidos.

    //Verifica de algum cliente da fila de espera tem o vendedor v como vendedor preferencial.
    int verificaVendedorPreferencial(vendedor v);
    void iniciaThreadVenda(cliente c, vendedor v);
};


#endif
