/*
 * InstructionFlow.h
 *
 *  Created on: 2016年4月24日
 *      Author: LeoBrilliant
 */

#ifndef INSTRUCTIONFLOW_H_
#define INSTRUCTIONFLOW_H_

#include "Instruction.h"
#include "Queue.h"

class InstructionFlow
{
public:
	InstructionFlow();
	~InstructionFlow();

	//更新指令插入时间
	//检查指令的合法性
	//
	//
private:
	//这里如果用指针队列效果会更好
	Queue<Instruction> instFlow;
};


#endif /* INSTRUCTIONFLOW_H_ */
