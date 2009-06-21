#ifndef VENDATHREAD_H
#define VENDATHREAD_H

#include <QtCore>
#include <cliente.h>
#include <caixa.h>

class pagamentoThread : public QThread
{

public:
    pagamentoThread(Client cl, Caixa caixa);
    void run();

signals:
    void finalizouPagamento(Caixa cx);
    void finalizouPagamento(Client c);
    void registerLog(QString log);

public slots:
    void realizaPagamento();

private:
   Cliente c;
   Caixa cx;
};

#endif
