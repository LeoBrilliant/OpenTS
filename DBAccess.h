/*
 * DBAccess.h
 *
 *  Created on: 2016��5��23��
 *      Author: user
 */

#ifndef DBACCESS_H_
#define DBACCESS_H_

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Order.h"

using namespace std;

char * GetInsertOrderSQL(Order * op);

char * GetUpdateOrderSQL(Order * op);


#endif /* DBACCESS_H_ */
