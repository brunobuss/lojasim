#include <seller.h>

Seller::Seller()
{
	name = "";
}

void Seller::setName(const QString n)
{
	name = n;
}

QString Seller::getName(void)const
{
	return name;
}
