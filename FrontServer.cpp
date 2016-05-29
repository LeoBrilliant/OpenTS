/*
 * main.cpp
 *
 *  Created on: 2016Äê5ÔÂ8ÈÕ
 *      Author: LeoBrilliant
 */

#include "FrontServer.h"
#include <string.h>

using namespace std;

int FrontServer()
{
	int sockfd;
	struct sockaddr_in server_addr;
	char server_ip[] = "192.168.31.134";

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	inet_aton(server_ip, &server_addr.sin_addr);
	server_addr.sin_port = htons(SERVER_PORT);

	if((sockfd = initserver(SOCK_STREAM, (sockaddr*)&server_addr, sizeof(server_addr), QLEN)) >= 0)
	{
		serve(sockfd);
		exit(0);
	}

	return 0;
}
