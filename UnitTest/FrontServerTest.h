/*
 * DBAccessTest.h
 *
 *  Created on: 2016Äê5ÔÂ23ÈÕ
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
