#ifndef GERADORCLIENTE_H
#define GERADORCLIENTE_H

#include <QtCore>
#include <globaldef.h>
#include <Cliente.h>

class geradorCliente : public QThread
{
	Q_OBJECT
	
public:
	geradorCliente();
	run();

signals:
	void geraCliente(Cliente c);

};

#endif
