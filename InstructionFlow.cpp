/*
 * InstructionFlow.cpp
 *
 *  Created on: 2016Äê4ÔÂ27ÈÕ
 *      Author: user
 */

#include "InstructionFlow.h"

InstructionFlow::InstructionFlow() :
	InstructionHandlers(NULL),
	BusinessHandler(DefaultHandler),
	NotifyClient(DefaultHandler),
	ResponseToClient(DefaultHandler)
{
}

InstructionFlow::~InstructionFlow() {
}

ReturnType InstructionFlow::InsertInstruction(Instruction& inst) {
	instFlow.Push(inst);
	this->SetInsertTime(inst);
	return Constants::SUCCESS;
}

inline VoidType InstructionFlow::SetInsertTime(Instruction& inst) {
	inst.SetInsertTime();
}

inline ReturnType InstructionFlow::ValidateInstruction(Instruction& inst) {
	return Constants::SUCCESS;
}

inline VoidType InstructionFlow::SetConfirmedTime(Instruction& inst) {
	inst.SetConfirmedTime();
}

ReturnType InstructionFlow::InsertInstructionHandlers(Map<StringType, OrderBook *> * handler)
{
//	pair<StringType, OrderBook> p = make_pair(instrument, handler);
//	this->InstructionHandlers.Insert(p);
	this->InstructionHandlers = handler;
	return Constants::SUCCESS;
}

ReturnType InstructionFlow::InsertAction(Instruction &inst)
{
	this->InsertInstruction(inst);

	this->DispatchInstruction(inst);
	return Constants::SUCCESS;
}
ReturnType InstructionFlow::DispatchInstruction(Instruction &inst)
{
	ReturnType ret = Constants::FAILURE;
	Order * op = NULL;
	OrderBook * obp = NULL;
	switch(inst.GetInstType())
	{
	case InstructionType::LIMITPRICEORDER:

	case InstructionType::CANCEL:

	case InstructionType::MARKETPRICEORDER:
		op = (Order *)(&inst);
		obp = (*(this->InstructionHandlers))[op->GetInstrumentID()];
		ret = obp->OrderAction(op);

		break;
	default:
		break;
	}
	return ret;
}
