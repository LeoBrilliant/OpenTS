/*
 * MySQLDB.cpp
 *
 *  Created on: 2016Äê5ÔÂ23ÈÕ
 *      Author: user
 */

#include "MySQLDB.h"

MYSQL * InitializeMySQLClient(MYSQL * conn)
{
	conn = mysql_init(conn);
	if(!conn)
	{
		fprintf(stderr, "init mysql failed\n");
		fprintf(stderr, "Connection failed....%d: %s\n", errno, strerror(errno));
	}
	return conn;
}

MYSQL * ConnectMySQLServer(MYSQL *conn)
{
	char * host = "127.0.0.1";
	char * user = "root";
	char * password = "";
	char * db = "test";
	unsigned int port = 3306;
	char * unix_socket = NULL;
	unsigned long client_flag = 0;

	conn = mysql_real_connect(conn, host, user, password, db, port, unix_socket, client_flag);
	if(conn)
	{
		printf("Connection Success...\n");
	}
	else
	{
		fprintf(stderr, "Connection failed....%d: %s\n", errno, strerror(errno));
	}

	return conn;
}

int MySQLQuery(MYSQL * conn, const char * sql)
{
	int ret = mysql_query(conn, sql);
	if (ret != 0)
	{
		const char *mysql_err = mysql_error(conn);
		fprintf(stderr, "Query Failed: %s\n",mysql_err);
	}
	return ret;
}

void CloseMySQLConnnection(MYSQL * conn)
{
	mysql_close(conn);
}



