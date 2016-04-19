/*
 * chtbl.cpp
 *
 *  Created on: 2016��2��17��
 *      Author: LeoBrilliant
 */

#include "ChainHashTable.h"

#include <cstdlib>
#include <cstring>

#include "List.h"

template<typename Key, typename Value>
int ChainHashTable<Key,Value>::chtbl_init(int buckets, int (*h)(const void *key),
		int (*match)(const void *key1, const void *key2),
		void (*destroy)(void *data))
{
	int i;
	Key k;
	if((this->table = new List<Key>[buckets](buckets, k) ))
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

	if((retval = list_ins_next(&this->table[bucket], NULL, data)) == 0)
		this->size++;

	return retval;
}
template<typename Key, typename Value>
int ChainHashTable<Key,Value>::chtbl_remove(Key **data)
{
	Key *element, *prev;
	int  bucket;

	bucket = this->h(*data) % this->buckets;

	prev = NULL;

	for(element = list_head(&this->table[bucket]); element != NULL;
			element = list_next(element))
	{
		if(this->match(*data, list_data(element)))
		{
			if(list_rem_next(&this->table[bucket], prev, data) == 0)
			{
				this->size--;
				return 0;
			}
			else
			{
				return -1;
			}
		}
		prev = element;
	}

	return -1;
}
template<typename Key, typename Value>
int ChainHashTable<Key,Value>::chtbl_lookup(Key **data)
{
	Key *element;
	int bucket;

	bucket = this->h(*data) % this->buckets;

	for(element = list_head(&this->table[bucket]); element != NULL; element = list_next(element))
	{
		if(this->match(*data, list_data(element)))
		{
			*data = list_data(element);
			return 0;
		}
	}

	return -1;
}