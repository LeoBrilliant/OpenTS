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

bool InstructionFlow::InsertInstruction(Instruction& inst) {
	instFlow.Push(inst);
	this->SetInsertTime(inst);
	return Constants::SUCCESS;
}

inline void InstructionFlow::SetInsertTime(Instruction& inst) {
	inst.SetInsertTime();
}

inline bool InstructionFlow::ValidateInstruction(Instruction& inst) {
	return Constants::SUCCESS;
}

inline void InstructionFlow::SetConfirmedTime(Instruction& inst) {
	inst.SetConfirmedTime();
}
