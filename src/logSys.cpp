#include <logSys.h>

logSys::logSys()
{
	dia = 1;
}

void logSys::run()
{
    exec();
}


void logSys::geraRelatorioDiario()
{
	bool fail = false;

	gmut.lock();
	cmut.lock();
	vmut.lock();

	/* TODO: Escrever os trecos aqui */
	QFile arquivo("relatorio_diario_nro" + QString::number(dia) + ".txt");

	if(arquivo.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
	{
		QTextStream rel(&arquivo);

		int vendedores[QTDVENDEDORES];
		for(int i = 0; i < QTDVENDEDORES; i++) vendedores[i] = 0;

		int itens[QTDPROD];
		for(int i = 0; i < QTDPROD; i++) itens[i] = 0;


		rel << "Relatorio referente ao dia " + QString::number(dia) + ":\n\n";
		rel << "Vendas realizadas:\n";
		while(!lVenda.isEmpty())
		{
			logMessageVenda log = lVenda.takeFirst();

			for(int i = 0; i < QTDPROD; i++)
			{
				itens[i] += log.getProdutoVendido(i);
				vendedores[log.getVendedor()] += log.getProdutoVendido(i);
			}

			rel << log.getLogMessage();
		}

		rel << "\n\n";

		rel << "Compras realizadas:\n";
		while(!lCompra.isEmpty())
		{
			logMessageCompra log = lCompra.takeFirst();
			rel << log.getLogMessage();
		}

		rel << "\n\n";
		rel << "Produtividade dos vendedores:\n";
		
		int t = 0;

		for(int i = 0; i < QTDVENDEDORES; i++)
		{
			rel << "Vendedor " + QString::number(i) + ": " + QString::number(vendedores[i]) +
				" produtos vendidos.\n";
			t += vendedores[i];
		}
		rel << "TOTAL: " + QString::number(t) + "\n";

		rel << "\n\n";
		rel << "Produtos vendidos:\n";

		t = 0;

		for(int i = 0; i < QTDPROD; i++)
		{
			rel << "Produto " + QString::number(i) + ": " + QString::number(itens[i]) +
				" unidades vendidas.\n";

			t += itens[i];
		}
		rel << "TOTAL: " + QString::number(t) + "\n";

		rel << "\n\n";
		rel << "Fim do relatorio.\n";
	}
	else fail = true;

	dia++;

	vmut.unlock();
	cmut.unlock();
	gmut.unlock();

	if(fail) receiveLog("Falha ao criar o relatorio do dia " + QString::number(dia-1) + "\n");
	else receiveLog("Criado relatorio diario com sucesso.");
}

void logSys::receiveLog(QString msg)
{
    gmut.lock();

    QTextStream ot(stdout);
    msg = "[" + (QTime::currentTime()).toString(Qt::TextDate) +  "] " + msg;
    ot << msg << "\n";

    log.append(msg);

    gmut.unlock();
}

void logSys::receiveLogCompra(logMessageCompra* lc)
{
    cmut.lock();
    lCompra.append(*lc);
    receiveLog(lc->getLogMessage());
    cmut.unlock();
}

void logSys::receiveLogVenda(logMessageVenda* lv)
{
    vmut.lock();
    lVenda.append(*lv);
    receiveLog(lv->getLogMessage());
    vmut.unlock();
}
