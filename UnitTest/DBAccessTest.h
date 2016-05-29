/*
 * DBAccessTest.h
 *
 *  Created on: 2016��5��23��
 *      Author: user
 */

#ifndef UNITTEST_DBACCESSTEST_H_
#define UNITTEST_DBACCESSTEST_H_


#include <../DBAccess.h>
#include "UTBase.h"
#include "TestDataFactory.h"
#include "../MySQLDB.h"

class DBAccessTest : public UTBase<IntIDType>
{
public:
	DBAccessTest();
	~DBAccessTest();
	virtual void TestSuite();

private:
	virtual void ConstructorTest();
};



#endif /* UNITTEST_DBACCESSTEST_H_ */
