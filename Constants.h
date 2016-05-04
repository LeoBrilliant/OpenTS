/*
 * Constants.h
 *
 *  Created on: 2016Äê4ÔÂ25ÈÕ
 *      Author: user
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include "Types.h"

namespace constants
{
typedef enum
{
	// InstrumentID
	INVALIDINSTRUMENTID = -1,

	//Volume
	INVALIDVOLUME = -1,
	EMPTYVOLUME = 0,

	//Price
	INVALIDPRICE = -1,

	//IntTypeID
	STARTOFINTID = 1,
	INVALIDINTID = 0,

	//Pointer
	NULLPOINTER = 0,

	//Execution Result
	SUCCESS = 0,
	FAILURE = -1,

	//Length
	ZERO = 0
} Constants;

const char InvalidString[] = "INVALIDSTRING";

}

#endif /* CONSTANTS_H_ */
