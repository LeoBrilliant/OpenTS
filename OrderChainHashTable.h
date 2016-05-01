/*
 * OrderChainHashTable.h
 *
 *  Created on: 2016Äê5ÔÂ1ÈÕ
 *      Author: LeoBrilliant
 */

#ifndef ORDERCHAINHASHTABLE_H_
#define ORDERCHAINHASHTABLE_H_

#include "Types.h"
#include "Constants.h"
#include "ChainHashTable.h"
#include "Order.h"
#include "ProgramMessage.h"

class OrderChainHashTable : public ChainHashTable<Order*, string>
{
public:
	OrderChainHashTable();
	virtual ~OrderChainHashTable();
	Order* GetBestPriceOrder();
	PriceType GetBestPrice();

	DirectionType GetDirection();

private:
	DirectionType Direction;
};



#endif /* ORDERCHAINHASHTABLE_H_ */
