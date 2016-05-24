/*
 * UnitTestFactory.cpp
 *
 *  Created on: 2016Äê5ÔÂ1ÈÕ
 *      Author: LeoBrilliant
 */

#include "UnitTestFactory.h"

void UnitTestEntrance()
{
	ProgramMessage::Debug(__FUNCTION__);

	DBAccessUT();
	//SerializationUT();

	//ControlCenterUT();

	//InfrastructureUT();

	//OrderChainHashTableUT();

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

void InfrastructureUT()
{
	InfrastructureTest it;
	it.TestSuite();
}

void ControlCenterUT()
{
	ControlCenterTest it;
	it.TestSuite();
}

void SerializationUT()
{
	SerializationTest st;
	st.TestSuite();
}

void DBAccessUT()
{
	DBAccessTest dt;
	dt.TestSuite();
}
