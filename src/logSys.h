#ifndef LOGSYS_H
#define LOGSYS_H

#include <QtCore>

class logSys : public QThread
{
    Q_OBJECT

public:
    void run();
    void printReport();

public slots:
    void reciveLog(QString msg);    

private:
    QList<QString> qlog;
};



#endif
