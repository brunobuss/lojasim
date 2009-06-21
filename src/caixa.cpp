#include <caixa.h>

Caixa::Caixa()
{
}

int Caixa::getID(void)const
{
	return id;
}

QString Caixa::getName(void)const
{
	return name;
}

void Caixa::setID(const int a)
{
	id = a;
}

void Caixa::setName(const QString a)
{
	name = a;
}
