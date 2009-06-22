#include <vendedor.h>

Vendedor::Vendedor()
{
	name = "";
	cntTotalClientes = 0;
  cntClientesPref = 3;
}

void Vendedor::setName(const QString n)
{
	name = n;
}

QString Vendedor::getName(void)const
{
	return name;
}

void Vendedor::setID(const int a)
{
	id = a;
}

int Vendedor::getID(void)const
{
	return id;
}

int Vendedor::podeAtenderClientePref(void)
{
	if(cntClientesPref > 0)
		return true;
	else
		return false;
}

void Vendedor::atendeuClientePreferencial()
{
   cntTotalClientes++;
   cntClientesPref--;
}
void Vendedor::atendeuCliente()
{
   cntTotalClientes++;
}

int Vendedor::getTotalClientesAtendidos(void)const
{
	return cntTotalClientes;
}
