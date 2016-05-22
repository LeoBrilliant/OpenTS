/*
 * Infrasctructure.h
 *
 *  Created on: 2016��5��2��
 *      Author: LeoBrilliant
 */

#ifndef INFRASTRUCTURE_H_
#define INFRASTRUCTURE_H_

#include "Types.h"
#include "Constants.h"

#include "Instrument.h"
#include "InstructionFlow.h"
#include "OrderBook.h"
#include "Map.h"
#include "Debug.h"

class Infrastructure
{
public:
	Infrastructure();
	~Infrastructure();

	//��ʼ���������ݽṹ
	ReturnType InitializeInfrastructureAction();

	//����ָ��
	ReturnType AcceptInstruction(Instruction & inst);

//private:
	//��ʼ����Լ�б�
	ReturnType InitializeInstruments();
	//��ʼ���ͻ��б�
	ReturnType InitializeClients();
	//��ʼ���ͻ��ʽ�
	ReturnType InitializeFunds();
	//��ʼ���ͻ��ֲ�
	ReturnType InitializePositions();
	//��ʼ���ͻ�����Ȩ��
	ReturnType InitializeTradingRights();
	//��ʼ��ί�в�
	ReturnType InitializeOrderBooks();
	//��ʼ��ָ����
	ReturnType InitializeInstructionFlow();
	//ע��ָ����¼�
	ReturnType RegisterInstructionAction();

	//Members
	//��Լ�б�
	Map<StringType, Instrument*> InstrumentList;
	//�ͻ��б�
	Map<IntIDType, StringType> ClientList;
	//�ͻ��ʽ�
	//�ͻ��ֲ�
	//�ͻ�����Ȩ��
	//ί�в�
	Map<StringType, OrderBook*> OrderBooks;
	//ָ����
	InstructionFlow InstFlow;
};

#endif /* INFRASTRUCTURE_H_ */
