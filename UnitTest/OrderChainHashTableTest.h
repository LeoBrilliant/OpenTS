/*
 * OrderChainHashTable.h
 *
 *  Created on: 2016��5��1��
 *      Author: LeoBrilliant
 */

#ifndef UNITTEST_ORDERCHAINHASHTABLETEST_H_
#define UNITTEST_ORDERCHAINHASHTABLETEST_H_

#include "../OrderChainHashTable.h"
#include "UTBase.h"

class OrderChainHashTableTest : public UTBase<IntIDType>
{
public:
	OrderChainHashTableTest();
	~OrderChainHashTableTest();
	virtual void TestSuite();

private:
	virtual void ConstructorTest();
};

//OrderChainHashTableTest::OrderChainHashTableTest() {
//}
//
//OrderChainHashTableTest::~OrderChainHashTableTest() {
//}

#endif /* UNITTEST_ORDERCHAINHASHTABLETEST_H_ */
