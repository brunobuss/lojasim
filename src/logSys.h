#ifndef LOGSYS_H
#define LOGSYS_H

#include <QtCore>
#include <logMessageCompra.h>
#include <logMessageVenda.h>

class logSys : public QThread
{
    Q_OBJECT

public:
    void run();

public slots:
    void receiveLog(QString msg);
    void receiveLogCompra(logMessageCompra* lc);
    void receiveLogVenda(logMessageVenda* lv);
    void geraRelatorioDiario();

private:
    QMutex gmut, cmut, vmut;

    QList<QString> log;
    QList<logMessageCompra> lCompra;
    QList<logMessageVenda> lVenda;

};



#endif
