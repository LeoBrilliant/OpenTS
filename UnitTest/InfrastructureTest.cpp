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
		//Instrument Data
		StringType name = "TestInstrument";
		StringType code = "Instrument-01";
		StringType underlying = "IF";
		VolumeType multiplier = 300;
		VolumeType quotationUnit = 1;
		PriceType tick = 1.0;
		StringType month = "1606";
		//Client Data
		StringType name1 = "Brilliant", name2 = "Leo";
		IntIDType clientID1 = 1, clientID2 = 2;
		//OrderBook Data
		PriceType lastPrice = 100.00;
		AuctionType auction = AuctionType::CONTINUOUSAUCTION;

		ProgramMessage::Debug(typeid(ocht1).name());
		assert( typeid(ocht1) == typeid(Infrastructure));
		ocht1.InitializeInfrastructureAction();
		assert(ocht1.InstrumentList.Size() == 1);
		assert(ocht1.InstrumentList[name] != NULL);
		assert(ocht1.InstrumentList[name]->GetName().compare(name) == 0);
		assert(ocht1.InstrumentList[name]->GetMultiplier() == multiplier);
		assert(ocht1.InstrumentList[name]->GetQuotationUnit() == quotationUnit);
		assert(ocht1.InstrumentList[name]->GetTick() == tick);
		assert(ocht1.ClientList.Size() == 2);
		assert(ocht1.ClientList[clientID1].compare(name1) == 0);
		assert(ocht1.ClientList[clientID2].compare(name2) == 0);
		assert(ocht1.OrderBooks.Size() == 1);
		assert(ocht1.OrderBooks[name]->GetLastPrice() == lastPrice);
		assert(ocht1.OrderBooks[name]->GetAuction() == auction);
		assert(ocht1.OrderBooks[name]->AskOrderHashQueue.Direction == DirectionType::SELL);
		assert(ocht1.OrderBooks[name]->AskOrderHashQueue.Tick == tick);
		assert(ocht1.OrderBooks[name]->AskOrderHashQueue.UpperPriceBound == lastPrice);
		assert(ocht1.OrderBooks[name]->AskOrderHashQueue.LowerPriceBound == lastPrice);
		assert(ocht1.OrderBooks[name]->BidOrderHashQueue.Direction == DirectionType::BUY);
		assert(ocht1.OrderBooks[name]->BidOrderHashQueue.Tick == tick);
		assert(ocht1.OrderBooks[name]->BidOrderHashQueue.UpperPriceBound == lastPrice);
		assert(ocht1.OrderBooks[name]->BidOrderHashQueue.LowerPriceBound == lastPrice);
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
