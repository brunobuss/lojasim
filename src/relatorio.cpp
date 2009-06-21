#include <relatorio.h>

relatorio::relatorio()
{
	cL.clear();
	pL.clear();

}

void relatorio::run()
{
    exec();
}

void relatorio::vendaConcluida(Cliente c)
{
	mutex.lock();
	cL.append(c);
	mutex.unlock();
}

void relatorio::pedidoAtendido(Pedido p)
{
	mutex.lock();
	pL.append(p);
	mutex.unlock();
}
