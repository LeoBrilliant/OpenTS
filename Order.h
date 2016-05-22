/*
 * Order.h
 *
 *  Created on: 2016��4��11��
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
	//�ͻ�ID
	//string ClientID;
	//��Լ��
	StringType InstrumentID;
	//ָ������
	//string OrderType;
	//����
	DirectionType Direction;
	//��ƽ��־
	OffsetType OffsetFlag;
	//�۸�
	PriceType OrderPrice;
	//����
	VolumeType Volume;
	//�������
	IntIDType OrderID;
	//���ر������
	IntIDType LocalOrderID;
	//������
	//����ʱ��
	RightTimePoint OrderTimePoint;
	//ʣ������
	VolumeType VolumeLeft;
	//����ʱ��
	RightTimePoint CancelTimePoint;
	//����״̬
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
