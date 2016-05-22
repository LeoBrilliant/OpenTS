/*
 * SerializationTest.cpp
 *
 *  Created on: 2016Äê5ÔÂ22ÈÕ
 *      Author: LeoBrilliant
 */

#include "SerializationTest.h"

SerializationTest::SerializationTest() {
}

SerializationTest::~SerializationTest() {
}

void SerializationTest::TestSuite() {
	this->ConstructorTest();

	UnitTestStats();

}

void SerializationTest::ConstructorTest() {
	ProgramMessage::Debug(__FUNCTION__);

	{
		ProgramMessage::Debug<int>(IncCaseCount());
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
		//OrderBook Data
		PriceType lastPrice = 100.00;
		AuctionType auction = AuctionType::CONTINUOUSAUCTION;

		//Instruction Data
		IntIDType InstructionID = 1;
		IntIDType ClientID = 10000001;
		InstructionType InstType = InstructionType::LIMITPRICEORDER;

		Instruction * ip = new Instruction(ClientID, InstType, InstructionID);

		ProgramMessage::Debug(ip);
		assert( typeid(ip) == typeid(Instruction *));
		assert(ip != NULL);

		StringType strInst = SerializeInstruction(ip);
		ProgramMessage::Debug(strInst);

		delete ip;
		ip = NULL;
		ip = DeserialInstruction(strInst);
		assert(ip != NULL);

		StringType strInst2 = SerializeInstruction(ip);
		assert(strInst2.compare(strInst) == 0);
		ProgramMessage::Debug(strInst2);
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

		ProgramMessage::Debug<int>(IncCaseCount());
		Order * op = GenOrder();
		assert(op != NULL);
		StringType strOrder = SerializeOrder(op);
		ProgramMessage::Debug(strOrder);

		delete ip;
		Order * op2 = NULL;
		op2 = DeserializeOrder(strOrder);
		assert(op2 != NULL);

		StringType strOrder2 = SerializeOrder(op2);
		ProgramMessage::Debug(strOrder2);
		//assert(strOrder2.compare(strOrder) == 0);

		IncCasePassed();
		ProgramMessage::Debug("Passed");
	}
}
