/*
 * OrderChainHashTable.cpp
 *
 *  Created on: 2016Äê5ÔÂ1ÈÕ
 *      Author: LeoBrilliant
 */

#include "OrderChainHashTable.h"

OrderChainHashTable::OrderChainHashTable() :
Direction(DirectionType::UNKNOWNDIRECTION),
	Tick(DirectionType::UNKNOWNDIRECTION),
	UpperPriceBound(DirectionType::UNKNOWNDIRECTION),
	LowerPriceBound(DirectionType::UNKNOWNDIRECTION),
	buckets(NULL),
	table(NULL),
	size(0)

{
	//this->HashFunc = NULL;
	cout << "OrderChainHashTable Default Constructor" << endl;
}

OrderChainHashTable::~OrderChainHashTable() {
	ProgramMessage::Debug("OrderChainHashTable Destructor");
	if(this->table)
	{
		delete [] this->table;
		this->table = NULL;
	}
}

Order* OrderChainHashTable::GetBestPriceOrder() {
	Order * op = NULL;
	PriceType bestPrice = this->GetBestPrice();
	op = this->GetFirstOrder(bestPrice);
	return op;
}

PriceType OrderChainHashTable::GetBestPrice() {
	PriceType bestPrice = Constants::INVALIDPRICE;
	DirectionType direction = this->GetDirection();
	switch(direction)
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

OrderChainHashTable::OrderChainHashTable(DirectionType direction,
		PriceType tick, PriceType upperPriceBound, PriceType lowerPriceBound) :
			Direction(direction),
			Tick(tick),
			UpperPriceBound(upperPriceBound),
			LowerPriceBound(lowerPriceBound),
			buckets(NULL),
			table(NULL),
			size(0)
{
	//assert(key->GetOrderPrice() >= this->LowerPriceBound);
	int buckets = this->CalBuckets();
	this->SetBuckets(buckets);
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
	return key1->GetOrderID() == key2->GetOrderID();
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
		int level = (price - this->LowerPriceBound) / this->Tick;
		level %= this->buckets ;
		List<Order*>::LstCstIter begin = this->GetBeginIter(level);
		List<Order*>::LstCstIter end = this->GetEndIter(level);
		if(begin != end)
		{
			op = (*begin);
		}
	}
	return op;
}

int OrderChainHashTable::chtbl_init(int buckets, int (*HashFunc)(const Order * key),
		int (*MatchFunc)(const Order * key1, const Order * key2),
		void (*destroy)(Order * data))
{
	try
	{
		this->table = new List<Order *>[buckets];
	}
	catch(...)
	{
		return ConstValue::EXCEPTION;
	}

	this->buckets = buckets;

	//for(i = 0; i < this->buckets; ++i)
	{
		//list_init(&this->table[i], destroy);
	}

	this->size = 0;

	return 0;
}


void OrderChainHashTable::chtbl_destroy()
{
	//for(i = 0; i < this->buckets; ++i)
	{
		//list_destroy(&this->table[i]);
	}

	delete [] this->table ;

	//ToDo
	//other destruct code below

	return;
}


int OrderChainHashTable::chtbl_insert(Order * data)
{
	Order * temp;
	int bucket, retval;

	temp = data;
	if(this->chtbl_lookup(temp) == ConstValue::ELEMENT_FOUND)
	{
		return ConstValue::FAILED;
	}

	bucket = this->HashFunc(data) % this->buckets;

	this->table[bucket].PushBack(data);
	this->size++;

	return retval=this->Size();
}


int OrderChainHashTable::chtbl_remove(Order * data)
{
	//Order * element, prev;
	int  bucket;

	bucket = this->HashFunc(data) % this->buckets;

	for(typename List<Order *>::LstCstIter element = this->table[bucket].Begin(); element != this->table[bucket].Begin(); element++)
	{
		if(this->MatchFunc(data, *element))
		{
			this->table[bucket].Erase(element);
			this->size--;
			return ConstValue::SUCCESS;

		}
	}

	return ConstValue::FAILED;
}

int OrderChainHashTable::chtbl_lookup(Order * data)
{
	int bucket;

	bucket = this->HashFunc(data) % this->buckets;

	for(typename List<Order *>::LstCstIter element = this->table[bucket].Begin(); element != this->table[bucket].End(); element++)
	{
		if(this->MatchFunc(data, *element))
		{
			data = *element;
			return ConstValue::ELEMENT_FOUND;
		}
	}
	return ConstValue::ELEMENT_NOT_FOUND;
}


void OrderChainHashTable::GetSummary()
{
	ProgramMessage::Debug("Summary[");
	ProgramMessage::Debug("size:\t");
	ProgramMessage::Debug<int>(this->Size());
	ProgramMessage::Debug("]");
}


inline typename List<Order *>::LstCstIter OrderChainHashTable::GetBeginIter(int i) {
	return this->table[i].Begin();
}


inline typename List<Order *>::LstCstIter OrderChainHashTable::GetEndIter(int i) {
	if(i >= 0 && i < this->buckets)
		return this->table[i].End();
	return this->table[i].End();
}


inline void OrderChainHashTable::Clear() {
	for(int i = 0; i < this->buckets; ++i)
	{
		this->table[i].Clear();
	}
	this->size = 0;
}


inline int OrderChainHashTable::GetBuckets() const {
	return buckets;
}


inline const List<Order *>* OrderChainHashTable::GetTable() const {
	return table;
}

void OrderChainHashTable::GetDetail(const string & s)
{
	ProgramMessage::Debug(s);
	this->GetSummary();
	ProgramMessage::Debug("Elements[");
	for(int i=0; i < this->buckets; ++i)
	{
		ProgramMessage::Debug("bucket");
		char str[20];
		sprintf(str, "%d", i);
		this->table[i].GetDetail(str);
	}
	ProgramMessage::Debug("]");
}
