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


	char * sql = new char[2048];
	memset(sql, 0, 2048);
	sprintf(sql, "insert into t_order"
			"(ClientID, InstructionType, InstrumentID, Direction, OffsetFlag, OrderPrice,"
			"Volume, OrderID, LocalOrderID, VolumeLeft, OrderStatus)"
			"Values("
			"%d, %d,\'%s\', \'%d\', \'%d\',"
			"%.3f, %d, %d, %d, %d,"
			"\'%d\')",
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
/*
	sprintf(sql, "INSERT INTO t_order("
			"ClientID"
			//", InstructionType, "
			//"Direction, "
			//"OffsetFlag, "
			//"OrderPrice, "
			//"Volume, "
			//"OrderID, "
			//"LocalOrderID, "
			//"OrderTimePoint, "
			//"VolumeLeft, "
			//"CancelTimePoint, "
			//"OrderStatus"
			") VALUES ("
			"1"
			//", %d, \'%d\', \'%d\',"
			//"%.3f, %d, %d, %d, %d,"
			//"\'%d\') ;",
			")"
			//1
			//(op->GetClientID())
			//(int)(op->GetInstType()),
			//(op->GetInstrumentID().c_str()),
			//(int)op->GetDirection(),
			//(int)op->GetOffsetFlag(),
			//op->GetOrderPrice(),
			//op->GetVolume(),
			//op->GetOrderID(),
			//op->GetLocalOrderID(),
			//op->GetVolumeLeft(),
			//(int)op->GetOrderStatus()
	);*/

//	sprintf(sql, "insert into t_order(clientid) values (1)");
//	strcpy(sql, "insert into t_order(clientid) values (1)");
//	int q = strcmp(sql, "Insert into t_order(ClientID, InstructionType, InstrumentID, Direction, OffsetFlag, OrderPrice,Volume, OrderID, LocalOrderID, VolumeLeft, OrderStatus)Values(10000001, 1,'TestInstrument', '1', '1',101.340000, 32, 1, 1, 32,'1')");

	return sql;

}

char * GetUpdateOrderSQL(Order * op)
{
	char * sql = new char[2048];
	memset(sql, 0, 2048);
	//UPDATE t_order SET ClientID=[value-1],InstructionType=[value-2],InstrumentID=[value-3],Direction=[value-4],
	//OffsetFlag=[value-5],OrderPrice=[value-6],Volume=[value-7],OrderID=[value-8],LocalOrderID=[value-9],
	//OrderTimePoint=[value-10],VolumeLeft=[value-11],CancelTimePoint=[value-12],OrderStatus=[value-13] WHERE 1
	sprintf(sql, "UPDATE t_order "
			"SET "
			//"ClientID=[value-1],"
			//"InstructionType=[value-2],"
			//"InstrumentID=[value-3],"
			//"Direction=[value-4],"
			//"OffsetFlag=[value-5],"
			//"OrderPrice=[value-6],"
			//"Volume=[value-7],"
			//"OrderID=[value-8],"
			//"LocalOrderID=[value-9],"
			//"OrderTimePoint=[value-10],"
			"VolumeLeft=%d," //"[value-11],"
			//"CancelTimePoint=[value-12],"
			"OrderStatus=%d " // "[value-13] "
			"WHERE OrderID=%d"
			,
			op->GetVolumeLeft(),
			(int)op->GetOrderStatus(),
			op->GetOrderID()
	);

	return sql;
}
