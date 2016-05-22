/*
 * SerializationTest.h
 *
 *  Created on: 2016Äê5ÔÂ22ÈÕ
 *      Author: LeoBrilliant
 */

#ifndef UNITTEST_SERIALIZATIONTEST_H_
#define UNITTEST_SERIALIZATIONTEST_H_

#include <../Serialization.h>
#include "UTBase.h"
#include "TestDataFactory.h"

class SerializationTest : public UTBase<IntIDType>
{
public:
	SerializationTest();
	~SerializationTest();
	virtual void TestSuite();

private:
	virtual void ConstructorTest();
};


#endif /* UNITTEST_SERIALIZATIONTEST_H_ */
