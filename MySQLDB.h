/*
 * MySQLDB.h
 *
 *  Created on: 2016Äê5ÔÂ23ÈÕ
 *      Author: user
 */

#ifndef MYSQLDB_H_
#define MYSQLDB_H_

#include <mysql.h>

#include <iostream>

using namespace std;

#include <mysql.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

MYSQL * InitializeMySQLClient(MYSQL * conn);

MYSQL * ConnectMySQLServer(MYSQL *conn);

int MySQLQuery(MYSQL * conn, const char * sql);

void CloseMySQLConnnection(MYSQL * conn);


/*void MySqlTest()
{
	MYSQL * conn_ptr = NULL;
	MYSQL_RES * res;
	MYSQL_ROW row;

	char * host = "127.0.0.1";
	char * user = "root";
	char * password = "";
	char * db = "mysql";
	unsigned int port = 3306;
	char * unix_socket = NULL;
	unsigned long client_flag = 0;

	conn_ptr = mysql_init(conn_ptr);
	if(!conn_ptr)
	{
		fprintf(stderr, "init mysql failed\n");
		fprintf(stderr, "Connection failed....%d: %s\n", errno, strerror(errno));
		exit(-1);
	}

	conn_ptr = mysql_real_connect(conn_ptr, host, user, password, db, port, unix_socket, client_flag);
	if(conn_ptr)
	{
		printf("Connection Success...\n");
	}
	else
	{
		fprintf(stderr, "Connection failed....%d: %s\n", errno, strerror(errno));
	}

	if(mysql_query(conn_ptr, "select host, user from user"))
	{
		fprintf(stderr, "call mysql_query failed...%d: %s", errno, strerror(errno));
	}

	res = mysql_use_result(conn_ptr);

	while((row = mysql_fetch_row(res)))
	{
		fprintf(stdout, "%s\t%s\n", row[0], row[1]);
	}

	mysql_free_result(res);
	mysql_close(conn_ptr);

	return;
}*/




#endif /* MYSQLDB_H_ */
