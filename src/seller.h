#ifndef SELLER_H
#define SELLER_H

#include <QtCore>
#include <globaldef.h>

class Seller : public QObject
{
	Q_OBJECT
	
	int id;
	QString name;

public:
	Seller();
	
	void setName(const QString);
	void setID(const int);
	QString getName(void)const;
	int getID(void)const;
	

};


#endif //SELLER_H
