#ifndef RELATORIO_H
#define RELATORIO_H

#include <QtCore>

class relatorio : public QThread
{

Q_OBJECT

public:
    relatorio();
    void run();

public slots:
    void vendaConcluida(cliente c);
    void pedidoAtendido(pedido p);

private:
    QList<cliente> cL; //lista dos clientes atendidos
    QList<pedidos> pL; //lista dos pedidos de reestoque atendidos
};


#endif