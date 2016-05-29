/*
 * DBAccessTest.h
 *
 *  Created on: 2016��5��23��
 *      Author: user
 */

#ifndef UNITTEST_FRONTSERVERTEST_H_
#define UNITTEST_FRONTSERVERTEST_H_


#include <../FrontServer.h>
#include "UTBase.h"
#include "TestDataFactory.h"
#include "../MySQLDB.h"

class FrontServerTest : public UTBase<IntIDType>
{
public:
	FrontServerTest();
	~FrontServerTest();
	virtual void TestSuite();

private:
	virtual void ConstructorTest();
};



#endif /* UNITTEST_DBACCESSTEST_H_ */
