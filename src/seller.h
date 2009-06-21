#ifndef SELLER_H
#define SELLER_H

#include <QtCore>
#include <globaldef.h>

class Seller
{
public:
    Seller();
    void setName(const QString);
    QString getName(void)const;

private:
    QString name;
};


#endif //SELLER_H
