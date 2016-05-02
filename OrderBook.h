/*
 * OrderBook.h
 *
 *  Created on: 2016年4月11日
 *      Author: user
 */

#ifndef ORDERBOOK_H_
#define ORDERBOOK_H_

#include <vector>
#include "Instrument.h"
#include "ChainHashTable.h"
#include "Order.h"
#include "Queue.h"
#include "List.h"
#include "Types.h"
#include "OrderChainHashTable.h"
#include "Constants.h"
#include "TradingRecord.h"

class OrderBook
{
public:
	OrderBook();

	~OrderBook();

private:
	//合约信息
	Instrument * IntrumentInfo;
	//订单档位哈希队列
	OrderChainHashTable BidOrderHashQueue;
	OrderChainHashTable AskOrderHashQueue;

	//订单档位优先队列
	//TODO先不考虑行情
	//订单队列
	List<Order*> OrderFlow;

	//成交流
	List<TradingRecord*> TradingFlow;

	//最新价
	PriceType LastPrice;

	//竞价类型
	AuctionType Auction;

public:
	//获取最优一档订单
	Order * GetBestPriceOrder(DirectionType direction);

	//获取最新价
	inline PriceType GetLastPrice();

	//处理用户指令
	ReturnType OrderAction(Instruction * inst);
private:
	//插入订单队列
	ReturnType InsertIntoOrderFlow(Order * o);
	//获取对手方
	Order * GetCounterParties(Order *op);
	//获取限价指令成交价
	PriceType GetTradingPrice(Order * buy, Order * sell);
	//获取成交量
	VolumeType GetTradingVolume(Order* buy, Order* sell);
	//生成成交记录
	TradingRecord* GenTradingRecord(IntIDType tradeID, Order* op, VolumeType volume, PriceType price);
	//插入成交流
	ReturnType InsertIntoTradingFlow(TradingRecord * rec);
	//插入买订单簿
	ReturnType InsertIntoOrderHashQueue(Order * op);
	//插入卖订单簿
	//ReturnType InsertAskOrder(Order * op);
	//从订单簿中删除订单
	Order* RemoveFromOrderHashQueue(Order* op);
	//撮合算法
	ReturnType OrderMatching(Order * op);
	//更新最新价
	VoidType SetLastPrice(PriceType lastPrice);
	//Todo 撤销订单
	ReturnType CancelOrderAction(Instruction * inst);
	//根据OrderID查找订单
	Order* GetOrderByID(IntIDType id);
	//ToDo 记录委托流
	//ToDo 记录成交流
};



#endif /* ORDERBOOK_H_ */
