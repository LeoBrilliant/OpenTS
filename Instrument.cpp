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

Instrument::~Instrument() {
}
