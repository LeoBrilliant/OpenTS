/*
 * InstructionFlow.h
 *
 *  Created on: 2016��4��24��
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

	//����ָ��
	ReturnType InsertInstruction(Instruction & inst);
	//����ָ�����ʱ��
	VoidType SetInsertTime(Instruction & inst);
	//���ָ��ĺϷ���
	ReturnType ValidateInstruction(Instruction & inst);
	//����ָ��ȷ��ʱ��
	VoidType SetConfirmedTime(Instruction & inst);
	//֪ͨ�ͻ�
	//bool ResponseToClient(Instruction & inst);
	//��Ӧ�ͻ�
	//bool NotifyClient(Instruction & inst);
	//ҵ����
	//bool BusinessHandler(Instruction & inst);

	//����ָ�����
	ReturnType InsertInstructionHandlers(StringType instrument, InstrumentAction handler);

	//���붯������
	ReturnType InsertAction(Instruction &inst);
	//�ַ�ָ��
	ReturnType DispatchInstruction(Instruction &inst);

private:
	//���������ָ�����Ч�������
	Queue<Instruction> instFlow;
	//���������ָ��
	Queue<Instruction> instBuffer;

	//ָ���¼�������
	Map<StringType, InstrumentAction> InstructionHandlers;

	ReturnType (*BusinessHandler)(Instruction & inst);
	ReturnType (*NotifyClient)(Instruction & inst);
	ReturnType (*ResponseToClient)(Instruction & inst);
};


#endif /* INSTRUCTIONFLOW_H_ */
