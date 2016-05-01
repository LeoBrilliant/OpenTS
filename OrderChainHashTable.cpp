/*
 * OrderChainHashTable.cpp
 *
 *  Created on: 2016Äê5ÔÂ1ÈÕ
 *      Author: LeoBrilliant
 */

#include "OrderChainHashTable.h"

OrderChainHashTable::OrderChainHashTable() : Direction(DirectionType::UNKNOWNDIRECTION)
{
}

OrderChainHashTable::~OrderChainHashTable() {
}

Order* OrderChainHashTable::GetBestPriceOrder() {
	return NULL;
}

PriceType OrderChainHashTable::GetBestPrice() {
	return Constants::INVALIDPRICE;
}

DirectionType OrderChainHashTable::GetDirection() {
	return this->Direction;
}
