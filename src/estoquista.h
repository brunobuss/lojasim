#ifndef ESTOQUISTA_H
#define ESTOQUISTA_H

#include <QString>
#include <globaldef.h>


const static QString estoquistaNames[MAXESTOQUISTANAMES] = { "Gabriel" , "Maria", "Antonio"};

class Estoquista
{
	int id;
	QString nome;

public:
	Estoquista();

	int getID(void)const;
	QString getName(void)const;
	void setID(const int);
	void setName(const QString);
	
};

#endif //ESTOQUISTA_H
