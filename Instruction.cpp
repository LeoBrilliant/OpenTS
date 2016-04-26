/*
 * Instruction.cpp
 *
 *  Created on: 2016Äê4ÔÂ25ÈÕ
 *      Author: user
 */

#include "Instruction.h"

unsigned int Instruction::InstructionCounter = Constants::STARTOFINTID;

Instruction::Instruction() : InstructionID(Constants::INVALIDINSTRUMENTID),
		ClientID(Constants::INVALIDINTID),
		InstType(InstructionType::UNKNOWNINSTRUCTION)
{
}

Instruction::Instruction(IntIDType clientID,
		InstructionType instType, int instID): InstructionID(instID),
				ClientID(clientID),
				InstType(instType)
{
}

Instruction::~Instruction() {
}

int Instruction::GetInstructionCounter() {
	return InstructionCounter;
}

int Instruction::IncInstructionCounter() {
	return InstructionCounter++;
}


IntIDType Instruction::GetClientId() const {
	return ClientID;
}

void Instruction::SetClientId(IntIDType clientId) {
	ClientID = clientId;
}

const RightTimePoint& Instruction::GetConfirmedTime() const {
	return ConfirmedTime;
}

void Instruction::SetConfirmedTime(RightTimePoint& confirmedTime) {
	ConfirmedTime = confirmedTime;
}

const RightTimePoint& Instruction::GetInsertTime() const {
	return InsertTime;
}

void Instruction::SetInsertTime(RightTimePoint& insertTime) {
	InsertTime = insertTime;
}


int Instruction::GetInstructionId() const {
	return InstructionID;
}

void Instruction::SetInstructionId(int instructionId) {
	InstructionID = instructionId;
}

const RightTimePoint& Instruction::GetUpdateTime() const {
	return UpdateTime;
}

void Instruction::SetConfirmedTime() {
	this->ConfirmedTime = RightTimePoint::Now();
}

void Instruction::SetInsertTime() {
	this->InsertTime = RightTimePoint::Now();
}

//void Instruction::SetInstructionId() {
//	this->InstructionID = IncInstructionCounter();
//}

void Instruction::SetUpdateTime(RightTimePoint& updateTime) {
	UpdateTime = updateTime;
}

InstructionType Instruction::GetInstType() const {
	return InstType;
}

void Instruction::SetInstType(InstructionType instType) {
	InstType = instType;
}

void Instruction::SetUpdateTime() {
	this->UpdateTime = RightTimePoint::Now();
}
