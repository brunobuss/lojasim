#ifndef SELLER_H
#define SELLER_H

#include <QtCore>
#include <globaldef.h>

class Seller : public QObject
{
	Q_OBJECT
	
	QString name;

public:
	Seller();
	void setName(const QString);
	QString getName(void)const;

};


#endif //SELLER_H
