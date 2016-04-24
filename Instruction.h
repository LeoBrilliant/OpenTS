/*
 * Instruction.h
 *
 *  Created on: 2016Äê4ÔÂ24ÈÕ
 *      Author: LeoBrilliant
 */

#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_

#include <chrono>
using namespace std;
using namespace chrono;

class Instruction
{
public:
	Instruction();
	~Instruction();

private:
	int InstructionID;
	string CliendID;
	chrono InsertTime;
	chrono ConfirmedTime;
	chrono UpdateTime;

	static unsigned int InstructionCounter;

public:
	static int GetInstructionCounter();
	static int IncInstructionCounter();
};



#endif /* INSTRUCTION_H_ */
