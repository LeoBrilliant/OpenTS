/*
 * Map.cpp
 *
 *  Created on: 2016Äê1ÔÂ26ÈÕ
 *      Author: user
 */

#include "Map.h"

/*
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
}*/
