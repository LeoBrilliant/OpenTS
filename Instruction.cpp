/*
 * Instruction.cpp
 *
 *  Created on: 2016Äê4ÔÂ25ÈÕ
 *      Author: user
 */

#include "Instruction.h"

unsigned int Instruction::InstructionCounter = Constants::STARTOFINSTRUMENTID;

Instruction::Instruction() : InstructionID(Constants::INVALIDINSTRUMENTID)
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


const string& Instruction::GetCliendId() const {
	return CliendID;
}

void Instruction::SetCliendId(const string& cliendId) {
	CliendID = cliendId;
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

void Instruction::SetUpdateTime() {
	this->UpdateTime = RightTimePoint::Now();
}
