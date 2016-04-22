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

};

template<typename Key, typename Value>
unsigned int ChainHashTableTest<Key, Value>::caseCount = 0;
template<typename Key, typename Value>
unsigned int ChainHashTableTest<Key, Value>::casePassed = 0;

template<typename Key, typename Value>
void ChainHashTableTest<Key, Value>::TestSuite()
{
	this->ContructorTest();
}

template<typename Key, typename Value>
void ChainHashTableTest<Key, Value>::ContructorTest()
{
	//cout << __FUNCTION__ << endl;

	ProgramMessage::Debug(__FUNCTION__);
	//cout << "TestCase(" << IncCaseCount() << ")" ;
//	string s = "TestCase(" ;
//	s = s + "1";
	ProgramMessage::Debug<int>(IncCaseCount());
	//ProgramMessage::EndOfLine();
	ChainHashTable<Key, Value> cht1;
	cout << typeid(cht1).name() << "\t";
	assert( typeid(cht1) == typeid(ChainHashTable<Key, Value>));
	//assert( &cht1 != NULL);
	assert(cht1.Size() == 0);
	cht1.GetDetail("Hello");
	//cht1.GetSummary();
	IncCasePassed();
	//cout << "Passed" << endl;
	ProgramMessage::Debug("Passed");
}




#endif /* UNITTEST_CHAINHASHTABLETEST_H_ */
