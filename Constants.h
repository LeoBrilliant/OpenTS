/*
 * Constants.h
 *
 *  Created on: 2016��4��25��
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
	INVALIDVOLUME = -1,
	INVALIDPRICE = -1,

	STARTOFINTID = 1,
	INVALIDINTID = 0,

	//Pointer
	NULLPOINTER = 0,

	//Execution Result
	SUCCESS = 0,
	FAILURE = -1
} Constants;

const char InvalidString[] = "INVALIDSTRING";

}

#endif /* CONSTANTS_H_ */
