/*
 * UnitTestHeader.h
 *
 *  Created on: 2016Äê4ÔÂ24ÈÕ
 *      Author: LeoBrilliant
 */

#ifndef UNITTEST_UNITTESTFACTORY_H_
#define UNITTEST_UNITTESTFACTORY_H_


#include "ListTest.h"
#include "ChainHashTableTest.h"
#include "RightTimePointUnitTest.h"
#include "OrderChainHashTableTest.h"
#include "InfrastructureTest.h"
#include "ControlCenterTest.h"
#include "SerializationTest.h"
#include "DBAccessTest.h"
#include "FrontServerTest.h"

void FrontServerUT();
void DBAccessUT();
void SerializationUT();
void ControlCenterUT();

void InfrastructureUT();
void TimePointUT();
void ChainHashTableUT();
void ListUT();
void OrderChainHashTableUT();
void UnitTestEntrance();

#endif /* UNITTEST_UNITTESTFACTORY_H_ */
