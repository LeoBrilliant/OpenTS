/*
 * FrontServerTest.cpp
 *
 *  Created on: 2016Äê5ÔÂ23ÈÕ
 *      Author: user
 */

#include "FrontServerTest.h"

FrontServerTest::FrontServerTest() {
}

FrontServerTest::~FrontServerTest() {
}

void FrontServerTest::TestSuite() {
	this->ConstructorTest();

	UnitTestStats();

}

void FrontServerTest::ConstructorTest() {
	ProgramMessage::Debug(__FUNCTION__);
	{
		ProgramMessage::Debug<int>(IncCaseCount());

		FrontServer();
		IncCasePassed();
		ProgramMessage::Debug("Passed");

		ProgramMessage::Debug<int>(IncCaseCount());
		Order * op = GenOrder();

		//char * sql = GetInsertOrderSQL(op);

		IncCasePassed();
		ProgramMessage::Debug("Passed");
	}
}

