/*
 * InstructionFlow.cpp
 *
 *  Created on: 2016��4��27��
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
