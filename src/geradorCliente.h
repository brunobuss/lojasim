#ifndef GERADORCLIENTE_H
#define GERADORCLIENTE_H

#include <QtCore>
#include <globaldef.h>
#include <cliente.h>

class geradorCliente : public QThread
{
	Q_OBJECT
	
public:
	geradorCliente();
	~geradorCliente();
	void run();

signals:
	void geraCliente(Cliente &c);
	void geraRelatorioDiario(void);

public slots:
       void controlaTempo(void);
	void geraRelatorio(void);

private:
	QTimer *timer;
	QTimer *dia;

};

#endif
