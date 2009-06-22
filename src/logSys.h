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
    void receiveLog(QString msg);                 // Recebe as mensagens generica que vao para o log
    void receiveLogCompra(logMessageCompra* lc);  // Recebe as mensagens de compra que vao para o log
    void receiveLogVenda(logMessageVenda* lv);    // Recebe as mensagens de Venda que vao para o log
    void geraRelatorioDiario();                   // Recebe um sinal para processar um relatorio diario

private:
    QMutex gmut, cmut, vmut;

    int dia;

    QList<QString> log;
    QList<logMessageCompra> lCompra;
    QList<logMessageVenda> lVenda;

};



#endif
