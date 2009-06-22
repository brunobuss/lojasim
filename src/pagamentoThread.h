#ifndef VENDATHREAD_H
#define VENDATHREAD_H

#include <QtCore>
#include <cliente.h>
#include <caixa.h>

//Classe responsavel por simular o pagamento dos produtos
//que um cliente comprou.
class pagamentoThread : public QThread
{
	Q_OBJECT

public:
    pagamentoThread(Cliente* cl, Caixa* caixa);
    void run(); //Codigo referente a execucao da thread

signals:
    //Sinaliza que o caixa 'cx' finalizou a operacao de pagamento.
    void finalizouPagamento(Caixa *cx);
    //Registra a mensagem 'log' no log do sistema/output.
    void registerLog(QString log);

private:
   Cliente* c;
   Caixa* cx;
};

#endif
