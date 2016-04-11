/*
 * Order.h
 *
 *  Created on: 2016年4月11日
 *      Author: user
 */

#ifndef ORDER_H_
#define ORDER_H_

#include <String>
#include <chrono>

using namespace std;
using namespace chrono;

class Order
{
public:
	Order();

private:
	//客户ID
	string ClientID;
	//合约号
	string IntrumentID;
	//指令类型
	string OrderType;
	//方向
	char Direction;
	//开平标志
	char OffsetFlag;
	//价格
	double OrderPrice;
	//手数
	int Volume;
	//报单编号
	string OrderID;
	//本地报单编号
	string LocalOrderID;
	//交易日
	//报单时间
	chrono OrderTimePoint;
};



#endif /* ORDER_H_ */
