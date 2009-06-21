#ifndef RELATORIO_H
#define RELATORIO_H

#include <QThread>
#include <cliente.h>
#include <pedido.h>

class relatorio : public QThread
{

Q_OBJECT

public:
    relatorio();
    void run();

public slots:
    void vendaConcluida(Cliente c);
    void pedidoAtendido(Pedido p);

private:
    QList<Cliente> cL; //lista dos clientes atendidos
    QList<Pedido> pL; //lista dos pedidos de reestoque atendidos
};


#endif
