/*
 * Instrument.cpp
 *
 *  Created on: 2016Äê4ÔÂ28ÈÕ
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
