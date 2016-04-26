/*
 * Types.h
 *
 *  Created on: 2016Äê4ÔÂ26ÈÕ
 *      Author: LeoBrilliant
 */

#ifndef TYPES_H_
#define TYPES_H_

typedef double PriceType;
typedef unsigned int VolumeType;
typedef unsigned int IntIDType;

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

#endif /* TYPES_H_ */
