/*
 * Serialization.cpp
 *
 *  Created on: 2016��5��22��
 *      Author: LeoBrilliant
 */

#include "Serialization.h"


StringType SerializeInstruction(Instruction * inst)
{
	Value jsonInst;
	AssembleInstructionValue(inst, jsonInst);
	//FastWriter fast_writer;
	StyledWriter fast_writer;
	StringType strInst = fast_writer.write(jsonInst);
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
	StringType strOrder = fast_writer.write(jsonOrder);

	return strOrder;
}

Value & AssembleOrderValue(Order * o, Value & jsonOrder)
{
	Value jsonInst;
	AssembleInstructionValue((Instruction*) o, jsonInst);
//	Value jsonOrder;
	jsonOrder["Instruction"] = jsonInst;
	/*
	//��Լ��
	StringType InstrumentID;
	//����
	DirectionType Direction;
	//��ƽ��־
	OffsetType OffsetFlag;
	//�۸�
	PriceType OrderPrice;
	//����
	VolumeType Volume;
	//�������
	IntIDType OrderID;
	//���ر������
	IntIDType LocalOrderID;
	//������
	//����ʱ��
	RightTimePoint OrderTimePoint;
	//ʣ������
	VolumeType VolumeLeft;
	//����ʱ��
	RightTimePoint CancelTimePoint;
	//����״̬
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
	reader.parse(strOrder.c_str(), jsonOrder);
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
			(StringType)(jsonOrder["InstrumentID"].asString()),
			(DirectionType)(jsonOrder["Direction"].asInt()),
			(OffsetType)(jsonOrder["OffsetFlag"].asInt()),
			(PriceType)(jsonOrder["OrderPrice"].asDouble()),
			(VolumeType)(jsonOrder["Volume"].asInt()),
			(IntIDType)(jsonOrder["LocalOrderID"].asInt())
			);
	return ip;

}
