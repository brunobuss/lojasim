#ifndef GLOBALDEF_H
#define GLOBALDEF_H

//Log Message Types:
#define LOGM_TYPE_GENERAL 	1

//configuracoes
#define QTDPROD 		15
#define MAXCLIENTNAMES 		40
#define MAXCLIENTLASTNAMES	20
#define MAXP			15
#define MINP			5
#define QTDVENDEDORES		10
#define PROBVENDPREF		30 //[0...100]
#define PROBCOMPRAMENOS		70 //[0...100]
#define MAXSELLERNAMES		10	
#define QNT_MAX_CLIENTES 	20
#define QTDCAIXAS		2
#define QTDESTOQUISTAS		3
#define MAXESTOQUISTANAMES	3
#define MAXCAIXANAMES		2
#define QTDMINPEDIDOS		3
#define MAXTIME			5
#define UNIDTEMPO		100
#define	DIA			144000
#define PONTO_RESUP		3

//memsagem de erro
#define ERROR_INDEX_OUT		-1
#define ERROR_SHAREDMEMORY_FAILED   -2

//Segmentos de memoria compartilhada:
#define SM_PROD_ESTOQUE "lojaSimProdDisp"
#define SM_PROD_REPRIMIDO "lojaSimDemandaReprimida"

#endif //GLOBALDEF_H
