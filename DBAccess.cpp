/*
 * DBAccess.cpp
 *
 *  Created on: 2016Äê5ÔÂ23ÈÕ
 *      Author: user
 */


#include "DBAccess.h"

char * GetInsertOrderSQL(Order * op)
{
/*	string sql;
	sql.append("Insert into t_order ");
	sql.append("(ClientID, InstructionType, InstrumentID, Direction, OffsetFlag, OrderPrice, "
			"Volume, OrderID, LocalOrderID, OrderTimePoint, VolumeLeft, CancelTimePoint, OrderStatus) ");

	sql.append("(ClientID, InstructionType, InstrumentID, Direction, OffsetFlag, OrderPrice, "
			"Volume, OrderID, LocalOrderID, VolumeLeft,  OrderStatus) ");
	sql.append("Values ");
	sql.append("(");
	sql.append(" " + op->GetClientID() + ", ");
	sql.append(" " + op->GetInstType() + ", ");
	sql.append(" " + op->GetInstrumentID() + ", ");
	sql.append(" " + op->GetDirection() + ", " );
	sql.append(" " + op->GetOffsetFlag() + ", " );
	sql.append(" " + op->GetOrderPrice() + ", " );
	sql.append(" " + op->GetVolume() + ", " );
	sql.append(" " + op->GetOrderID() + ", " );
	sql.append(" " + op->GetLocalOrderID() + ", " );
	//sql.append(" " + op->GetOrderTimePoint().GetMicroSeconds() + ", " );
	sql.append(" " + op->GetVolumeLeft() + ", " );
	//sql.append(" " + op->GetCancelTimePoint().GetMicroSeconds() + ", " );
	sql.append(" " + op->GetOrderStatus() + ", " );
	sql.append(")");

	return sql.c_str();*/


	char sql[2048];
	sprintf(sql, "Insert into t_order "
			"(ClientID, InstructionType, InstrumentID, Direction, OffsetFlag, OrderPrice, "
			"Volume, OrderID, LocalOrderID, VolumeLeft,  OrderStatus) "
			"Values ("
			"%d, %d, '%s', '%d', '%d', "
			"%f, %d, %d, %d, %d, "
			"'%d' )",
			(int)(op->GetClientID()),
			(int)(op->GetInstType()),
			(op->GetInstrumentID().c_str()),
			(int)op->GetDirection(),
			(int)op->GetOffsetFlag(),
			op->GetOrderPrice(),
			op->GetVolume(),
			op->GetOrderID(),
			op->GetLocalOrderID(),
			op->GetVolumeLeft(),
			(int)op->GetOrderStatus()
	);

	return sql;

}

