#include <pedido.h>

Pedido::Pedido()
{
	id = 0;
}

int Pedido::getID(void)const
{
	return id;
}

void Pedido::setID(const int a)
{
	id = a;
}

