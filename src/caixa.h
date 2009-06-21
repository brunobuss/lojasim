#ifndef CAIXA_H
#define CAIXA_H

#include <QString>
#include <globaldef.h>


const static QString caixaNames[MAXCAIXANAMES] = { "Mauro" , "Luisa"};


class Caixa
{
	int id;
	QString name;

public:
	Caixa();

	int getID(void)const;
	QString getName(void)const;
	void setID(const int);
	void setName(const QString);
	
};

#endif //CAIXA_H
