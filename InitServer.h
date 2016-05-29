/*
 * InitServer.h
 *
 *  Created on: 2016��5��8��
 *      Author: LeoBrilliant
 */

#ifndef INITSERVER_H_
#define INITSERVER_H_

#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

int initserver(int type, const struct sockaddr * addr, socklen_t alen, int qlen)
{
	int fd, err;
	int reuse = 1;
	if((fd = socket(addr->sa_family, type, 0)) < 0)
		return -1;
	if(setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(int)) < 0)
	{
		err = errno;
		goto errout;
	}
	if(bind(fd, addr, alen) < 0)
	{
		err = errno;
		goto errout;
	}

	if(type == SOCK_STREAM || type == SOCK_SEQPACKET)
	{
		if(listen(fd, qlen) < 0)
		{
			err = errno;
			goto errout;
		}
	}
	return fd;
errout:
	close(fd);
	errno = err;
	return -1;
}



#endif /* INITSERVER_H_ */
