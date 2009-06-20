#ifndef LOGSYS_H
#define LOGSYS_H

#include <QThread>

class logSys : public QThread
{
    Q_OBJECT

public:
    void run();
    void printReport();

public slot:
    void reciveLog(QString msg);    

private:
    QList<QString> qlog;
};



#endif