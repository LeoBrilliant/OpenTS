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

class InstructionFlow
{
public:
	InstructionFlow();
	~InstructionFlow();

	//����ָ�����ʱ��
	//���ָ��ĺϷ���
	//
	//
private:
	//���������ָ�����Ч�������
	Queue<Instruction> instFlow;
};


#endif /* INSTRUCTIONFLOW_H_ */
