#include <cliente.h>

Cliente::Cliente(const int ida, unsigned int sid)
{
	int t;
	int tempid[QTDPROD];
	int maxprod;
	int i,j;
	
	id = ida;

	qsrand(sid);

//Sorteia os produtos
	maxprod = QTDPROD;
  for(i = 0; i < QTDPROD; i++)
  {
  	tempid[i] = i;
  }
  numProdutos = (qrand()%(QTDPROD-1)) + 1;
  for(i = 0 ; i < numProdutos; i++)
  {
  	t = qrand()%maxprod;
  	idProdDesejado[i] = tempid[t];
  	qtdProdDesejados[i] = qrand()%(MAXP-MINP+1) + MINP;
  	
  	maxprod--;
  	for(j = t; j < maxprod; j++)
  	{
  		tempid[j] = tempid[j+1];
  	}
  }
  // Configura questoes de compra
	t = qrand()%100;
	if(t < PROBCOMPRAMENOS)
		compraMenos = true;
	else
		compraMenos = false;
	
	// Configura questoes do Vendedor
	idVendedorPreferido = qrand()%QTDVENDEDORES;
	t = qrand()%100;
	if(t < PROBVENDPREF)
		desejaVendedor = true;
	else
		desejaVendedor = false;
	

	//configura o nome;	
	nome = clientName[qrand()%MAXCLIENTNAMES];
	sobrenome = clientLastName[qrand()%MAXCLIENTLASTNAMES];
	
	nomeCompleto = nome + " " + sobrenome;
	
}

bool Cliente::getCompraMenos(void)const
{
 		return compraMenos;
}

int Cliente::getNumProdutos(void)const
{
		return numProdutos;
}

int Cliente::getProduto(const int ind)const
{
	if(ind>=0 && ind < numProdutos)
		return idProdDesejado[ind];
	else
		return ERROR_INDEX_OUT;
}

int Cliente::getQtdProduto(const int ind)const
{
	if(ind >= 0 && ind < numProdutos)
		return qtdProdDesejados[ind];
	else
		return ERROR_INDEX_OUT;
}

QString Cliente::getNomeID(void)const
{
	QString r;

	r = nomeCompleto + " (" + QString::number(id) + ")";

	return r;	
}

int Cliente::getID(void)const
{
	return id;
}

int Cliente::getVendedorPref(void)const
{
	if(desejaVendedor)
		return idVendedorPreferido;
	else
		return -1;
}
