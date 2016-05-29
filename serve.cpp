/*
 * serve.cpp
 *
 *  Created on: 2016Äê5ÔÂ28ÈÕ
 *      Author: LeoBrilliant
 */

#include "FrontServer.h"
#include "Serialization.h"
#include "Infrastructure.h"

using namespace std;

void serve(int sockfd)
{
	int clfd;
	// status;
	//pid_t pid;
	struct pollfd * pollfds;
	int clientcounter = 0;
	struct sockaddr claddr;
	struct sockaddr_in * paddrin;
	socklen_t claddrlen;
	mutex sockctl;

	bool readerThreadCreated = false;
	//bool writerThreadCreated = false;

	char ip[20];
	const char * cp;

	if((pollfds = (pollfd *) malloc(1024 * sizeof(struct pollfd))) == NULL)
	{
		perror("malloc error");
	}

	pollfds[0].fd = sockfd;
	pollfds[0].events = POLLIN | POLLOUT;

	for(int i = 1; i < 1024; ++i)
	{
		pollfds[i].fd = -1;
	}

	static Infrastructure infra;
	infra.InitializeInfrastructureAction();

	while(true)
	{
//		reader(pollfds, &clientcounter, &sockctl);

		int ret = poll(pollfds, clientcounter + 1, -1);
		int * counter = &clientcounter;
		struct pollfd clifd;
		int nread;
		char buf[4096];

		if(ret < 0)
		{
			perror("poll failed");
			break;
		}

		if( ret == 0)
			continue;

		if(pollfds[0].revents & POLLIN)
		{
			claddrlen = sizeof(claddr);
			memset(&claddr, 0, claddrlen);
			clfd = accept(sockfd, &claddr, &claddrlen);
			if(clfd < 0)
			{
				syslog(LOG_ERR, "ruptimed: accept error: %s", strerror(errno));
				exit(1);
			}

			paddrin = (struct sockaddr_in *)(&claddr);
			cp = inet_ntop((int)paddrin->sin_family, (void*)&paddrin->sin_addr, (char*)ip, INET_ADDRSTRLEN);
			printf("client connected(%s: %d), %s\n", ip, paddrin->sin_port, cp);
			fflush(stdout);

			sockctl.lock();
			clientcounter++;
			pollfds[clientcounter].fd=(clfd);
			pollfds[clientcounter].events = POLLIN;
			sockctl.unlock();

			if(!readerThreadCreated || clientcounter == 0)
			{
				//thread (reader, pollfds+1, ref(clientcounter), &sockctl).detach();
				readerThreadCreated = true;
			}
		}

		for(int i = 1; i <= (*counter); ++i)
		{
			clifd = pollfds[i];
			if(clifd.revents & POLLHUP)
			{
				goto hungup;
			}
			else if(clifd.revents & POLLIN)
			{
				if((nread = read(clifd.fd, buf, MAXLINE)) < 0)
				{
					printf("read error on fd %d", pollfds[i].fd);
				}
				else if(nread == 0)
				{
hungup:
					printf("closed: fd %d", clifd.fd);
					sockctl.lock();
					for(int j = i; j < (*counter); ++j)
					{
						pollfds[j] = pollfds[j + 1];
					}
					(*counter)--;
					sockctl.unlock();
					close(clifd.fd);
				}
				else
				{
					//request(buf, nread, clifd, client[i].uid);
					//printf("%s\n", buf);
					fflush(stdout);
					Json::Reader jsonReader;
					Json::Value jsonValue;
					bool parseResult = jsonReader.parse(buf, jsonValue);
					if(parseResult)
					{
						Json::Value inst = jsonValue["Instruction"];
						if(inst["InstType"].asInt() == InstructionType::LIMITPRICEORDER)
						{
							printf("LimitPriceOrderReceived\n");

							Instruction * op = DeserializeOrder(jsonValue);

							infra.AcceptInstruction(*op);
						}
					}
				}
			}
		}

/*		//Reader
		//Writer
		if((pid = fork()) < 0)
		{
			syslog(LOG_ERR, "ruptimed: fork error: %s", strerror(errno));
			exit(1);
		}
		else if(pid == 0) //child
		{
			if(dup2(clfd, STDOUT_FILENO) != STDOUT_FILENO ||
					dup2(clfd, STDERR_FILENO) != STDERR_FILENO)
			{
				syslog(LOG_ERR, "ruptimed: unexpected error");
				exit(1);
			}
			close(clfd);
			execl("/usr/bin/date", "uptime", (char*)0);
			syslog(LOG_ERR, "ruptimed: unexpected return from exec: %s",
					strerror(errno));
		}
		else //parent
		{
			close(clfd);
			waitpid(pid, &status, 0);
		}*/
	}
}


