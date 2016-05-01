/*
 * OrderChainHashTable.cpp
 *
 *  Created on: 2016Äê5ÔÂ1ÈÕ
 *      Author: LeoBrilliant
 */

#include "OrderChainHashTable.h"

OrderChainHashTable::OrderChainHashTable() : Direction(DirectionType::UNKNOWNDIRECTION),
	Tick(DirectionType::UNKNOWNDIRECTION), UpperPriceBound(DirectionType::UNKNOWNDIRECTION),
			LowerPriceBound(DirectionType::UNKNOWNDIRECTION)
{
	//this->hashfunc = NULL;
}

OrderChainHashTable::~OrderChainHashTable() {
}

Order* OrderChainHashTable::GetBestPriceOrder() {
	Order * op = NULL;
	PriceType bestPrice = this->GetBestPrice();
	op = this->GetFirstOrder(bestPrice);
	return op;
}

PriceType OrderChainHashTable::GetBestPrice() {
	PriceType bestPrice = Constants::INVALIDPRICE;
	switch(this->GetDirection())
	{
	case DirectionType::BUY:
		bestPrice = this->GetMaxPrice();
		break;
	case DirectionType::SELL:
		bestPrice = this->GetMinPrice();
		break;
	default:
		break;
	}
	return bestPrice;
}

int HashFunc(Order* key)
{
	int priceLevel = Constants::INVALIDINTID;
//	//assert(this->Tick > 0);
//	priceLevel = (key->GetOrderPrice() - this->LowerPriceBound()) / this->Tick;
	return priceLevel;
}

OrderChainHashTable::OrderChainHashTable(DirectionType direction,
		PriceType tick, PriceType upperPriceBound, PriceType lowerPriceBound) :
				/*ChainHashTable(0, HashFunc, NULL, NULL),*/
			Direction(direction), Tick(tick), UpperPriceBound(upperPriceBound),
			LowerPriceBound(lowerPriceBound)
{
	//assert(key->GetOrderPrice() >= this->LowerPriceBound);
	int buckets = this->CalBuckets();
	this->SetBuckets(buckets);
	this->SetHashfunc(::HashFunc);
	typedef int (*PFMatch)(Order* key1, Order* key2);
	//typedef int (*PFMatch)(key key1, key key2);
	void * tmpfunc = (void*)(&this->MatchFunc);
	this->SetMatch((PFMatch)(&this->MatchFunc));
	this->SetMatch((PFMatch)(tmpfunc));
	this->SetMatch((int(*)(Order*, Order*))(&this->MatchFunc));

	this->SetHashfunc((int(*)(Order*))(&this->HashFunc));

	List<Order *> * table = new List<Order *>[buckets];
	this->SetTable(table);
}

DirectionType OrderChainHashTable::GetDirection() {
	return this->Direction;
}

int  OrderChainHashTable::HashFunc(Order* key)
{
	int priceLevel = Constants::INVALIDINTID;
	//assert(key->GetOrderPrice() >= this->LowerPriceBound());
	//assert(this->Tick > 0);
	priceLevel = (key->GetOrderPrice() - this->LowerPriceBound) / this->Tick;
	return priceLevel;
}


int  OrderChainHashTable::MatchFunc(Order* key1, Order* key2)
{
	//assert(key1 != NULL);
	//assert(key2 != NULL);
	return key1 == key2;
}

IntIDType OrderChainHashTable::CalBuckets() {
	//assert(key->GetOrderPrice() >= this->LowerPriceBound());
	int buckets = (this->UpperPriceBound - this->LowerPriceBound) / this->Tick + 1;
	return buckets;
}

PriceType OrderChainHashTable::GetMaxPrice() {
	PriceType maxPrice = Constants::INVALIDPRICE;
	for(int i = 0; i < this->GetBuckets(); ++ i)
	{
		int price = this->GetLevelPrice(i);
		if(price != Constants::INVALIDPRICE)
		{
			if(price > maxPrice)
			{
				maxPrice = price;
			}
		}
	}
	return maxPrice;
}

PriceType OrderChainHashTable::GetMinPrice() {
	PriceType minPrice = Constants::INVALIDPRICE;
	for(int i = 0; i < this->GetBuckets(); ++ i)
	{
		int price = this->GetLevelPrice(i);
		if(price != Constants::INVALIDPRICE)
		{
			if(price < minPrice)
			{
				minPrice = price;
			}
		}
	}
	return minPrice;
}

PriceType OrderChainHashTable::GetLevelPrice(IntIDType level) {
	PriceType price = Constants::INVALIDPRICE;
	List<Order*>::LstCstIter begin = this->GetBeginIter(level);
	List<Order*>::LstCstIter end = this->GetEndIter(level);
	if(begin != end)
	{
		price = (*begin)->GetOrderPrice();
	}
	return price;
}

Order* OrderChainHashTable::GetFirstOrder(PriceType price) {
	//assert(price >= this->LowerPriceBound());
	Order * op = NULL;
	if(price != Constants::INVALIDPRICE){
		int level = (price - this->LowerPriceBound) / this->Tick ;
		List<Order*>::LstCstIter begin = this->GetBeginIter(level);
		List<Order*>::LstCstIter end = this->GetEndIter(level);
		if(begin != end)
		{
			op = (*begin);
		}
	}
	return op;
}
