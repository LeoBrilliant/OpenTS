/*
 * InfrastructureTest.h
 *
 *  Created on: 2016��5��2��
 *      Author: LeoBrilliant
 */

#ifndef UNITTEST_INFRASTRUCTURETEST_H_
#define UNITTEST_INFRASTRUCTURETEST_H_


#include "../Infrastructure.h"

#include "../Debug.h"
#include "UTBase.h"
#include <string>

class InfrastructureTest : public UTBase<IntIDType>
{
public:
	InfrastructureTest();
	~InfrastructureTest();
	virtual void TestSuite();

private:
	virtual void ConstructorTest();
};


#endif /* UNITTEST_INFRASTRUCTURETEST_H_ */
