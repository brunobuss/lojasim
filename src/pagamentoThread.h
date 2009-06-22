#ifndef VENDATHREAD_H
#define VENDATHREAD_H

#include <QtCore>
#include <cliente.h>
#include <caixa.h>

class pagamentoThread : public QThread
{

	Q_OBJECT

public:
    pagamentoThread(Cliente* cl, Caixa* caixa);
    void run();

signals:
    void finalizouPagamento(Caixa *cx);
    void registerLog(QString log);

private:
   Cliente* c;
   Caixa* cx;
};

#endif
