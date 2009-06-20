#include <logSys.h>

void logSys::run()
{
    exec();
}

void logSys::printReport()
{
    /*Faz print no console do relatório atual*/
}

void logSys::reciveLog(QString msg)
{
    qlog.append(msg);   
}