/*
 * OrderBook.cpp
 *
 *  Created on: 2016Äê4ÔÂ28ÈÕ
 *      Author: LeoBrilliant
 */

#include "OrderBook.h"

OrderBook::OrderBook() :
	IntrumentInfo(NULL),
	LastPrice(Constants::INVALIDPRICE)
	//InstrumentInfo()
{
}

OrderBook::~OrderBook() {
}

ReturnType OrderBook::InsertOrderFlow(Order& o) {
	return Constants::SUCCESS;
}

ReturnType OrderBook::InsertOrderHashQueue(Order* op) {
	return Constants::SUCCESS;
}

Order* OrderBook::GetBestPriceOrder(DirectionType direction) {
	return NULL;
}

ReturnType OrderBook::OrderMatching(AuctionType auction) {
	return Constants::SUCCESS;
}
