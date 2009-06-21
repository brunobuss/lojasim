#ifndef VENDATHREAD_H
#define VENDATHREAD_H

class vendaThread : public
{

public:
    vendaThread(Client c, Seller s);
    void run();


signals:
    void finalizouVenda(Seller s);
    void finalizouVenda(Client c);

public slots:
    void realizaVenda();
};



#endif
