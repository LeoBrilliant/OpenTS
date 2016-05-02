/*
 * OrderChainHashTableTest.cpp
 *
 *  Created on: 2016Äê5ÔÂ1ÈÕ
 *      Author: LeoBrilliant
 */

#include "InfrastructureTest.h"


InfrastructureTest::InfrastructureTest() {
}

InfrastructureTest::~InfrastructureTest() {
}

void InfrastructureTest::TestSuite() {
	this->ConstructorTest();

	UnitTestStats();
}

void InfrastructureTest::ConstructorTest()
{
	ProgramMessage::Debug(__FUNCTION__);

	{
		ProgramMessage::Debug<int>(IncCaseCount());
		Infrastructure ocht1;
		StringType name = "TestInstrument";
		StringType code = "Instrument-01";
		StringType underlying = "IF";
		VolumeType multiplier = 300;
		VolumeType quotationUnit = 1;
		PriceType tick = 1.0;
		StringType month = "1606";
		ProgramMessage::Debug(typeid(ocht1).name());
		assert( typeid(ocht1) == typeid(Infrastructure));
		ocht1.InitializeInfrastructure();
		assert(ocht1.InstrumentList.Size() == 1);
		assert(ocht1.InstrumentList[name] != NULL);
/*		assert(ocht1.GetBuckets() == 0);
		assert(ocht1.GetTable() == NULL);
		assert(ocht1.GetDirection() == DirectionType::UNKNOWNDIRECTION);
		ocht1.GetDetail("Hello");*/
		IncCasePassed();
		ProgramMessage::Debug("Passed");
	}

/*	{
		ProgramMessage::Debug<int>(IncCaseCount());
		PriceType upper = 10.0;
		PriceType lower = 1.0;
		PriceType tick = 1.0;
		DirectionType direction = DirectionType::BUY;
		OrderChainHashTable ocht1(direction, tick, upper, lower);
		ProgramMessage::Debug(typeid(ocht1).name());
		assert( typeid(ocht1) == typeid(OrderChainHashTable));
		assert(ocht1.Size() == 0);
		assert(ocht1.GetBuckets() == 10);
		assert(ocht1.GetTable() != NULL);
		assert(ocht1.GetDirection() == direction);
		assert(ocht1.GetBestPrice() == Constants::INVALIDPRICE);
		assert(ocht1.GetBestPriceOrder() == NULL);

		ocht1.GetDetail("Hello");
		IncCasePassed();
		ProgramMessage::Debug("Passed");
	}*/
}
