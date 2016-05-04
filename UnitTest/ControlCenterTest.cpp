/*
 * ControlCenterTest.cpp
 *
 *  Created on: 2016Äê5ÔÂ4ÈÕ
 *      Author: user
 */


#include "ControlCenterTest.h"

ControlCenterTest::ControlCenterTest() {
}

ControlCenterTest::~ControlCenterTest() {
}

void ControlCenterTest::TestSuite() {
	this->ConstructorTest();

	UnitTestStats();
}

void ControlCenterTest::ConstructorTest() {
	ProgramMessage::Debug(__FUNCTION__);

	{
		ProgramMessage::Debug<int>(IncCaseCount());
		ControlCenter ocht1;
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
		assert( typeid(ocht1) == typeid(ControlCenter));
		assert(ocht1.Infra == NULL);

		ocht1.CommandLoop();
//		ocht1.InitializeInfrastructureAction();
//		assert(ocht1.InstrumentList.Size() == 1);
//		assert(ocht1.InstrumentList[name] != NULL);
//		assert(ocht1.InstrumentList[name]->GetName().compare(name) == 0);
//		assert(ocht1.InstrumentList[name]->GetMultiplier() == multiplier);
//		assert(ocht1.InstrumentList[name]->GetQuotationUnit() == quotationUnit);
//		assert(ocht1.InstrumentList[name]->GetTick() == tick);
//		assert(ocht1.ClientList.Size() == 2);
//		assert(ocht1.ClientList[clientID1].compare(name1) == 0);
//		assert(ocht1.ClientList[clientID2].compare(name2) == 0);
//		assert(ocht1.OrderBooks.Size() == 1);
//		assert(ocht1.OrderBooks[name]->GetLastPrice() == lastPrice);
//		assert(ocht1.OrderBooks[name]->GetAuction() == auction);
//		assert(ocht1.OrderBooks[name]->AskOrderHashQueue.Direction == DirectionType::SELL);
//		assert(ocht1.OrderBooks[name]->AskOrderHashQueue.Tick == tick);
//		assert(ocht1.OrderBooks[name]->AskOrderHashQueue.UpperPriceBound == lastPrice);
//		assert(ocht1.OrderBooks[name]->AskOrderHashQueue.LowerPriceBound == lastPrice);
//		assert(ocht1.OrderBooks[name]->BidOrderHashQueue.Direction == DirectionType::BUY);
//		assert(ocht1.OrderBooks[name]->BidOrderHashQueue.Tick == tick);
//		assert(ocht1.OrderBooks[name]->BidOrderHashQueue.UpperPriceBound == lastPrice);
//		assert(ocht1.OrderBooks[name]->BidOrderHashQueue.LowerPriceBound == lastPrice);
		IncCasePassed();
		ProgramMessage::Debug("Passed");
	}
}
