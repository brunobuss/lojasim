#include<logMessage.h>

logMessage::logMessage()
{
}

logMessage::logMessage(QString str)
{
    msg = str;
}

QString logMessage::getMsg()
{
    return msg;
}

void logMessage::setMsg(QString str)
{
    msg = str;
}

int logMessage::returnMsgType()
{
    return LOGM_TYPE_GENERAL;
}