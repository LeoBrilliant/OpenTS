/*
 * UnitTestFactory.cpp
 *
 *  Created on: 2016��5��1��
 *      Author: LeoBrilliant
 */

#include "UnitTestFactory.h"

void UnitTestEntrance()
{
	ProgramMessage::Debug(__FUNCTION__);

	OrderChainHashTableUT();

	//TimePointUT();

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
	//chtt.ContructorTest();
	chtt.TestSuite();

}

void ListUT()
{
	//ListTest<int> lt;
	//lt.TestSuite();
}

void OrderChainHashTableUT() {
	OrderChainHashTableTest ot;
	ot.TestSuite();
}