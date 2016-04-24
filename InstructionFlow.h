/*
 * InstructionFlow.h
 *
 *  Created on: 2016��4��24��
 *      Author: LeoBrilliant
 */

#ifndef INSTRUCTIONFLOW_H_
#define INSTRUCTIONFLOW_H_

#include "Order.h"
#include "Queue.h"

class InstructionFlow
{
public:
	InstructionFlow();
	~InstructionFlow();

	static enum InstructionType
	{
		LIMITPRICEORDER=1,
		MARKETPRICEORDER=2,
		CANCEL=3
	};

	//����ָ�����ʱ��
	//���ָ��ĺϷ���
	//
	//
private:
	//���������ָ�����Ч�������
	Queue<Order> instFlow;
};


#endif /* INSTRUCTIONFLOW_H_ */
