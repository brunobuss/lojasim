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
	lojaSim(int argc, char* argv[]);   // main

public slots:
	void executaSimulador();           // inicia a execucao do simulador

private:
	QSharedMemory dsm;
	QSharedMemory rsm;
	QSharedMemory qsm;
	QSharedMemory nsm;
};


#endif
