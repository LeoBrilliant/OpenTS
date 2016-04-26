/*
 * Order.cpp
 *
 *  Created on: 2016Äê4ÔÂ26ÈÕ
 *      Author: LeoBrilliant
 */

#include "Order.h"

Order::Order() :
	Direction(DirectionType::UNKNOWNDIRECTION),
	OffsetFlag(OffsetType::UNKNOWNOFFSET),
	OrderPrice(Constants::INVALIDPRICE),
	Volume(Constants::INVALIDVOLUME),
	OrderID(Constants::INVALIDINTID),
	LocalOrderID(Constants::INVALIDINTID),
	VolumeLeft(Constants::INVALIDVOLUME),
	OrderStatus(OrderStatusType::UNKNOWNSTATUS)
{
}

Order::Order(IntIDType clientID,
		InstructionType instType,
		string& instID,
		DirectionType direction,
		OffsetType offset,
		PriceType price,
		VolumeType volume,
		IntIDType localOrderID) :
			Instruction(clientID, instType),
			InstrumentID(instID),
			Direction(direction),
			OffsetFlag(offset),
			OrderPrice(price),
			Volume(volume),
			OrderID(Constants::INVALIDINTID),
			LocalOrderID(localOrderID),
			VolumeLeft(Volume),
			OrderStatus(OrderStatusType::INIT)
{
	//OrderID = Instruction::GetInstructionID();
	OrderID = this->GetInstructionId();
}

Order::~Order() {
}

const RightTimePoint& Order::GetCancelTimePoint() const {
	return CancelTimePoint;
}

void Order::SetCancelTimePoint(RightTimePoint& cancelTimePoint) {
	CancelTimePoint = cancelTimePoint;
}

DirectionType Order::GetDirection() const {
	return Direction;
}

void Order::SetDirection(DirectionType direction) {
	Direction = direction;
}

const string& Order::GetInstrumentId() const {
	return InstrumentID;
}

void Order::SetInstrumentId(string& instrumentId) {
	InstrumentID = instrumentId;
}

IntIDType Order::GetLocalOrderId() const {
	return LocalOrderID;
}

void Order::SetLocalOrderId(IntIDType localOrderId) {
	LocalOrderID = localOrderId;
}

OffsetType Order::GetOffsetFlag() const {
	return OffsetFlag;
}

void Order::SetOffsetFlag(OffsetType offsetFlag) {
	OffsetFlag = offsetFlag;
}

IntIDType Order::GetOrderId() const {
	return OrderID;
}

void Order::SetOrderId(IntIDType orderId) {
	OrderID = orderId;
}

PriceType Order::GetOrderPrice() const {
	return OrderPrice;
}

void Order::SetOrderPrice(PriceType orderPrice) {
	OrderPrice = orderPrice;
}

OrderStatusType Order::GetOrderStatus() const {
	return OrderStatus;
}

void Order::SetOrderStatus(OrderStatusType orderStatus) {
	OrderStatus = orderStatus;
}

const RightTimePoint& Order::GetOrderTimePoint() const {
	return OrderTimePoint;
}

void Order::SetOrderTimePoint(RightTimePoint& orderTimePoint) {
	OrderTimePoint = orderTimePoint;
}

VolumeType Order::GetVolume() const {
	return Volume;
}

void Order::SetVolume(VolumeType volume) {
	Volume = volume;
}

VolumeType Order::GetVolumeLeft() const {
	return VolumeLeft;
}

void Order::SetVolumeLeft(VolumeType volumeLeft) {
	VolumeLeft = volumeLeft;
}
