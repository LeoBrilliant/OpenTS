/*
 * Infrastructure.cpp
 *
 *  Created on: 2016Äê5ÔÂ2ÈÕ
 *      Author: LeoBrilliant
 */

#include "Infrastructure.h"


Infrastructure::Infrastructure() {
}

Infrastructure::~Infrastructure() {
}

ReturnType Infrastructure::InitializeInfrastructureAction() {
	ReturnType ret = Constants::FAILURE;
	ret = this->InitializeInstruments();
	ret = this->InitializeClients();

	ret = this->InitializeOrderBooks();
	ret = this->RegisterInstructionAction();
	return ret;
}

ReturnType Infrastructure::InitializeInstruments() {
	StringType name = "TestInstrument";
	StringType code = "Instrument-01";
	StringType underlying = "IF";
	VolumeType multiplier = 300;
	VolumeType quotationUnit = 1;
	PriceType tick = 1.0;
	StringType month = "1606";
	Instrument * ip = new Instrument(name, code, underlying, multiplier, quotationUnit,
			tick, month
			);
	pair<StringType, Instrument*> p = make_pair(name, ip);
	//pair<StringType, Instrument*> st(name, ip);
	this->InstrumentList.Insert(p);

	//this->InstrumentList[name] = ip;
	return Constants::SUCCESS;
}

ReturnType Infrastructure::InitializeClients() {
	StringType name1 = "Brilliant", name2 = "Leo";
	IntIDType clientID1 = 1, clientID2 = 2;
	pair<IntIDType, StringType> p = make_pair(clientID1, name1);
	this->ClientList.Insert(p);
	p = make_pair(clientID2, name2);
	this->ClientList.Insert(p);
	return Constants::SUCCESS;
}

ReturnType Infrastructure::InitializeFunds() {
	return Constants::SUCCESS;
}

ReturnType Infrastructure::InitializePositions() {
	return Constants::SUCCESS;
}

ReturnType Infrastructure::InitializeTradingRights() {
	return Constants::SUCCESS;
}

ReturnType Infrastructure::InitializeOrderBooks() {

	for(typename Map<StringType, Instrument*>::MapIter iter = this->InstrumentList.Begin();
			iter != this->InstrumentList.End(); ++ iter)
	{
		PriceType lastPrice = 100.00;
		AuctionType auction = AuctionType::CONTINUOUSAUCTION;
		OrderBook * op = new OrderBook(iter->second,lastPrice, auction);
		pair<StringType, OrderBook*> p = make_pair(iter->first, op);
		this->OrderBooks.Insert(p);
	}
	return Constants::SUCCESS;
}

ReturnType Infrastructure::InitializeInstructionFlow() {
	return Constants::SUCCESS;
}

ReturnType Infrastructure::AcceptInstruction(Instruction& inst) {
	this->InstFlow.InsertAction(inst);
	return Constants::SUCCESS;
}

ReturnType Infrastructure::RegisterInstructionAction() {
	typedef ReturnType (*InstrumentAction)(Instruction * inst);
	for(typename Map<StringType, OrderBook*>::MapIter iter = this->OrderBooks.Begin();
			iter != this->OrderBooks.End(); ++ iter)
	{
		//pair<StringType, InstrumentAction> p = make_pair(iter->first, iter->second->OrderAction);
		this->InstFlow.InsertInstructionHandlers(iter->first,InstrumentAction(&iter->second->OrderAction));
	}
	return Constants::SUCCESS;
}
