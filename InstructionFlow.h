/*
 * InstructionFlow.h
 *
 *  Created on: 2016年4月24日
 *      Author: LeoBrilliant
 */

#ifndef INSTRUCTIONFLOW_H_
#define INSTRUCTIONFLOW_H_

#include "Instruction.h"
#include "Order.h"
#include "Queue.h"
#include "Map.h"

//ReturnType TestFuncPointer(Instruction & inst)
//{
//	return Constants::SUCCESS;
//}
//typedef ReturnType (*DefaultFuncPointer)(Instruction & inst);

//const DefaultFuncPointer DefaultHandler = (DefaultFuncPointer)NULL;

//const static DefaultFuncPointer TestHandler = TestFuncPointer;

//const DefaultFuncPointer DefaultHandler = (DefaultFuncPointer)NULL;

class InstructionFlow
{
public:
	InstructionFlow();

	~InstructionFlow();

	typedef ReturnType (*DefaultFuncPointer)(Instruction & inst);
	typedef ReturnType (*InstrumentAction)(Instruction * inst);

	const DefaultFuncPointer DefaultHandler = (DefaultFuncPointer)NULL;

//	const static DefaultFuncPointer TestHandler = TestFuncPointer;

	//插入指令
	ReturnType InsertInstruction(Instruction & inst);
	//更新指令插入时间
	VoidType SetInsertTime(Instruction & inst);
	//检查指令的合法性
	ReturnType ValidateInstruction(Instruction & inst);
	//更新指令确认时间
	VoidType SetConfirmedTime(Instruction & inst);
	//通知客户
	//bool ResponseToClient(Instruction & inst);
	//响应客户
	//bool NotifyClient(Instruction & inst);
	//业务处理
	//bool BusinessHandler(Instruction & inst);

	//更新指令处理方法
	ReturnType InsertInstructionHandlers(StringType instrument, InstrumentAction handler);

	//插入动作处理
	ReturnType InsertAction(Instruction &inst);
	//分发指令
	ReturnType DispatchInstruction(Instruction &inst);

private:
	//这里如果用指针队列效果会更好
	Queue<Instruction> instFlow;
	//缓存待处理指令
	Queue<Instruction> instBuffer;

	//指令事件处理集合
	Map<StringType, InstrumentAction> InstructionHandlers;

	ReturnType (*BusinessHandler)(Instruction & inst);
	ReturnType (*NotifyClient)(Instruction & inst);
	ReturnType (*ResponseToClient)(Instruction & inst);
};


#endif /* INSTRUCTIONFLOW_H_ */
