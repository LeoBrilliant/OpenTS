/*
 * chtbl.h
 *
 *  Created on: 2016Äê2ÔÂ17ÈÕ
 *      Author: LeoBrilliant
 */

#ifndef C_CHTBL_H_
#define C_CHTBL_H_

#include "ProgramMessage.h"
#include "List.h"
#include <cstdlib>
#include <cstdio>
//#include "UnitTest/ChainHashTableTest.h"

const int ELEMENT_FOUND = 0;
const int ELEMENT_NOT_FOUND = 1;

template<typename Key, typename Value>
class ChainHashTable
{
public:
	ChainHashTable(){
		this->buckets = 0;
		this->hashfunc = NULL;
		this->match = NULL;
		this->destroy = NULL;
		this->size = 0;
		this->table = NULL;

		cout << "ChainHashTable Default Constructor" << endl;
	}

	ChainHashTable(
			int buckets,
			int (*hashfunc)(const Key key),
			int (*match)(Key key1, Key key2),
			void (*destroy)(Key data)
	);

	virtual ~ChainHashTable();

private:
	int buckets;

	int (*hashfunc)(const Key key);
	int (*match)(Key key1, Key key2);
	void (*destroy)(Key data);

	int size;

	List<Key> * table;

	virtual int chtbl_init(int buckets, int (*h)(const Key key),
			int (*match)(const Key key1, const Key key2),
			void (*destroy)(Key data));

	virtual void chtbl_destroy();

	virtual int chtbl_insert(Key data);

	virtual int chtbl_remove(Key data);

	virtual int chtbl_lookup(Key data);

public:
	inline int Size() {return this->size;}

	inline int Insert(Key data){ return chtbl_insert(data); }
	inline int Remove(Key data){ return chtbl_remove(data); }
	inline int LookUp(Key data){ return chtbl_lookup(data); }

	virtual typename List<Key>::LstCstIter GetBeginIter(int i);
	virtual typename List<Key>::LstCstIter GetEndIter(int i);

	virtual inline void Clear();

	virtual void GetSummary();

	virtual void GetDetail(const string& s);
	virtual int GetBuckets() const;
	virtual const List<Key>* GetTable() const;
	virtual void SetHashfunc(int (*hashfunc)(const Key key));
	virtual void SetMatch(int (*match)(Key key1, Key key2));

	void SetBuckets(int buckets) {
		this->buckets = buckets;
	}

	void SetTable(List<Key>* table) {
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

	//template<typename Key1, typename Value1>
	//friend class ChainHashTableTest;
};

template<typename Key, typename Value>
ChainHashTable<Key,Value>::ChainHashTable(
		int buckets,
		int (*hash)(const Key key),
		int (*match)(Key key1, Key key2),
		void (*destroy)(Key data)) :
		buckets(buckets), hashfunc(hash), match(match), destroy(destroy)
{
	//int i;
	//Key k;
	ProgramMessage::Debug("ChainHashTable Constructor");
	try
	{
		ProgramMessage::Debug("Allocate New buckets");
		this->table = new List<Key>[buckets];
	}
	catch(...)
	{
		ProgramMessage::Fatal("Allocate New buckets Failed");
		//return ConstValue::EXCEPTION;
	}

	this->buckets = buckets;

	//for(i = 0; i < this->buckets; ++i)
	{
		//list_init(&this->table[i], destroy);
	}

	this->size = 0;

	//return 0;
}

template<typename Key, typename Value>
ChainHashTable<Key,Value>::~ChainHashTable()
{
	ProgramMessage::Debug("ChainHashTable Destructor");
	if(this->table)
	{
		delete [] this->table;
		this->table = NULL;
	}
}

template<typename Key, typename Value>
int ChainHashTable<Key,Value>::chtbl_init(int buckets, int (*hashfunc)(const Key key),
		int (*match)(const Key key1, const Key key2),
		void (*destroy)(Key data))
{
	try
	{
		this->table = new List<Key>[buckets];
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

	this->hashfunc = hashfunc;
	this->match = match;
	this->destroy = destroy;

	this->size = 0;

	return 0;
}

template<typename Key, typename Value>
void ChainHashTable<Key,Value>::chtbl_destroy()
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

template<typename Key, typename Value>
int ChainHashTable<Key,Value>::chtbl_insert(Key data)
{
	Key temp;
	int bucket, retval;

	temp = data;
	if(this->chtbl_lookup(temp) == ConstValue::ELEMENT_FOUND)
	{
		return ConstValue::FAILED;
	}

	bucket = this->hashfunc(data) % this->buckets;

	this->table[bucket].PushBack(data);
	this->size++;

	return retval=this->Size();
}

template<typename Key, typename Value>
int ChainHashTable<Key,Value>::chtbl_remove(Key data)
{
	//Key element, prev;
	int  bucket;

	bucket = this->hashfunc(data) % this->buckets;

	for(typename List<Key>::LstCstIter element = this->table[bucket].Begin(); element != this->table[bucket].Begin(); element++)
	{
		if(this->match(data, *element))
		{
			this->table[bucket].Erase(element);
			this->size--;
			return ConstValue::SUCCESS;

		}
	}

	return ConstValue::FAILED;
}
template<typename Key, typename Value>
int ChainHashTable<Key,Value>::chtbl_lookup(Key data)
{
	int bucket;

	bucket = this->hashfunc(data) % this->buckets;

	for(typename List<Key>::LstCstIter element = this->table[bucket].Begin(); element != this->table[bucket].End(); element++)
	{
		if(this->match(data, *element))
		{
			data = *element;
			return ConstValue::ELEMENT_FOUND;
		}
	}
	return ConstValue::ELEMENT_NOT_FOUND;
}

template<typename Key, typename Value>
void ChainHashTable<Key,Value>::GetSummary()
{
	ProgramMessage::Debug("Summary[");
	ProgramMessage::Debug("size:\t");
	ProgramMessage::Debug<int>(this->Size());
	ProgramMessage::Debug("]");
}

template<typename Key, typename Value>
inline typename List<Key>::LstCstIter ChainHashTable<Key, Value>::GetBeginIter(int i) {
	return this->table[i].Begin();
}

template<typename Key, typename Value>
inline typename List<Key>::LstCstIter ChainHashTable<Key, Value>::GetEndIter(int i) {
	if(i >= 0 && i < this->buckets)
		return this->table[i].End();
	return this->table[i].End();
}

template<typename Key, typename Value>
inline void ChainHashTable<Key, Value>::Clear() {
	for(int i = 0; i < this->buckets; ++i)
	{
		this->table[i].Clear();
	}
	this->size = 0;
}

template<typename Key, typename Value>
inline int ChainHashTable<Key, Value>::GetBuckets() const {
	return buckets;
}

template<typename Key, typename Value>
inline void ChainHashTable<Key,Value>::SetHashfunc(int (*hashfunc)(const Key key))
{
	this->hashfunc = hashfunc;
}

template<typename Key, typename Value>
inline void ChainHashTable<Key,Value>::SetMatch(int (*match)(Key key1, Key key2))
{
	this->match = match;
}

template<typename Key, typename Value>
inline const List<Key>* ChainHashTable<Key, Value>::GetTable() const {
	return table;
}

template<typename Key, typename Value>
void ChainHashTable<Key,Value>::GetDetail(const string & s)
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

#endif /* C_CHTBL_H_ */
