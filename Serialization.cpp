/*
 * Serialization.cpp
 *
 *  Created on: 2016Äê5ÔÂ22ÈÕ
 *      Author: LeoBrilliant
 */

#include "Serialization.h"


StringType SerializeInstruction(Instruction * inst)
{
	Value jsonInst;
/*
	IntIDType InstructionID;
	IntIDType ClientID;
	InstructionType InstType;
	RightTimePoint InsertTime;
	RightTimePoint ConfirmedTime;
	RightTimePoint UpdateTime;
 */
	jsonInst["InstructionID"] = inst->GetInstructionID();
	jsonInst["ClientID"] = inst->GetClientID();
	jsonInst["InstType"] = inst->GetInstType();
//	jsonInst["InsertTime"] = inst->GetInsertTime();
//	jsonInst["ConfirmedTime"] = inst->GetConfirmedTime();
//	jsonInst["UpdateTime"] = inst->GetUpdateTime();

	FastWriter fast_writer;
	string strInst = fast_writer.write(jsonInst);
	return strInst;
}

Instruction * DeserialInstruction(StringType strInst)
{
	Reader reader;
	Value jsonInst;
	reader.parse(strInst, jsonInst);
	Instruction * ip = new Instruction(
			jsonInst["ClientID"].asInt(),
			(InstructionType)(jsonInst["InstType"].asInt()),
			jsonInst["InstructionID"].asInt()
			);
	return ip;
}

