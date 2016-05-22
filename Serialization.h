/*
 * Serialization.h
 *
 *  Created on: 2016��5��21��
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

#endif /* SERIALIZATION_H_ */
