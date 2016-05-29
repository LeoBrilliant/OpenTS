/*
 * FrontServer.h
 *
 *  Created on: 2016Äê5ÔÂ28ÈÕ
 *      Author: LeoBrilliant
 */

#ifndef FRONTSERVER_H_
#define FRONTSERVER_H_

#include <netdb.h>
#include <errno.h>
#include <syslog.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <thread>
#include <mutex>
#include <poll.h>

#define QLEN 10

#ifndef HOST_NAME_MAX
#define HOST_NAME_MAX 256
#endif

#define SERVER_PORT 20000
#define MAXLINE 4096

int FrontServer();

int initserver(int type, const struct sockaddr * addr, socklen_t alen, int qlen);

void serve(int sockfd);

void reader(pollfd * pollfds, int & counter, std::mutex * sockctl);

void writer(int * sockfds, int * counter, std::mutex * sockctl);

#endif /* FRONTSERVER_H_ */
