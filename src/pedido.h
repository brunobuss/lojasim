#ifndef PEDIDO_H
#define PEDIDO_H

class Pedido
{

public:
	Pedido();
	int getID(void)const;
	void setID(const int);

private:
	int id;
	
};

#endif //PEDIDO_H
