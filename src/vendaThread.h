#ifndef VENDATHREAD_H
#define VENDATHREAD_H

#include<QtCore>
#include<cliente.h>
#include<seller.h>

class vendaThread : public QThread
{

public:
    vendaThread(Client c, Seller s);
    void run();

signals:
    void finalizouVenda(Seller s);
    void finalizouVenda(Client c);
    void registerLog(QString log);

public slots:
    void realizaVenda();

private:
   Cliente c;
   Seller s;
};

#endif
