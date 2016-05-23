/*
 * DBAccessTest.cpp
 *
 *  Created on: 2016Äê5ÔÂ23ÈÕ
 *      Author: user
 */

#include "DBAccessTest.h"

DBAccessTest::DBAccessTest() {
}

DBAccessTest::~DBAccessTest() {
}

void DBAccessTest::TestSuite() {
	this->ConstructorTest();

	UnitTestStats();

}

void DBAccessTest::ConstructorTest() {
	ProgramMessage::Debug(__FUNCTION__);
	{
		ProgramMessage::Debug<int>(IncCaseCount());
		MYSQL * conn_ptr = NULL;
		MYSQL_RES * res;
		MYSQL_ROW row;
		conn_ptr = InitializeMySQLClient(conn_ptr);
		assert(conn_ptr != NULL);
		conn_ptr = ConnectMySQLServer(conn_ptr);
		assert(conn_ptr != NULL);

		if(mysql_query(conn_ptr, "select * from t_test"))
		{
			fprintf(stderr, "call mysql_query failed...%d: %s", errno, strerror(errno));
		}

		res = mysql_use_result(conn_ptr);

		while((row = mysql_fetch_row(res)))
		{
			fprintf(stdout, "%s\t%s\t%s\n", row[0], row[1], row[2]);
		}

		mysql_free_result(res);
		mysql_close(conn_ptr);

		IncCasePassed();
		ProgramMessage::Debug("Passed");

		ProgramMessage::Debug<int>(IncCaseCount());
		conn_ptr = NULL;
		conn_ptr = InitializeMySQLClient(conn_ptr);
		assert(conn_ptr != NULL);
		conn_ptr = ConnectMySQLServer(conn_ptr);
		assert(conn_ptr != NULL);

		if (!mysql_set_character_set(conn_ptr, "utf8"))
		{
		    printf("New client character set: %s\n",
		           mysql_character_set_name(conn_ptr));
		}

		Order * op = GenOrder();

		char * sql = GetInsertOrderSQL(op);

		//int i = strlen(sql);

		//sql = "select * from t_test";

		//sql = "insert into t_order(clientid) values (1)";
		//sql = "Insert into t_order (ClientID, InstructionType, InstrumentID, Direction, OffsetFlag, OrderPrice, Volume, OrderID, LocalOrderID, VolumeLeft,  OrderStatus) Values (10000001, 1, 'TestInstrument', '1', '1', 101.340000, 32, 1, 1, 32, '1' )";
/*		sql = "Insert into t_order (ClientID, InstructionType, InstrumentID, Direction, OffsetFlag, OrderPrice, "
				"Volume, OrderID, LocalOrderID, VolumeLeft,  OrderStatus) Values (10000001, 1, 'TestInstrument', '1', '1', 101.340000, 32, 1, 1, 32, '1' )";
		sql = "Insert into t_order (ClientID, InstructionType, InstrumentID, Direction, OffsetFlag, OrderPrice, "
				"Volume, OrderID, LocalOrderID, VolumeLeft,  OrderStatus"
				") "
				"Values "
				"("
				"10000001, 1, 'TestInstrument', '1', '1', 101.3400000,"
				" 32, 1, 1, 32, '1'"
				")";*/

		ProgramMessage::Debug(sql);

		if(mysql_query(conn_ptr, sql))
		{
			fprintf(stderr, "call mysql_query failed...%d: %s", errno, mysql_error(conn_ptr));
		}

		//res = mysql_use_result(conn_ptr);

		//while((row = mysql_fetch_row(res)))
		{
			//fprintf(stdout, "%s\t%s\t%s\n", row[0], row[1], row[2]);
		}

		//mysql_free_result(res);
		mysql_close(conn_ptr);

		delete op;
		delete sql;

		IncCasePassed();
		ProgramMessage::Debug("Passed");

	}
}

