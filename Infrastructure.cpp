/*
 * Infrastructure.cpp
 *
 *  Created on: 2016Äê5ÔÂ2ÈÕ
 *      Author: LeoBrilliant
 */

#include "Infrasctructure.h"


Infrastructure::Infrastructure() {
}

Infrastructure::~Infrastructure() {
}

ReturnType Infrastructure::InitializeInfrastructure() {
	ReturnType ret = Constants::FAILURE;
	ret = this->InitializeInstruments();
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
	return Constants::SUCCESS;
}

ReturnType Infrastructure::InitializeInstructionFlow() {
	return Constants::SUCCESS;
}

ReturnType Infrastructure::RegisterInstructionAction() {
	return Constants::SUCCESS;
}
