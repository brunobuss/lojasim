#ifndef ESTOQUISTA_H
#define ESTOQUISTA_H

#include <QString>
#include <globaldef.h>


const static QString estoquistaNames[MAXESTOQUISTANAMES] = { "Gabriel" , "Maria", "Antonio"};

class Estoquista
{
	int id;
	QString name;

public:
	Estoquista();

	int getID(void)const;         // Retorna o identificador
	QString getName(void)const;   // Retorna o nome do Estoquista
	void setID(const int);        // Configura um ID
	void setName(const QString);  // Configura um nome
	
};

#endif //ESTOQUISTA_H
