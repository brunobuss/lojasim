#ifndef LOGSYS_H
#define LOGSYS_H

#include <QThread>
#include <logMessage.h>

class logSys : public QThread
{
    Q_OBJECT

public:
    void run();
    void printReport();

public slot:
    void reciveLog(logMessage reg);

private:
    QList<logMessage> qlog;
};



#endif