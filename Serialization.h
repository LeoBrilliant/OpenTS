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
#include "Order.h"

using namespace Json;

StringType SerializeInstruction(Instruction * inst);

Value & AssembleInstructionValue(Instruction * inst, Value & jsonInst);

Instruction * DeserialInstruction(StringType strInst);

StringType SerializeOrder(Order * o);

Value & AssembleOrderValue(Order * o, Value & jsonOrder);

Order * DeserializeOrder(StringType strOrder);

Order * DeserializeOrder(Value & jsonOrder);

#endif /* SERIALIZATION_H_ */
