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
#include "Order.h"
#include "ProgramMessage.h"
#include "List.h"

class OrderChainHashTable
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

//private:
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

private:
	int buckets;

	List<Order *> * table;

	int size;

	virtual int chtbl_init(int buckets, int (*h)(const Order * key),
			int (*match)(const Order * key1, const Order * key2),
			void (*destroy)(Order * data));

	virtual void chtbl_destroy();

	virtual int chtbl_insert(Order * data);

	virtual int chtbl_remove(Order * data);

	virtual int chtbl_lookup(Order * data);

public:
	inline int Size() {return this->size;}

	inline int Insert(Order * data){ return chtbl_insert(data); }
	inline int Remove(Order * data){ return chtbl_remove(data); }
	inline int LookUp(Order * data){ return chtbl_lookup(data); }

	virtual typename List<Order *>::LstCstIter GetBeginIter(int i);
	virtual typename List<Order *>::LstCstIter GetEndIter(int i);

	virtual inline void Clear();

	virtual void GetSummary();

	virtual void GetDetail(const string& s);
	virtual int GetBuckets() const;
	virtual const List<Order *>* GetTable() const;
	//virtual void SetHashfunc(int (*hashfunc)(const Order * key));
	//virtual void SetMatch(int (*match)(Order * key1, Order * key2));

	void SetBuckets(int buckets) {
		this->buckets = buckets;
	}

	void SetTable(List<Order *>* table) {
		this->table = table;
	}

	static const enum ConstValue
	{
		ELEMENT_FOUND = 0,
		ELEMENT_NOT_FOUND = 1,
		SUCCESS = 0,
		FAILED = -1,
		EXCEPTION = -1
	} x ;

	//template<typename Order *1, typename Value1>
	//friend class ChainHashTableTest;
};



#endif /* ORDERCHAINHASHTABLE_H_ */
