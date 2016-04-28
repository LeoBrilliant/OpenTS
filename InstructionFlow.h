/*
 * InstructionFlow.h
 *
 *  Created on: 2016��4��24��
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

	//����ָ��
	bool InsertInstruction(Instruction & inst);
	//����ָ�����ʱ��
	void SetInsertTime(Instruction & inst);
	//���ָ��ĺϷ���
	bool ValidateInstruction(Instruction & inst);
	//����ָ��ȷ��ʱ��
	void SetConfirmedTime(Instruction & inst);
	//֪ͨ�ͻ�
	//bool ResponseToClient(Instruction & inst);
	//��Ӧ�ͻ�
	//bool NotifyClient(Instruction & inst);
	//ҵ����
	//bool BusinessHandler(Instruction & inst);

private:
	//���������ָ�����Ч�������
	Queue<Instruction> instFlow;
	//���������ָ��
	Queue<Instruction> instBuffer;

	ReturnType (*BusinessHandler)(Instruction & inst);
	ReturnType (*NotifyClient)(Instruction & inst);
	ReturnType (*ResponseToClient)(Instruction & inst);
};


#endif /* INSTRUCTIONFLOW_H_ */
