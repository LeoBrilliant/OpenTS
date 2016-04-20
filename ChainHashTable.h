/*
 * chtbl.h
 *
 *  Created on: 2016Äê2ÔÂ17ÈÕ
 *      Author: LeoBrilliant
 */

#ifndef C_CHTBL_H_
#define C_CHTBL_H_

#include <cstdlib>

#include "List.h"

const int ELEMENT_FOUND = 0;
const int ELEMENT_NOT_FOUND = 1;

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

	static const enum ConstValue
	{
		ELEMENT_FOUND = 0,
		ELEMENT_NOT_FOUND = 1,
		SUCCESS = 0,
		FAILED = -1
	} x ;
};

#endif /* C_CHTBL_H_ */
