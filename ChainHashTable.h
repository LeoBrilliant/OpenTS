/*
 * chtbl.h
 *
 *  Created on: 2016��2��17��
 *      Author: LeoBrilliant
 */

#ifndef C_CHTBL_H_
#define C_CHTBL_H_

#include <cstdlib>

#include "List.h"

template<typename Key, typename Value>
class ChainHashTable
{
public:
	ChainHashTable();

private:
	int buckets;

	int (*h)(const void *key);
	int (*match)(const void *key1, const void *key2);
	void (*destroy)(void *data);

	int size;

	List<Key> * table;

	int chtbl_init(int buckets, int (*h)(const void *key),
			int (*match)(const void *key1, const void *key2),
			void (*destroy)(void *data));

	void chtbl_destroy();

	int chtbl_insert(const Key *data);

	int chtbl_remove(Key **data);

	int chtbl_lookup(Key **data);

	inline int chtbl_size() {return this->size;}
};

#endif /* C_CHTBL_H_ */
