/*
 * Serialization.h
 *
 *  Created on: 2016Äê5ÔÂ21ÈÕ
 *      Author: LeoBrilliant
 */

#ifndef SERIALIZATION_H_
#define SERIALIZATION_H_

#include <json/json.h>
#include "Instruction.h"

using namespace Json;

StringType SerializeInstruction(Instruction * inst);

Instruction * DeserialInstruction(StringType strInst);

#endif /* SERIALIZATION_H_ */
