/*
 * Instruction.h
 *
 *  Created on: 2016Äê4ÔÂ24ÈÕ
 *      Author: LeoBrilliant
 */

#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_

#include "RightTimePoint.h"
#include "Constants.h"
#include "Types.h"

#include <string>

using namespace std;
using namespace constants;

class Instruction
{
public:
	Instruction();
	Instruction(IntIDType clientID, InstructionType instType, int instID = IncInstructionCounter());
	~Instruction();

private:
	IntIDType InstructionID;
	IntIDType ClientID;
	InstructionType InstType;
	RightTimePoint InsertTime;
	RightTimePoint ConfirmedTime;
	RightTimePoint UpdateTime;

	static IntIDType InstructionCounter;

public:
	static int GetInstructionCounter();
	static int IncInstructionCounter();

	IntIDType GetClientID() const;
	void SetClientID(IntIDType cliendID);

	const RightTimePoint& GetConfirmedTime() const;
	void SetConfirmedTime(RightTimePoint& confirmedTime);
	void SetConfirmedTime();

	const RightTimePoint& GetInsertTime() const;
	void SetInsertTime(RightTimePoint& insertTime);
	void SetInsertTime();

	int GetInstructionID() const;
	void SetInstructionID(int instructionID = InstructionCounter);
	//void SetInstructionID();

	const RightTimePoint& GetUpdateTime() const;
	void SetUpdateTime(RightTimePoint& updateTime);
	void SetUpdateTime();
	InstructionType GetInstType() const;
	void SetInstType(InstructionType instType);
};



#endif /* INSTRUCTION_H_ */
