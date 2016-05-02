/*
 * Map.h
 *
 *  Created on: 2016Äê1ÔÂ26ÈÕ
 *      Author: user
 */

#ifndef STL_MAPOPS_H_
#define STL_MAPOPS_H_

#include <map>
#include <iostream>
using namespace std;

template <typename Key, typename Value>
class Map
{
typedef typename map<Key, Value>::iterator MapIter;
typedef typename map<Key, Value>::reverse_iterator RMapIter;

private:
	map<Key, Value> mt;

public:
	//Constructor
	Map();
	Map(Map<Key, Value> & m);
	Map(MapIter first, MapIter last);

	//Destructor
	~Map();

	//Operator
	Map<Key, Value> & operator=(Map& m) { mt = m.GetMt(); return *this; }

	//Iterators
	MapIter Begin() { return mt.begin(); }
	MapIter End() { return mt.end(); }
	RMapIter Rbegin() { return mt.rbegin(); }
	RMapIter Rend() { return mt.rend(); }

	//Capacity
	bool Empty() { return mt.empty(); }
	size_t Size() { return mt.size(); }
	size_t MaxSize() { return mt.max_size(); }


	//Element access
	Value & operator[](const Key & k) { return mt[k]; }

	//Modifiers
	pair<MapIter, bool> Insert(pair<Key, Value>& p) { return mt.insert(p); }
	MapIter Insert(MapIter position, const pair<Key, Value> & p) { return mt.insert(position, p); }
	void Insert(MapIter first, MapIter last) { mt.insert(first, last); }
	void Erase(MapIter position) { mt.erase(position); }
	size_t Erase(const Key& k) { return mt.erase(k); }
	void Erase(MapIter first, MapIter last) { mt.erase(first, last); }
	void Swap(Map& x) { mt.swap(x.GetMt); }
	void Clear() { mt.clear(); }

	//Observers
	typename map<Key, Value>::key_compare KeyCompare() const { return mt.key_comp(); }
	typename map<Key, Value>::value_compare ValueCompare() const { return mt.value_comp(); }

	//Operations
	MapIter Find(const Key& k) { return mt.find(k); }
	size_t Count(const Key& k) { return mt.count(k); }
	MapIter LowerBound(const Key& k) { return mt.lower_bound(k); }
	MapIter UpperBound(const Key& k) { return mt.upper_bound(k); }
	pair<MapIter, MapIter> EqualRange(const Key& k) { return mt.equal_range(k); }

	//Getter
	map<Key, Value> & GetMt() { return mt; }

	//Summary
	void GetSummary();
	//Detail
	void GetDetail(const string &);

	// Allocator

};

template<typename Key, typename Value>
Map<Key, Value>::Map(): mt()
{
	cout << "Map Constructor: Default" << endl;
}

template<typename Key, typename Value>
Map<Key, Value>::Map(Map<Key, Value> &m): mt(m.GetMt())
{
	cout << "Map Constructor: Copy" << endl;
}

template<typename Key, typename Value>
Map<Key, Value>::Map(MapIter first, MapIter last):mt(first, last)
{
	cout << "Map Constructor: Fill dt with iterator from first to last" << endl;
}

template<typename Key, typename Value>
Map<Key, Value>::~Map()
{
	mt.clear();
	cout << "Map Destructor: Default" << endl;
}

template<typename Key, typename Value>
void Map<Key, Value>::GetSummary()
{
	cout << "Summary[" << endl;
	cout << "empty: \t" << (this->Empty()? "True":"False") << "\t" << endl;
	cout << "size: \t" << this->Size() << endl;
	cout << "max_size: \t" << this->MaxSize() << endl;
	cout << "]" << endl;
}

template<typename Key, typename Value>
void Map<Key, Value>::GetDetail(const string & s)
{
	cout << s << endl;
	this->GetSummary();
	cout << "Elements[" << endl;
	MapIter iv = this->Begin();
	while(iv != this->End())
	{
		cout << "<" << iv->first >> ", " >> iv->second >> ">" ;
		++iv;
	}
	cout << "]" << endl;
}

#endif /* STL_MAPOPS_H_ */
