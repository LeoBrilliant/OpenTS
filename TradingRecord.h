/*
 * TradingRecord.h
 *
 *  Created on: 2016年5月2日
 *      Author: LeoBrilliant
 */

#ifndef TRADINGRECORD_H_
#define TRADINGRECORD_H_

#include "RightTimePoint.h"
#include "Constants.h"
#include "Types.h"

#include <string>

using namespace std;
using namespace constants;

class TradingRecord
{
public:
	TradingRecord();
	TradingRecord(IntIDType recID,
			IntIDType clientID,
			RecordType recType,
			StringType instID,
			DirectionType direction,
			OffsetType offset,
			PriceType price,
			VolumeType volume,
			IntIDType orderID,
			IntIDType localOrderID
			);
	~TradingRecord();

private:
	IntIDType RecID;
	IntIDType ClientID;
	RecordType RecType;
//	RightTimePoint ConfirmedTime;
//	RightTimePoint UpdateTime;

	//合约号
	StringType InstrumentID;
	//方向
	DirectionType Direction;
	//开平标志
	OffsetType OffsetFlag;
	//价格
	PriceType Price;
	//手数
	VolumeType Volume;
	//报单编号
	IntIDType OrderID;
	//本地报单编号
	IntIDType LocalOrderID;
	//交易日
	//成交时间
	//RightTimePoint OrderTimePoint;
	RightTimePoint InsertTime;

	static IntIDType RecordCounter;

public:
	static IntIDType GetRecordCounter();
	static IntIDType IncRecordCounter();

	IntIDType GetClientID() const;
	VoidType SetClientID(IntIDType clientID);

//	const RightTimePoint& GetConfirmedTime() const;
//	VoidType SetConfirmedTime(RightTimePoint& confirmedTime);
//	VoidType SetConfirmedTime();

	const RightTimePoint& GetInsertTime() const;
	VoidType SetInsertTime(RightTimePoint& insertTime);
	VoidType SetInsertTime();

	IntIDType GetRecordID() const;
	VoidType SetRecordID(int recID = RecordCounter);
	//VoidType SetInstructionID();

//	const RightTimePoint& GetUpdateTime() const;
//	VoidType SetUpdateTime(RightTimePoint& updateTime);
//	VoidType SetUpdateTime();
	RecordType GetRecType() const;
//	VoidType SetRecType(RecordType instType);
	DirectionType GetDirection() const;
	VoidType SetDirection(DirectionType direction);
	IntIDType GetLocalOrderID() const;
	VoidType SetLocalOrderID(IntIDType localOrderID);
	OffsetType GetOffsetFlag() const;
	VoidType SetOffsetFlag(OffsetType offsetFlag);
	IntIDType GetOrderID() const;
	VoidType SetOrderID(IntIDType orderID);
	PriceType GetTradingPrice() const;
	VoidType SetTradingPrice(PriceType tradingPrice);
	VolumeType GetVolume() const;
	VoidType SetVolume(VolumeType volume);
};




#endif /* TRADINGRECORD_H_ */
