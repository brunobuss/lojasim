#ifndef LOJASIM_H
#define LOJASIM_H

#include <QtCore>

#include <logSys.h>
#include <vendaDispatcher.h>
#include <pagamentoDispatcher.h>
#include <pedidoDispatcher.h>
#include <logMessageCompra.h>
#include <logMessageVenda.h>
#include <geradorCliente.h>

class lojaSim: public QObject
{

	Q_OBJECT
public:
	lojaSim(int argc, char* argv[]);

public slots:
	void executaSimulador();

private:
	QSharedMemory dsm;
	QSharedMemory rsm;
};


#endif
