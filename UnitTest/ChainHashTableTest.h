/*
 * ChainHashTableTest.h
 *
 *  Created on: 2016Äê4ÔÂ21ÈÕ
 *      Author: LeoBrilliant
 */

#ifndef UNITTEST_CHAINHASHTABLETEST_H_
#define UNITTEST_CHAINHASHTABLETEST_H_

#include "../ChainHashTable.h"
#include "../ProgramMessage.h"
#include <cmath>
#include <cstdlib>

#include "UTBase.h"

using namespace std;

using ::ProgramMessage;

template<typename Key, typename Value>
class ChainHashTableTest /*: public UTBase<Key>*/
{
	//using ::ProgramMessage;
	static unsigned int caseCount;
	static unsigned int casePassed;

public:
	//Constructor
	ChainHashTableTest() { cout << typeid(this).name() << endl; }

	//Constructor Test
	void ContructorTest();

	//Operator= Test
	void OperatorEqualTest();

	//OperatorNew Test
	void OperatorNewTest();

	//Exception Test
	void ExceptioinTest();

	//Signal Test
	void SignalTest();

	//Operator[] Test
	void OperatorSquareBracketsTest();

	//Apply Test
	void ApplyTest();

	//Shift Test
	void ShiftTest();

	//Resize Test
	void ResizeTest();

	//Test suite
	void TestSuite();

	//Destructor
	~ChainHashTableTest(){};

	static unsigned int GetCaseCount(){ return caseCount; }
	static unsigned int IncCaseCount(){ return ++caseCount; }
	static unsigned int GetCasePassed(){ return casePassed; }
	static unsigned int IncCasePassed(){ return ++casePassed; }

	static void UnitTestStats();

};

template<typename Key, typename Value>
unsigned int ChainHashTableTest<Key, Value>::caseCount = 0;
template<typename Key, typename Value>
unsigned int ChainHashTableTest<Key, Value>::casePassed = 0;

template<typename Key, typename Value>
void ChainHashTableTest<Key, Value>::TestSuite()
{
	this->ContructorTest();

	UnitTestStats();
}

template<typename Key>
int HashFunc(const Key key)
{
	return abs(key) * 1;
}

template<typename Key>
int MatchFunc(Key key1, Key key2)
{
	return key1 == key2;
}

template<typename Key>
void DestroyFunc(Key key)
{
	key = -11;
}

template<typename Key, typename Value>
void ChainHashTableTest<Key, Value>::ContructorTest()
{
	ProgramMessage::Debug(__FUNCTION__);
	ProgramMessage::Debug<int>(IncCaseCount());
	ChainHashTable<Key, Value> cht1;
	ProgramMessage::Debug(typeid(cht1).name());
	assert( typeid(cht1) == typeid(ChainHashTable<Key, Value>));
	assert(cht1.Size() == 0);
	cht1.GetDetail("Hello");
	IncCasePassed();
	ProgramMessage::Debug("Passed");

	ProgramMessage::Debug<int>(IncCaseCount());
	{
		assert(typeid(Key) == typeid(int));
		typedef int (*PFHash)(const Key key);
		typedef int (*PFMatch)(Key key1, Key key2);
		typedef	void (*PFDestroy)(Key data);

		PFHash fpHash = HashFunc;
		PFMatch fpMatch = MatchFunc;
		PFDestroy fpDestroy = DestroyFunc;
		int iBuckets = 10;
		ChainHashTable<Key, Value> cht1(iBuckets, fpHash, fpMatch, fpDestroy);
		ProgramMessage::Debug(typeid(cht1).name());
		assert( typeid(cht1) == typeid(ChainHashTable<Key, Value>));
		assert(cht1.Size() == 0);
		cht1.GetDetail("Hello");
		IncCasePassed();
		ProgramMessage::Debug("Passed");

		ProgramMessage::Debug<int>(IncCaseCount());
		ProgramMessage::Debug("Insert Test");
		int array[iBuckets];
		for(int i = 0; i < iBuckets; ++i)
		{
			array[i] = i;
			cht1.Insert(array[i]);
		}
		for(int i = 0; i < iBuckets; ++i)
		{
			for(typename List<Key>::LstCstIter iter = cht1.GetBeginIter(i); iter != cht1.GetEndIter(i); ++iter)
			{
				assert(i == *iter);
			}
		}
		cht1.GetDetail("Insert Array");
		IncCasePassed();
		ProgramMessage::Debug("Passed");

		ProgramMessage::Debug<int>(IncCaseCount());
		ProgramMessage::Debug("Clear Test");
		cht1.Clear();
		assert( typeid(cht1) == typeid(ChainHashTable<Key, Value>));
		assert(cht1.Size() == 0);
		for(int i = 0; i < iBuckets; ++i)
		{
			assert(cht1.GetBeginIter(i) == cht1.GetEndIter(i));
		}
		cht1.GetDetail("Cleared");
		IncCasePassed();
		ProgramMessage::Debug("Passed");

		ProgramMessage::Debug<int>(IncCaseCount());
		ProgramMessage::Debug("Insert Test");
		//int array[iBuckets];
		int counter = 0;
		srand(time(0));
		int val = rand() % iBuckets;
		cht1.Clear();
		for(int i = 0; i < iBuckets; ++i)
		{
			array[i] = val;
			cht1.Insert(array[i]);
		}
		//assert(cht1.Size() == iBuckets);
		assert(cht1.Size() == 1);
		for(int i = 0; i < iBuckets; ++i)
		{
			for(typename List<Key>::LstCstIter iter = cht1.GetBeginIter(i); iter != cht1.GetEndIter(i); ++iter)
			{
				assert(val == *iter);
				counter++;
			}
		}
		assert(counter == 1);
		//assert(counter == iBuckets);
		cht1.GetDetail("Insert Array");
		IncCasePassed();
		ProgramMessage::Debug("Passed");
	}
}

template<typename Key, typename Value>
void ChainHashTableTest<Key, Value>::UnitTestStats() {
	ProgramMessage::Print<Key>(ChainHashTableTest<Key, Value>::GetCaseCount());
	ProgramMessage::Print(" Cases in total, ");
	ProgramMessage::Print<Key>(ChainHashTableTest<Key, Value>::GetCasePassed());
	ProgramMessage::PrintLine(" Cases Passed.");
}


#endif /* UNITTEST_CHAINHASHTABLETEST_H_ */
