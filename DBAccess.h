/*
 * DBAccess.h
 *
 *  Created on: 2016Äê5ÔÂ23ÈÕ
 *      Author: user
 */

#ifndef DBACCESS_H_
#define DBACCESS_H_

#include <string>
#include <stdio.h>
#include "Order.h"

using namespace std;

char * GetInsertOrderSQL(Order * op);


#endif /* DBACCESS_H_ */
