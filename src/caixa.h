#ifndef CAIXA_H
#define CAIXA_H

#include <QString>
#include <globaldef.h>


const static QString caixaNames[MAXCAIXANAMES] = { "Mauro" , "Luisa"};


class Caixa
{
	int id; // identificador do Caixa
	QString name; // Nome do Caixa

public:
	Caixa(); // Construtor

	int getID(void)const;         // retorna o identificador
	QString getName(void)const;   // retorna o nome do Caixa
	void setID(const int);        // configura um identificador
	void setName(const QString);  // configura um nome
	
};

#endif //CAIXA_H
