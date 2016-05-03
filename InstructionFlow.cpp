/*
 * InstructionFlow.cpp
 *
 *  Created on: 2016Äê4ÔÂ27ÈÕ
 *      Author: user
 */

#include "InstructionFlow.h"

InstructionFlow::InstructionFlow() :
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

ReturnType InstructionFlow::InsertInstructionHandlers(StringType instrument, InstrumentAction handler)
{
	pair<StringType, InstrumentAction> p = make_pair(instrument, handler);
	this->InstructionHandlers.Insert(p);
	return Constants::SUCCESS;
}
