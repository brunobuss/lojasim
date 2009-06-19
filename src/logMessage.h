#ifndef LOGMESSAGE_H
#define LOGMESSAGE_H

#include <QString>
#include <globaldef.h>

class logMessage : public
{
    Q_OBJECT

public:
    logMessage();
    logMessage(QString str);
    QString getMsg();
    void setMsg(QString str);
    int returnMsgType();

private:
    QString msg;
};

#endif