/*
 * TestDataFactory.cpp
 *
 *  Created on: 2016Äê5ÔÂ22ÈÕ
 *      Author: LeoBrilliant
 */

#include "TestDataFactory.h"


		//Instrument Data
		StringType name = "TestInstrument";
		StringType code = "Instrument-01";
		StringType underlying = "IF";
		VolumeType multiplier = 300;
		VolumeType quotationUnit = 1;
		PriceType tick = 1.0;
		StringType month = "1606";
		//OrderBook Data
		PriceType lastPrice = 100.00;
		AuctionType auction = AuctionType::CONTINUOUSAUCTION;

		//Instruction Data
		IntIDType InstructionID = 1;
		IntIDType ClientID = 10000001;
		InstructionType InstType = InstructionType::LIMITPRICEORDER;

IntIDType GenClientID()
{
	static IntIDType clientID = 10000001;
	return clientID ++;
}

IntIDType GenLocalOrderID()
{
	static IntIDType localOrderID = 1;
	return localOrderID++;
}

StringType GenClientName()
{
	static vector<string> clientName { "Leo", "Brilliant", "Hello", "World" };
	static IntIDType nameIndex = 0;
	return clientName[nameIndex++/clientName.size()];
}

Order * GenOrder()
{
	Order * op = new Order(
				GenClientID(),
				(InstructionType::LIMITPRICEORDER),
				(string)("TestInstrument"),
				(DirectionType::BUY),
				(OffsetType::OPEN),
				(PriceType)(101.34),
				(VolumeType)(32),
				GenLocalOrderID()
				);

	return op;
}

