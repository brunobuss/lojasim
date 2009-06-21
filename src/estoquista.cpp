#include <estoquista.h>

Estoquista::Estoquista()
{
}

int Estoquista::getID(void)const
{
	return id;
}

QString Estoquista::getName(void)const
{
	return name;
}

void Estoquista::setID(const int a)
{
	id = a;
}

void Estoquista::setName(const QString a)
{
	name = a;
}
