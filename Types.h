/*
 * Types.h
 *
 *  Created on: 2016Äê4ÔÂ26ÈÕ
 *      Author: LeoBrilliant
 */

#ifndef TYPES_H_
#define TYPES_H_

#include <string>
typedef double PriceType;
typedef unsigned int VolumeType;
typedef unsigned int IntIDType;
typedef int ReturnType;
typedef std::string StringType;

typedef enum
{
	UNKNOWNINSTRUCTION=0,
	LIMITPRICEORDER=1,
	MARKETPRICEORDER=2,
	CANCEL=3
} InstructionType;

typedef enum
{
	UNKNOWNDIRECTION=0,
	BUY=1,
	SELL=2
} DirectionType;

typedef enum
{
	UNKNOWNOFFSET=0,
	OPEN=1,
	OFFSET=2
} OffsetType;

typedef enum
{
	UNKNOWNSTATUS=-1,
	INIT=1,
	INORDERBOOK=2,
	PARTLYTRADED=3,
	ALLTRADED=4,
	CANCELLED=5
} OrderStatusType;

typedef enum
{
	UNKNOWNAUCTION = 0,
	CALLAUCTION = 1,
	CONTINUOUSAUCTION = 2,
	BLOCKTRADING = 3
}AuctionType;

#endif /* TYPES_H_ */
