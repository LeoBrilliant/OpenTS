/*
 * Infrasctructure.h
 *
 *  Created on: 2016年5月2日
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

	//初始化基础数据结构
	ReturnType InitializeInfrastructureAction();

	//接收指令
	ReturnType AcceptInstruction(Instruction & inst);

//private:
	//初始化合约列表
	ReturnType InitializeInstruments();
	//初始化客户列表
	ReturnType InitializeClients();
	//初始化客户资金
	ReturnType InitializeFunds();
	//初始化客户持仓
	ReturnType InitializePositions();
	//初始化客户交易权限
	ReturnType InitializeTradingRights();
	//初始化委托簿
	ReturnType InitializeOrderBooks();
	//初始化指令流
	ReturnType InitializeInstructionFlow();
	//注册指令处理事件
	ReturnType RegisterInstructionAction();

	//Members
	//合约列表
	Map<StringType, Instrument*> InstrumentList;
	//客户列表
	Map<IntIDType, StringType> ClientList;
	//客户资金
	//客户持仓
	//客户交易权限
	//委托簿
	Map<StringType, OrderBook*> OrderBooks;
	//指令流
	InstructionFlow InstFlow;
};

#endif /* INFRASTRUCTURE_H_ */
