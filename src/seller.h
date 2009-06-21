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
    int getID(void)const;
    void setID(const int);
    int podeAtenderClientePref(void);
    void atendeuClientePreferencial();
    void atendeuCliente();
    int getTotalClientesAtendidos(void)const;

private:
    QString name;
    int id;
    int cntTotalClientes;
    int cntClientesPref;
};


#endif //SELLER_H
