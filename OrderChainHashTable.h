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
	OrderChainHashTable(
			DirectionType direction,
			PriceType tick,
			PriceType upperPriceBound,
			PriceType lowerPriceBound
	);
	virtual ~OrderChainHashTable();
	Order* GetBestPriceOrder();
	PriceType GetBestPrice();

	DirectionType GetDirection();

private:
	DirectionType Direction;
	PriceType Tick;
	PriceType UpperPriceBound;
	PriceType LowerPriceBound;

	int HashFunc(Order* key);

	int MatchFunc(Order* key1, Order* key2);

	IntIDType CalBuckets();

	PriceType GetMaxPrice();
	PriceType GetMinPrice();
	PriceType GetLevelPrice(IntIDType level);
	Order* GetFirstOrder(PriceType price);
};



#endif /* ORDERCHAINHASHTABLE_H_ */
