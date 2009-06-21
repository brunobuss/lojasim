#include <seller.h>

Seller::Seller()
{
	name = "";
	cntTotalClientes = 0;
  cntClientesPref = 3;
}

void Seller::setName(const QString n)
{
	name = n;
}

QString Seller::getName(void)const
{
	return name;
}

void Seller::setID(const int a)
{
	id = a;
}

int Seller::getID(void)const
{
	return id;
}

int Seller::podeAtenderClientePref(void)
{
	if(cntClientesPref > 0)
		return true;
	else
		return false;
}

void Seller::atendeuClientePreferencial()
{
   cntTotalClientes++;
   cntClientesPref--;
}
void Seller::atendeuCliente()
{
   cntTotalClientes++;
}

int Seller::getTotalClientesAtendidos(void)const
{
	return cntTotalClientes;
}
