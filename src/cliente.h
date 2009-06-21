#ifndef CLIENTE_H
#define CLIENTE_H

#include <QtCore>
#include <clientsNames.h>
#include <globaldef.h>

class Cliente
{
public:
    Cliente(const int, unsigned int);
 
    bool getCompraMenos(void)const;
    int getNumProdutos(void)const;
    int getProduto(const int)const;
    int getQtdProduto(const int)const;
    QString getNomeID(void)const;
    int getID(void)const;
    int getVendedorPref(void)const;

private:
    int id;
    QString nome;
    QString sobrenome;
    QString nomeCompleto;
    int idProdDesejado[QTDPROD]; //Vetor de produtos desejados possui entre 5 e 15 posicoes
    int qtdProdDesejados[QTDPROD];
    int idVendedorPreferido;
    int numProdutos;
    bool desejaVendedor;
    bool compraMenos; 
};

#endif //CLIENTE_H
