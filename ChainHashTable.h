/*
 * chtbl.h
 *
 *  Created on: 2016Äê2ÔÂ17ÈÕ
 *      Author: LeoBrilliant
 */

#ifndef C_CHTBL_H_
#define C_CHTBL_H_

#include "List.h"

const int ELEMENT_FOUND = 0;
const int ELEMENT_NOT_FOUND = 1;

template<typename Key, typename Value>
class ChainHashTable
{
public:
	ChainHashTable(){
		this->buckets = 0;
		this->h = NULL;
		this->match = NULL;
		this->destroy = NULL;
		this->size = 0;
		this->table = NULL;

		cout << "ChainHashTable Default Constructor" << endl;
	}

private:
	int buckets;

	int (*h)(const Key *key);
	int (*match)(const Key *key1, const Key *key2);
	void (*destroy)(Key *data);

	int size;

	List<Key> * table;

	int chtbl_init(int buckets, int (*h)(const Key *key),
			int (*match)(const Key *key1, const Key *key2),
			void (*destroy)(Key *data));

	void chtbl_destroy();

	int chtbl_insert(const Key *data);

	int chtbl_remove(Key **data);

	int chtbl_lookup(Key **data);

public:
	inline int Size() {return this->size;}

	void GetSummary();
public:
	void GetDetail(const string& s);

	static const enum ConstValue
	{
		ELEMENT_FOUND = 0,
		ELEMENT_NOT_FOUND = 1,
		SUCCESS = 0,
		FAILED = -1,
		EXCEPTION = -1
	} x ;
};


template<typename Key, typename Value>
int ChainHashTable<Key,Value>::chtbl_init(int buckets, int (*h)(const Key *key),
		int (*match)(const Key *key1, const Key *key2),
		void (*destroy)(Key *data))
{
	int i;
	Key k;
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

	this->h = h;
	this->match = match;
	this->destroy = destroy;

	this->size = 0;

	return 0;
}

template<typename Key, typename Value>
void ChainHashTable<Key,Value>::chtbl_destroy()
{
	int i;
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
int ChainHashTable<Key,Value>::chtbl_insert(const Key *data)
{
	const Key *temp;
	int bucket, retval;

	temp = data;
	if(this->chtbl_lookup(&temp) == 0)
	{
		return -1;
	}

	bucket = this->h(data) % this->buckets;

	//if((retval = list_ins_next(&this->table[bucket], NULL, data)) == 0)
	//	this->size++;

	this->table[bucket].PushBack(data);
	this->size++;

	return retval;
}
template<typename Key, typename Value>
int ChainHashTable<Key,Value>::chtbl_remove(Key **data)
{
	Key *element, *prev;
	int  bucket;

	bucket = this->h(*data) % this->buckets;

	//prev = NULL;

	//for(element = list_head(&this->table[bucket]); element != NULL;
	//		element = list_next(element))
	for(typename List<Key>::LstIter element = this->table[bucket].Begin(); element != this->table[bucket].Begin(); element++)
	{
		if(this->match(*data, *element))
		{
			this->table[bucket].Erase(element);
			this->size--;
			return ConstValue::SUCCESS;

		}
	}

	return ConstValue::FAILED;
}
template<typename Key, typename Value>
int ChainHashTable<Key,Value>::chtbl_lookup(Key **data)
{
	Key *element;
	int bucket;

	bucket = this->h(*data) % this->buckets;

	for(typename List<Key>::LstIter element = this->table[bucket].Begin(); element != this->table[bucket].Begin(); element++)
	{
		if(this->match(*data, *element))
		{
			*data = *element;
			return ConstValue::ELEMENT_FOUND;
		}
	}
	return ConstValue::ELEMENT_NOT_FOUND;
}

template<typename Key, typename Value>
void ChainHashTable<Key,Value>::GetSummary()
{
	cout << "Summary[" << endl;
	//cout << "empty: \t" << (this->Empty()? "True":"False") << "\t" << endl;
	cout << "size: \t" << this->Size() << endl;
	//cout << "max_size: \t" << this->MaxSize() << endl;
	cout << "]" << endl;
}

template<typename Key, typename Value>
void ChainHashTable<Key,Value>::GetDetail(const string & s)
{
	cout << s << endl;
	this->GetSummary();
	cout << "Elements[" << endl;
	for(int i=0; i < this->buckets; ++i)
	{
		this->table[i].GetDetail("bucket " + i);
/*		typename List<Key>::LstCstIter iv = this->table[i].Begin();
		while(iv != this->table[i].End())
		{
			cout << "<" << (*iv) << ">" ;
			++iv;
		}	*/
	}
	cout << "]" << endl;
}

/*

template<typename Key, typename Value>
int ChainHashTable<Key,Value>::chtbl_init(int buckets, int (*h)(const Key *key),
		int (*match)(const Key *key1, const Key *key2),
		void (*destroy)(Key *data))
{
	int i;
	Key k;
	try
	{
		this->table = new List<Key>[buckets];
	}
	catch(...)
	{
		return -1;
	}

	this->buckets = buckets;

	//for(i = 0; i < this->buckets; ++i)
	{
		//list_init(&this->table[i], destroy);
	}

	this->h = h;
	this->match = match;
	this->destroy = destroy;

	this->size = 0;

	return 0;
}

template<typename Key, typename Value>
void ChainHashTable<Key,Value>::chtbl_destroy()
{
	int i;
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
int ChainHashTable<Key,Value>::chtbl_insert(const Key *data)
{
	const Key *temp;
	int bucket, retval;

	temp = data;
	if(this->chtbl_lookup(&temp) == 0)
	{
		return -1;
	}

	bucket = this->h(data) % this->buckets;

	//if((retval = list_ins_next(&this->table[bucket], NULL, data)) == 0)
	//	this->size++;

	this->table[bucket].PushBack(data);
	this->size++;

	return retval;
}
template<typename Key, typename Value>
int ChainHashTable<Key,Value>::chtbl_remove(Key **data)
{
	Key *element, *prev;
	int  bucket;

	bucket = this->h(*data) % this->buckets;

	//prev = NULL;

	//for(element = list_head(&this->table[bucket]); element != NULL;
	//		element = list_next(element))
	for(typename List<Key>::LstIter element = this->table[bucket].Begin(); element != this->table[bucket].Begin(); element++)
	{
		if(this->match(*data, *element))
		{
			this->table[bucket].Erase(element);
			this->size--;
			return ConstValue::SUCCESS;

		}
	}

	return ConstValue::FAILED;
}
template<typename Key, typename Value>
int ChainHashTable<Key,Value>::chtbl_lookup(Key **data)
{
	Key *element;
	int bucket;

	bucket = this->h(*data) % this->buckets;

	for(typename List<Key>::LstIter element = this->table[bucket].Begin(); element != this->table[bucket].Begin(); element++)
	{
		if(this->match(*data, *element))
		{
			*data = *element;
			return ConstValue::ELEMENT_FOUND;
		}
	}
	return ConstValue::ELEMENT_NOT_FOUND;
}

template<typename Key, typename Value>
void ChainHashTable<Key,Value>::GetSummary()
{
	cout << "Summary[" << endl;
	//cout << "empty: \t" << (this->Empty()? "True":"False") << "\t" << endl;
	cout << "size: \t" << this->Size() << endl;
	//cout << "max_size: \t" << this->MaxSize() << endl;
	cout << "]" << endl;
}

template<typename Key, typename Value>
void ChainHashTable<Key,Value>::GetDetail(const string & s)
{
	cout << s << endl;
	this->GetSummary();
	cout << "Elements[" << endl;
	for(int i=0; i < this->buckets; ++i)
	{
		this->table[i].GetDetail();
		typename List<Key>::LstCstIter iv = this->table[i].Begin();
		while(iv != this->table[i].End())
		{
			cout << "<" << (*iv) << ">" ;
			++iv;
		}
		cout << "]" << endl;
	}
}
*/

#endif /* C_CHTBL_H_ */
