/*
 * UnitTestHeader.h
 *
 *  Created on: 2016Äê4ÔÂ24ÈÕ
 *      Author: LeoBrilliant
 */

#ifndef UNITTEST_UNITTESTHEADER_H_
#define UNITTEST_UNITTESTHEADER_H_


#include "ListTest.h"
#include "ChainHashTableTest.h"
#include "RightTimePointUnitTest.h"

void TimePointUT();
void ChainHashTableUT();
void ListUT();

void UnitTestEntrance()
{
	ProgramMessage::Debug(__FUNCTION__);

	TimePointUT();

	//ChainHashTableUT();

	//ListUT();
}

void TimePointUT()
{
	TimePointUnitTest tpt;
	tpt.TestSuite();
}

void ChainHashTableUT()
{
	ChainHashTableTest<int, char> chtt;
	chtt.ContructorTest();
	//chtt.TestSuite();

}

void ListUT()
{
	//ListTest<int> lt;
	//lt.TestSuite();
}

#endif /* UNITTEST_UNITTESTHEADER_H_ */
