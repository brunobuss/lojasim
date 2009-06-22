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
	void geraCliente(Cliente *c);       // Sinal que se conecta a fila de clientes de vendaDispatcher
	void geraRelatorioDiario(void);     // Sinal que se conecta a gerador de relatorio disparado diariamente

public slots:
       void controlaTempo(void);            // controla o tempo de chegadas de clientes
	void geraRelatorio(void);           // controla o tempo de geracao de relatorios diarios

private:
	QTimer *timer;
	QTimer *dia;

};

#endif
