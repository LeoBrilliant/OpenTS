/*
 * Instrument.cpp
 *
 *  Created on: 2016��4��28��
 *      Author: LeoBrilliant
 */

#include "Instrument.h"

Instrument::Instrument(): Name(InvalidString),
	Code(InvalidString),
	Underlying(InvalidString),
	Multiplier(Constants::INVALIDVOLUME),
	QuotationUnit(Constants::INVALIDVOLUME),
	Tick(Constants::INVALIDPRICE),
	Month(InvalidString)
{
}

Instrument::Instrument(StringType name, StringType code, StringType underlying,
		VolumeType multiplier, VolumeType quotationUnit, PriceType tick,
		StringType month): Name(name),
				Code(code),
				Underlying(underlying),
				Multiplier(multiplier),
				QuotationUnit(quotationUnit),
				Tick(tick),
				Month(month)
{
}

Instrument::~Instrument() {
}

const StringType& Instrument::GetCode() const {
	return Code;
}

const StringType& Instrument::GetMonth() const {
	return Month;
}

VolumeType Instrument::GetMultiplier() const {
	return Multiplier;
}

const StringType& Instrument::GetName() const {
	return Name;
}

VolumeType Instrument::GetQuotationUnit() const {
	return QuotationUnit;
}

PriceType Instrument::GetTick() const {
	return Tick;
}

const StringType& Instrument::GetUnderlying() const {
	return Underlying;
}
