#include <geradorCliente.h>

geradorCliente::geradorCliente()
{
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(controlaTempo()));
	timer->start(UNIDTEMPO);

	dia = new QTimer(this);
	connect(dia, SIGNAL(timeout()), this, SLOT(geraRelatorio()));
	dia->start(DIA);

	qsrand(time(NULL));
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

	cl = new Cliente(i++, qrand());
	emit geraCliente(cl);

	timer->setInterval(UNIDTEMPO*(qrand()%MAXTIME));
}

void geradorCliente::geraRelatorio(void)
{
	emit geraRelatorioDiario();
}
