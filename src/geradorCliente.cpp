#include <geradorCliente.h>

geradorCliente::geradorCliente()
{
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(geradorClientes()));
	timer->start(UNIDTEMPO);

	dia = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(geraRelatorio()));
	dia->start(DIA);
}

geradorCliente::~geradorCliente()
{
	delete timer;
	delete dia;
}

void geradorCliente::run()
{
	exec();	
}
void geradorCliente::controlaTempo(void)
{
	static int i = 0;

	Cliente *cl;

	cl = new Cliente(i++);
	emit geraCliente(*cl);
	delete cl;

	timer->setInterval(UNIDTEMPO*(qrand()%MAXTIME));
}

void geradorCliente::geraRelatorio(void)
{
	emit geraRelatorioDiario();
}
