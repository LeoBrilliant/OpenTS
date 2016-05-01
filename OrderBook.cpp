/*
 * OrderBook.cpp
 *
 *  Created on: 2016年4月28日
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
	ReturnType ret = Constants::FAILURE;
	switch(op->GetDirection())
	{
	case DirectionType::BUY:
		ret = this->BidOrderHashQueue.Insert(op);
		break;
	case DirectionType::SELL:
		ret = this->AskOrderHashQueue.Insert(op);
		break;
	default:
		ret = Constants::FAILURE;
	}
	return ret;
}

Order* OrderBook::GetBestPriceOrder(DirectionType direction) {
	Order * bestPriceOrder = NULL;
	switch(direction)
	{
	case DirectionType::BUY:
		bestPriceOrder = NULL;
		bestPriceOrder = this->BidOrderHashQueue.GetBestPriceOrder();
		break;
	case DirectionType::SELL:
		bestPriceOrder = NULL;
		bestPriceOrder = this->AskOrderHashQueue.GetBestPriceOrder();
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
		this->InsertOrderFlow(op);
		Order * counterParty = this->GetCounterParties(op);
		PriceType matchingPrice = Constants::INVALIDPRICE;
		VolumeType matchingVolume = Constants::INVALIDVOLUME;
		if(op->GetDirection() == DirectionType::BUY)
		{
			matchingPrice = this->GetTradingPrice(op, counterParty);
			matchingVolume = this->GetTradingVolume(op, counterParty);
		}
		else if(op->GetDirection() == DirectionType::SELL)
		{
			matchingPrice = this->GetTradingPrice(counterParty, op);
			matchingVolume = this->GetTradingVolume(counterParty, op);
		}
		else
		{
			//Unknown Direction, Shouldn't be here
		}
		//写入成交流
		//更新最新价
		//更新行情
		//更新持仓
		break;
	default:
		break;
	}
	return Constants::SUCCESS;
}

Order* OrderBook::GetCounterParties(Order* op) {
	Order * counterParty = NULL;
	switch(op->GetDirection())
	{
	case DirectionType::BUY:
		counterParty = this->BidOrderHashQueue.GetBestPriceOrder();
		break;
	case DirectionType::SELL:
		counterParty = this->AskOrderHashQueue.GetBestPriceOrder();
		break;
	default:
		counterParty = NULL;
	}
	return counterParty;
}

PriceType OrderBook::GetTradingPrice(Order* buy, Order* sell) {
	PriceType tradingPrice = Constants::INVALIDPRICE;
	if(buy->GetOrderPrice() < sell->GetOrderPrice())
	{
		tradingPrice = Constants::INVALIDPRICE;
	}
	else if(this->GetLastPrice() <= sell->GetOrderPrice())
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

VolumeType OrderBook::GetTradingVolume(Order* buy, Order* sell) {
	VolumeType tradingVolume = Constants::INVALIDVOLUME;
	if(buy->GetVolumeLeft() < sell->GetVolumeLeft())
	{
		tradingVolume = buy->GetVolumeLeft();
	}
	else
	{
		tradingVolume = sell->GetVolumeLeft();
	}
	return tradingVolume;
}

inline PriceType OrderBook::GetLastPrice() {
	return this->LastPrice;
}
