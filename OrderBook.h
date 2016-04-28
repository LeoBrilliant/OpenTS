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
#include "Types.h"

class OrderBook
{
public:
	OrderBook();

	~OrderBook();

private:
	//合约信息
	Instrument * IntrumentInfo;
	//订单档位哈希队列
	ChainHashTable<Order*, string> BidOrderHashQueue;
	ChainHashTable<Order*, string> AskOrderHashQueue;

	//订单档位优先队列
	//TODO先不考虑行情
	//订单队列
	Queue<Order*> OrderFlow;

	//最新价
	PriceType LastPrice;

public:
	//插入订单队列
	ReturnType InsertOrderFlow(Order & o);
	//插入买订单簿
	ReturnType InsertOrderHashQueue(Order * op);
	//插入卖订单簿
	//ReturnType InsertAskOrder(Order * op);
	//获取最优一档订单
	Order * GetBestPriceOrder(DirectionType direction);
	//Todo 撤销订单
	//撮合算法
	ReturnType OrderMatching(AuctionType auction);
	//ToDo 记录委托流
	//ToDo 记录成交流
};



#endif /* ORDERBOOK_H_ */
