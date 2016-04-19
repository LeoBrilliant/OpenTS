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
#include "Queue.h"

class OrderBook
{
public:
	OrderBook();

private:
	//合约信息
	Instrument * IntrumentInfo;
	//订单档位哈希队列

	//订单档位优先队列
	//TODO先不考虑行情
	//订单队列

	Queue OrderQueue;
};



#endif /* ORDERBOOK_H_ */
