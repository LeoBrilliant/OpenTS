/*
 * TradingRecord.cpp
 *
 *  Created on: 2016Äê5ÔÂ2ÈÕ
 *      Author: LeoBrilliant
 */

#include "TradingRecord.h"

IntIDType TradingRecord::RecordCounter = Constants::STARTOFINTID;

TradingRecord::TradingRecord() :
	RecID(Constants::INVALIDINTID),
	ClientID(Constants::INVALIDINTID),
	RecType(RecordType::UNKNOWNRECORD),
	Direction(DirectionType::UNKNOWNDIRECTION),
	OffsetFlag(OffsetType::UNKNOWNOFFSET),
	Price(Constants::INVALIDPRICE),
	Volume(Constants::INVALIDVOLUME),
	OrderID(Constants::INVALIDINTID),
	LocalOrderID(Constants::INVALIDINTID)
{
}

TradingRecord::TradingRecord(IntIDType recID,
		IntIDType clientID,
		RecordType recType,
		StringType instID,
		DirectionType direction,
		OffsetType offset,
		PriceType price,
		VolumeType volume,
		IntIDType orderID,
		IntIDType localOrderID) :
		RecID(recID),
		ClientID(clientID),
		RecType(recType),
		InstrumentID(instID),
		Direction(direction),
		OffsetFlag(offset),
		Price(price),
		Volume(volume),
		OrderID(orderID),
		LocalOrderID(localOrderID)
{
}

TradingRecord::~TradingRecord() {
}

IntIDType TradingRecord::GetRecordCounter() {
	return RecordCounter;
}

IntIDType TradingRecord::IncRecordCounter() {
	return RecordCounter++;
}

IntIDType TradingRecord::GetClientID() const {
	return this->ClientID;
}

VoidType TradingRecord::SetClientID(IntIDType clientID) {
	this->ClientID = clientID;
}

const RightTimePoint& TradingRecord::GetInsertTime() const {
	return this->InsertTime;
}

VoidType TradingRecord::SetInsertTime(RightTimePoint& insertTime) {
	this->InsertTime = insertTime;
}

VoidType TradingRecord::SetInsertTime() {
	this->InsertTime = RightTimePoint::Now();
}

IntIDType TradingRecord::GetRecordID() const {
	return this->RecID;
}

VoidType TradingRecord::SetRecordID(int recID) {
	this->RecID = recID;
}

RecordType TradingRecord::GetRecType() const {
	return this->RecType;
}

DirectionType TradingRecord::GetDirection() const {
	return Direction;
}

VoidType TradingRecord::SetDirection(DirectionType direction) {
	Direction = direction;
}

IntIDType TradingRecord::GetLocalOrderID() const {
	return LocalOrderID;
}

VoidType TradingRecord::SetLocalOrderID(IntIDType localOrderID) {
	LocalOrderID = localOrderID;
}

OffsetType TradingRecord::GetOffsetFlag() const {
	return OffsetFlag;
}

VoidType TradingRecord::SetOffsetFlag(OffsetType offsetFlag) {
	OffsetFlag = offsetFlag;
}

IntIDType TradingRecord::GetOrderID() const {
	return OrderID;
}

VoidType TradingRecord::SetOrderID(IntIDType orderID) {
	OrderID = orderID;
}

PriceType TradingRecord::GetTradingPrice() const {
	return Price;
}

VoidType TradingRecord::SetTradingPrice(PriceType tradingPrice) {
	Price = tradingPrice;
}

VolumeType TradingRecord::GetVolume() const {
	return Volume;
}

VoidType TradingRecord::SetVolume(VolumeType volume) {
	Volume = volume;
}
