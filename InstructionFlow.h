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

ReturnType TestFuncPointer(Instruction & inst)
{
	return Constants::SUCCESS;
}
typedef ReturnType (*DefaultFuncPointer)(Instruction & inst);

	const DefaultFuncPointer DefaultHandler = (DefaultFuncPointer)NULL;

	const static DefaultFuncPointer TestHandler = TestFuncPointer;

//const DefaultFuncPointer DefaultHandler = (DefaultFuncPointer)NULL;

class InstructionFlow
{
public:
	InstructionFlow();

	~InstructionFlow();

	typedef ReturnType (*DefaultFuncPointer)(Instruction & inst);

	const DefaultFuncPointer DefaultHandler = (DefaultFuncPointer)NULL;

//	const static DefaultFuncPointer TestHandler = TestFuncPointer;

	//插入指令
	bool InsertInstruction(Instruction & inst);
	//更新指令插入时间
	void SetInsertTime(Instruction & inst);
	//检查指令的合法性
	bool ValidateInstruction(Instruction & inst);
	//更新指令确认时间
	void SetConfirmedTime(Instruction & inst);
	//通知客户
	//bool ResponseToClient(Instruction & inst);
	//响应客户
	//bool NotifyClient(Instruction & inst);
	//业务处理
	//bool BusinessHandler(Instruction & inst);

private:
	//这里如果用指针队列效果会更好
	Queue<Instruction> instFlow;
	//缓存待处理指令
	Queue<Instruction> instBuffer;

	ReturnType (*BusinessHandler)(Instruction & inst);
	ReturnType (*NotifyClient)(Instruction & inst);
	ReturnType (*ResponseToClient)(Instruction & inst);
};


#endif /* INSTRUCTIONFLOW_H_ */
