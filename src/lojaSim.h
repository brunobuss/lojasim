#ifndef LOJASIM_H
#define LOJASIM_H

#include <QtCore>

#include <logSys.h>
#include <vendaDispatcher.h>
#include <pagamentoDispatcher.h>
#include <pedidoDispatcher.h>
#include <logMessageCompra.h>
#include <logMessageVenda.h>


class lojaSim: public QObject
{

	Q_OBJECT

public:
	void executaSimulador(int argc, char* argv[]);
};


#endif
