/*
 * HashTable.h
 *
 *  Created on: 2016��4��19��
 *      Author: user
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <vector>
#include <map>

using namespace std;

template<typename Key, typename Value>
class HashTable
{
public:
	HashTable();

private:
	map<Key,Value> ht;
};



#endif /* HASHTABLE_H_ */
