/*
 * InfrastructureTest.h
 *
 *  Created on: 2016Äê5ÔÂ2ÈÕ
 *      Author: LeoBrilliant
 */

#ifndef UNITTEST_INFRASTRUCTURETEST_H_
#define UNITTEST_INFRASTRUCTURETEST_H_


#include "../Infrasctructure.h"
#include "UTBase.h"

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
