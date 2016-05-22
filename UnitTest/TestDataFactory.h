/*
 * TestDataFactory.h
 *
 *  Created on: 2016��5��22��
 *      Author: LeoBrilliant
 */

#ifndef UNITTEST_TESTDATAFACTORY_H_
#define UNITTEST_TESTDATAFACTORY_H_

#include "../Instrument.h"
#include "../Order.h"
#include <vector>
#include <string>

IntIDType GenClientID();
StringType GenClientName();
Instrument * GenInstrument();
Order * GenOrder();

#endif /* UNITTEST_TESTDATAFACTORY_H_ */
