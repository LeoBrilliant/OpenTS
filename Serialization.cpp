/*
 * Serialization.cpp
 *
 *  Created on: 2016年5月22日
 *      Author: LeoBrilliant
 */

#include "Serialization.h"


StringType SerializeInstruction(Instruction * inst)
{
	Value jsonInst;
	AssembleInstructionValue(inst, jsonInst);
	//FastWriter fast_writer;
	StyledWriter fast_writer;
	string strInst = fast_writer.write(jsonInst);
	return strInst;
}

Value & AssembleInstructionValue(Instruction * inst, Value & jsonInst)
{
//	Value jsonInst;
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

	return jsonInst;
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

StringType SerializeOrder(Order * o)
{
	Value jsonOrder;
	AssembleOrderValue(o, jsonOrder);
	//FastWriter fast_writer;
	StyledWriter fast_writer;
	string strOrder = fast_writer.write(jsonOrder);

	return strOrder;
}

Value & AssembleOrderValue(Order * o, Value & jsonOrder)
{
	Value jsonInst;
	AssembleInstructionValue((Instruction*) o, jsonInst);
//	Value jsonOrder;
	jsonOrder["Instruction"] = jsonInst;
	/*
	//合约号
	StringType InstrumentID;
	//方向
	DirectionType Direction;
	//开平标志
	OffsetType OffsetFlag;
	//价格
	PriceType OrderPrice;
	//手数
	VolumeType Volume;
	//报单编号
	IntIDType OrderID;
	//本地报单编号
	IntIDType LocalOrderID;
	//交易日
	//报单时间
	RightTimePoint OrderTimePoint;
	//剩余手数
	VolumeType VolumeLeft;
	//撤单时间
	RightTimePoint CancelTimePoint;
	//订单状态
	OrderStatusType OrderStatus;
	 */
	jsonOrder["InstrumentID"] = o->GetInstrumentID();
	jsonOrder["Direction"] = o->GetDirection();
	jsonOrder["OffsetFlag"] = o->GetOffsetFlag();
	jsonOrder["OrderPrice"] = o->GetOrderPrice();
	jsonOrder["Volume"] = o->GetVolume();
	jsonOrder["OrderID"] = o->GetOrderID();
	jsonOrder["LocalOrderID"] = o->GetLocalOrderID();
//	jsonOrder["OrderTimePoint"] = o->GetInstrumentID();
	jsonOrder["VolumeLeft"] = o->GetVolumeLeft();
//	jsonOrder["CancelTimePoint"] = o->GetInstrumentID();
	jsonOrder["OrderStatus"] = o->GetOrderStatus();
//	jsonOrder["InstrumentID"] = o->GetInstrumentID();
	return jsonOrder;
}

Order * DeserializeOrder(StringType strOrder)
{
	Reader reader;
	Value jsonOrder;
	reader.parse(strOrder, jsonOrder);
/*	Order(IntIDType clientID,
			InstructionType instType,
			string & instID,
			DirectionType direction,
			OffsetType offset,
			PriceType price,
			VolumeType volume,
			IntIDType localOrderID);
*/
	Value jsonInst = jsonOrder["Instruction"];
	Order * ip = new Order(
			(IntIDType)(jsonInst["ClientID"].asInt()),
			(InstructionType)(jsonInst["InstType"].asInt()),
			(string)(jsonOrder["InstrumentID"].asString()),
			(DirectionType)(jsonOrder["Direction"].asInt()),
			(OffsetType)(jsonOrder["OffsetFlag"].asInt()),
			(PriceType)(jsonOrder["OrderPrice"].asDouble()),
			(VolumeType)(jsonOrder["Volume"].asInt()),
			(IntIDType)(jsonOrder["LocalOrderID"].asInt())
			);
	return ip;

}
