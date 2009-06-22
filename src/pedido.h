#ifndef PEDIDO_H
#define PEDIDO_H

//Classe referente ao um pedido de re-estoque
class Pedido
{

public:
	Pedido();
	//Retorna ID do item a ser re-estocado
	int getID(void)const;
	//Define ID do item a ser re-estocado
	void setID(const int);

private:
	int id;
	
};

#endif //PEDIDO_H
