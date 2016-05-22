/*
 * ControlCenter.h
 *
 *  Created on: 2016Äê5ÔÂ2ÈÕ
 *      Author: LeoBrilliant
 */

#ifndef CONTROLCENTER_H_
#define CONTROLCENTER_H_

#include "Types.h"
#include "Constants.h"
#include "Infrastructure.h"

#include "Instrument.h"
#include "InstructionFlow.h"
#include "OrderBook.h"

class ControlCenter
{
public:
	ControlCenter();
	~ControlCenter();

//private:

	void CommandLoop();

	VoidType RegisterInfrastructure(Infrastructure *ip);

	Infrastructure * Infra;
};


#endif /* CONTROLCENTER_H_ */
