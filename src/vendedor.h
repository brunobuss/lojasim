#ifndef VENDEDOR_H
#define VENDEDOR_H

#include <QtCore>
#include <globaldef.h>

//Classe que representa um vendedor no sistema
class Vendedor
{
public:
    Vendedor();
    void setName(const QString); //Define nome
    QString getName(void)const; //Retorna nome
    int getID(void)const;
    void setID(const int);
    //Indica se ele ainda pode atender algum cliente preferencial
    int podeAtenderClientePref(void);

    //Metodos que trabalham sobre a contagem de clientes atendidos
    void atendeuClientePreferencial();
    void atendeuCliente();
    int getTotalClientesAtendidos(void)const;

private:
    QString name;
    int id;
    int cntTotalClientes;//Clientes atendidos
    int cntClientesPref;//Quantos clientes preferenciais ainda pode antender
};


#endif //VENDEDOR_H
