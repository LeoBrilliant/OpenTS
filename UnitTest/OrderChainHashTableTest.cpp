/*
 * OrderChainHashTableTest.cpp
 *
 *  Created on: 2016Äê5ÔÂ1ÈÕ
 *      Author: LeoBrilliant
 */

#include "OrderChainHashTableTest.h"

//void OrderChainHashTableTest::TestSuite()
//{
//
//}

OrderChainHashTableTest::OrderChainHashTableTest() {
}

OrderChainHashTableTest::~OrderChainHashTableTest() {
}

void OrderChainHashTableTest::TestSuite() {
	this->ConstructorTest();

	UnitTestStats();
}

void OrderChainHashTableTest::ConstructorTest()
{
	ProgramMessage::Debug(__FUNCTION__);

	{
		ProgramMessage::Debug<int>(IncCaseCount());
		OrderChainHashTable ocht1;
		ProgramMessage::Debug(typeid(ocht1).name());
		assert( typeid(ocht1) == typeid(OrderChainHashTable));
		assert(ocht1.Size() == 0);
		assert(ocht1.GetBuckets() == 0);
		assert(ocht1.GetTable() == NULL);
		assert(ocht1.GetDirection() == DirectionType::UNKNOWNDIRECTION);
		ocht1.GetDetail("Hello");
		IncCasePassed();
		ProgramMessage::Debug("Passed");
	}
}
