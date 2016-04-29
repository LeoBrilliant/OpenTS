/*
 * OrderBook.cpp
 *
 *  Created on: 2016Äê4ÔÂ28ÈÕ
 *      Author: LeoBrilliant
 */

#include "OrderBook.h"

OrderBook::OrderBook() :
	IntrumentInfo(NULL),
	LastPrice(Constants::INVALIDPRICE),
	Auction(AuctionType::UNKNOWNAUCTION)
	//InstrumentInfo()
{
}

OrderBook::~OrderBook() {
}

ReturnType OrderBook::InsertOrderFlow(Order* o) {
	this->OrderFlow.Push(o);
	return Constants::SUCCESS;
}

ReturnType OrderBook::InsertOrderHashQueue(Order* op) {
	switch(op->GetDirection())
	{
	case DirectionType::BUY:
		this->BidOrderHashQueue.Insert(& op);
		break;
	case DirectionType::SELL:
		this->AskOrderHashQueue.Insert(& op);
		break;
	default:
		return Constants::FAILURE;
	}
	return Constants::SUCCESS;
}

Order* OrderBook::GetBestPriceOrder(DirectionType direction) {
	Order * bestPriceOrder = NULL;
	switch(direction)
	{
	case DirectionType::BUY:
		//this->BidOrderHashQueue.GetBestPriceOrder();
		bestPriceOrder = NULL;
		break;
	case DirectionType::SELL:
		//this->AskOrderHashQueue.GetBestPriceOrder();
		bestPriceOrder = NULL;
		break;
	default:
		bestPriceOrder = NULL;
	}
	return bestPriceOrder;
}

ReturnType OrderBook::OrderMatching(Order * op) {
	switch(Auction)
	{
	case AuctionType::CALLAUCTION:
		break;
	case AuctionType::CONTINUOUSAUCTION:

		//
		break;
	default:
		break;
	}
	return Constants::SUCCESS;
}

Order* OrderBook::GetCounterParties(Order* op) {
	Order * bestPriceOrder = NULL;
	switch(op->GetDirection())
	{
	case DirectionType::BUY:
		//this->BidOrderHashQueue.GetBestPriceOrder();
		bestPriceOrder = NULL;
		break;
	case DirectionType::SELL:
		//this->AskOrderHashQueue.GetBestPriceOrder();
		bestPriceOrder = NULL;
		break;
	default:
		bestPriceOrder = NULL;
	}
	return bestPriceOrder;
}

PriceType OrderBook::GetTradingPrice(Order* buy, Order* sell) {
	PriceType tradingPrice = Constants::INVALIDPRICE;
	if(buy->GetOrderPrice() < sell->GetOrderPrice())
	{
		tradingPrice = Constants::INVALIDPRICE;
	}else if(this->GetLastPrice() <= sell->GetOrderPrice())
	{
		tradingPrice = sell->GetOrderPrice();
	}
	else if(this->GetLastPrice() <= buy->GetOrderPrice())
	{
		tradingPrice = this->GetLastPrice();
	}
	else if(buy->GetOrderPrice() < this->GetLastPrice())
	{
		tradingPrice = buy->GetOrderPrice();
	}
	else
	{
		tradingPrice = Constants::INVALIDPRICE;
	}
	return tradingPrice;
}

inline PriceType OrderBook::GetLastPrice() {
	return this->LastPrice;
}
