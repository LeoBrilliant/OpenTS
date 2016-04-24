/*
 * TimePointUnitTest.h
 *
 *  Created on: 2016Äê4ÔÂ24ÈÕ
 *      Author: LeoBrilliant
 */

#ifndef UNITTEST_TIMEPOINTUNITTEST_H_
#define UNITTEST_TIMEPOINTUNITTEST_H_

#include "../ProgramMessage.h"
#include "../TimePoint.h"
#include <cstdlib>
#include "UTBase.h"

class TimePointUnitTest
{
public:
	TimePointUnitTest();
	~TimePointUnitTest();

	//using ::ProgramMessage;

	//Test suite
	void TestSuite();

private:
	static unsigned int caseCount;
	static unsigned int casePassed;

public:
	//Constructor Test
	void ContructorTest();

	//Now Test
	void NowTest();

	static unsigned int GetCaseCount(){ return caseCount; }
	static unsigned int IncCaseCount(){ return ++caseCount; }
	static unsigned int GetCasePassed(){ return casePassed; }
	static unsigned int IncCasePassed(){ return ++casePassed; }

	static void UnitTestStats();

};

#endif /* UNITTEST_TIMEPOINTUNITTEST_H_ */
