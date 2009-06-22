#ifndef CLIENTE_H
#define CLIENTE_H

#include <QtCore>
#include <clientsNames.h>
#include <globaldef.h>

class Cliente
{
public:
    Cliente(const int, unsigned int);  // Construtor
 
    bool getCompraMenos(void)const;    // Retorna a escolha entre comprar menos ou nao
    int getNumProdutos(void)const;     // Retorna o numero produtos
    int getProduto(const int)const;    // retorna o i-esimo produto
    int getQtdProduto(const int)const; // retorna a quantidade do i-esimo produto
    QString getNomeID(void)const;      // retorna uma string com o nome e o id juntos
    int getID(void)const;              // retorna o identificar
    int getVendedorPref(void)const;    // retorna o vendedor preferencial caso tenha um

private:
    int id;                           
    QString nome;
    QString sobrenome;
    QString nomeCompleto;
    int idProdDesejado[QTDPROD];       // Vetor de produtos desejados possui entre 5 e 15 posicoes
    int qtdProdDesejados[QTDPROD];     // Quantidade dos produtos desejados
    int idVendedorPreferido;           
    int numProdutos;
    bool desejaVendedor;               // indica se possui um vendedor preferencial
    bool compraMenos;  
};

#endif //CLIENTE_H
