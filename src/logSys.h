#ifndef LOGSYS_H
#define LOGSYS_H

#include <QtCore>
#include <logMessageCompra.h>
#include <logMessageVenda.h>

class logSys : public QThread
{
    Q_OBJECT

public:
    logSys();
    void run();

public slots:
    void receiveLog(QString msg);
    void receiveLogCompra(logMessageCompra* lc);
    void receiveLogVenda(logMessageVenda* lv);
    void geraRelatorioDiario();

private:
    QMutex gmut, cmut, vmut;

    int dia;

    QList<QString> log;
    QList<logMessageCompra> lCompra;
    QList<logMessageVenda> lVenda;

};



#endif
