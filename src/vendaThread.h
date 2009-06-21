#ifndef VENDATHREAD_H
#define VENDATHREAD_H

#include<QtCore>
#include<cliente.h>
#include<seller.h>

class vendaThread : public QThread
{

    Q_OBJECT

public:
    vendaThread(Cliente* cl, Seller* sl);
    void run();

signals:
    void finalizouVenda(Seller s);
    void finalizouVenda(Cliente c);
    void registerLog(QString log);

public slots:
    void realizaVenda();

private:
   Cliente* c;
   Seller* s;
};

#endif
