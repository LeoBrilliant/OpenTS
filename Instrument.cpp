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

Instrument::~Instrument() {
}
