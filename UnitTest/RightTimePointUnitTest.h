/*
 * TimePointUnitTest.h
 *
 *  Created on: 2016Äê4ÔÂ24ÈÕ
 *      Author: LeoBrilliant
 */

#ifndef UNITTEST_RIGHTTIMEPOINTUNITTEST_H_
#define UNITTEST_RIGHTTIMEPOINTUNITTEST_H_

#include "../RightTimePoint.h"

#include "../ProgramMessage.h"
#include <cstdlib>
#include <limits>
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

	void GetMicroSecondsTest();

	void FromMicroSecondsTest();

	static unsigned int GetCaseCount(){ return caseCount; }
	static unsigned int IncCaseCount(){ return ++caseCount; }
	static unsigned int GetCasePassed(){ return casePassed; }
	static unsigned int IncCasePassed(){ return ++casePassed; }

	static void UnitTestStats();

};

#endif /* UNITTEST_RIGHTTIMEPOINTUNITTEST_H_ */
