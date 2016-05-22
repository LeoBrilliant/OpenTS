/*
 * Order.h
 *
 *  Created on: 2016年4月11日
 *      Author: user
 */

#ifndef ORDER_H_
#define ORDER_H_

#include <String>

#include "RightTimePoint.h"
#include "Instruction.h"
#include "ProgramMessage.h"

using namespace std;

class Order : public Instruction
{
public:
	Order();
	Order(IntIDType clientID,
			InstructionType instType,
			string instID,
			DirectionType direction,
			OffsetType offset,
			PriceType price,
			VolumeType volume,
			IntIDType localOrderID);
	~Order();

private:
	//客户ID
	//string ClientID;
	//合约号
	StringType InstrumentID;
	//指令类型
	//string OrderType;
	//方向
	DirectionType Direction;
	//开平标志
	OffsetType OffsetFlag;
	//价格
	PriceType OrderPrice;
	//手数
	VolumeType Volume;
	//报单编号
	IntIDType OrderID;
	//本地报单编号
	IntIDType LocalOrderID;
	//交易日
	//报单时间
	RightTimePoint OrderTimePoint;
	//剩余手数
	VolumeType VolumeLeft;
	//撤单时间
	RightTimePoint CancelTimePoint;
	//订单状态
	OrderStatusType OrderStatus;

public:
	const RightTimePoint& GetCancelTimePoint() const;
	void SetCancelTimePoint(RightTimePoint& cancelTimePoint);
	void SetCancelTimePoint();
	DirectionType GetDirection() const;
	void SetDirection(DirectionType direction);
	const string& GetInstrumentID() const;
	void SetInstrumentID(string& intrumentID);
	IntIDType GetLocalOrderID() const;
	void SetLocalOrderID(IntIDType localOrderID);
	OffsetType GetOffsetFlag() const;
	void SetOffsetFlag(OffsetType offsetFlag);
	IntIDType GetOrderID() const;
	void SetOrderID(IntIDType orderID);
	PriceType GetOrderPrice() const;
	void SetOrderPrice(PriceType orderPrice);
	OrderStatusType GetOrderStatus() const;
	void SetOrderStatus(OrderStatusType orderStatus);
	const RightTimePoint& GetOrderTimePoint() const;
	void SetOrderTimePoint(RightTimePoint& orderTimePoint);
	VolumeType GetVolume() const;
	void SetVolume(VolumeType volume);
	VolumeType GetVolumeLeft() const;
	void SetVolumeLeft(VolumeType volumeLeft);
};



#endif /* ORDER_H_ */
