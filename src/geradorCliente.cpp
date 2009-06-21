#include <geradorClientes.h>

geradorClientes::geradorClientes()
{}

void geradorClientes::run()
{
	int i = 0;
	Cliente *cl;

	while(true)
	{
		cl = new Cliente(i++);
		emit geraCliente(*cl);
		delete cl;
		msleep(qrand()%(MAXTIME-1) + 1);
	}
}
