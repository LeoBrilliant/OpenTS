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
OrderBook::OrderBook(Instrument * inst, PriceType lastPrice, AuctionType auction) :
	IntrumentInfo(inst),
	LastPrice(lastPrice),
	Auction(auction),
	BidOrderHashQueue(DirectionType::BUY, inst->GetTick(), lastPrice, lastPrice),
	AskOrderHashQueue(DirectionType::SELL, inst->GetTick(), lastPrice, lastPrice)
{
}

OrderBook::~OrderBook() {
}

ReturnType OrderBook::InsertIntoOrderFlow(Order* o) {
	this->OrderFlow.PushBack(o);
	return Constants::SUCCESS;
}

ReturnType OrderBook::InsertIntoOrderHashQueue(Order* op) {
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
	Order * counterParty = this->GetCounterParties(op);
	PriceType matchingPrice;
	VolumeType matchingVolume;
	Order * buy, * sell;
	IntIDType tradeID;
	TradingRecord * buyRec, *sellRec;
	RightTimePoint tradingTime;
	switch(Auction)
	{
	case AuctionType::CALLAUCTION:
		break;
	case AuctionType::CONTINUOUSAUCTION:
		this->InsertIntoOrderFlow(op);
		//matchingPrice = Constants::INVALIDPRICE;
		//matchingVolume = Constants::INVALIDVOLUME;
		//限价指令撮合
		while(op->GetVolumeLeft() >= Constants::EMPTYVOLUME)
		{
			if(op->GetDirection() == DirectionType::BUY)
			{
	//			matchingPrice = this->GetTradingPrice(op, counterParty);
	//			matchingVolume = this->GetTradingVolume(op, counterParty);
				buy = op;
				sell = this->GetCounterParties(op);
			}
			else if(op->GetDirection() == DirectionType::SELL)
			{
	//			matchingPrice = this->GetTradingPrice(counterParty, op);
	//			matchingVolume = this->GetTradingVolume(counterParty, op);
				sell = op;
				buy = this->GetCounterParties(op);
			}
			else
			{
				//Unknown Direction, Shouldn't be here
				//NULL;
			}
			matchingPrice = this->GetTradingPrice(buy, sell);

			//撮合成功
			if(matchingPrice != Constants::INVALIDPRICE)
			{
				matchingVolume = this->GetTradingVolume(buy, sell);
				tradeID = TradingRecord::IncRecordCounter();
				buyRec = this->GenTradingRecord(tradeID, buy, matchingVolume, matchingPrice);
				sellRec = this->GenTradingRecord(tradeID, sell, matchingVolume, matchingPrice);
				//写入成交流
				this->InsertIntoTradingFlow(buyRec);
				this->InsertIntoTradingFlow(sellRec);
				//更新最新价
				this->SetLastPrice(matchingPrice);
				//Todo 更新行情
				//Todo 更新持仓
				//更新订单状态订单剩余量
				op->SetVolumeLeft(op->GetVolumeLeft() - matchingVolume);
				if(op->GetVolumeLeft() <= Constants::EMPTYVOLUME)
				{
					//全部成交
					op->SetOrderStatus(OrderStatusType::ALLTRADED);
				}
				else
				{
					//部分成交
					op->SetOrderStatus(OrderStatusType::PARTLYTRADED);
				}

				counterParty->SetVolumeLeft(op->GetVolumeLeft() - matchingVolume);
				if(counterParty->GetVolume() <= Constants::EMPTYVOLUME)
				{
					//全部成交
					counterParty->SetOrderStatus(OrderStatusType::ALLTRADED);
					//从档位表中删除订单
					counterParty = this->RemoveFromOrderHashQueue(counterParty);
				}
				else
				{
					//部分成交
					op->SetOrderStatus(OrderStatusType::PARTLYTRADED);
				}

				tradingTime = RightTimePoint::Now();
				op->SetUpdateTime(tradingTime);
				counterParty->SetUpdateTime(tradingTime);
				//继续撮合
			}
			else
			{
				//撮合不成功,插入订单簿
				this->InsertIntoOrderHashQueue(op);
				break;
			}
		}
		break;
	default:
		break;
	}

	matchingPrice = Constants::INVALIDPRICE;
	matchingVolume = Constants::INVALIDVOLUME;
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
	//assert(buy->GetVolumeLeft() > 0 && sell->GetVolumeLeft() > 0);
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

PriceType OrderBook::GetLastPrice() {
	return this->LastPrice;
}

TradingRecord* OrderBook::GenTradingRecord(IntIDType tradeID, Order* op,
		VolumeType volume, PriceType price)
{
	TradingRecord * rec = NULL;
	rec = new TradingRecord(tradeID,
			op->GetClientID(),
			RecordType::TRADING,
			op->GetInstrumentID(),
			op->GetDirection(),
			op->GetOffsetFlag(),
			price,
			volume,
			op->GetOrderID(),
			op->GetLocalOrderID()
			);

	return rec;
}

ReturnType OrderBook::OrderAction(Instruction* inst) {
	ReturnType ret = Constants::FAILURE;
	Order * op;
	switch(inst->GetInstType())
	{
	case InstructionType::LIMITPRICEORDER:
		op = (Order *)inst;
		ret = this->OrderMatching(op);
		break;
	case InstructionType::CANCEL:
		ret = this->CancelOrderAction(inst);
		break;
	default:
		break;
	}

	return ret;
}

VoidType OrderBook::SetLastPrice(PriceType lastPrice) {
	LastPrice = lastPrice;
}

ReturnType OrderBook::InsertIntoTradingFlow(TradingRecord* rec) {
	this->TradingFlow.PushBack(rec);
	return Constants::SUCCESS;
}

Order* OrderBook::RemoveFromOrderHashQueue(Order* op) {
	ReturnType ret = Constants::FAILURE;
	switch(op->GetDirection())
	{
	case DirectionType::BUY:
		ret = this->BidOrderHashQueue.Remove(op);
		break;
	case DirectionType::SELL:
		ret = this->AskOrderHashQueue.Remove(op);
		break;
	default:
		ret = Constants::FAILURE;
	}
	if(ret == Constants::FAILURE)
		return NULL;

	return op;
}

ReturnType OrderBook::CancelOrderAction(Instruction* inst) {
	Order * op = (Order *)inst;
	ReturnType ret = Constants::FAILURE;
	op = this->GetOrderByID(op->GetOrderID());
	if(op != NULL)
	{
		this->RemoveFromOrderHashQueue(op);
		op->SetOrderStatus(OrderStatusType::CANCELLED);
		op->SetCancelTimePoint();
		//更新档位委托手数
		ret = Constants::SUCCESS;
	}
	return ret;
}

//其实可以用二分查找
Order* OrderBook::GetOrderByID(IntIDType id) {
	Order * op = NULL;
	for(List<Order*>::RLstCstIter iter = this->OrderFlow.Rbegin();  iter != this->OrderFlow.Rend(); ++iter)
	{
		if((*iter)->GetOrderID() == id)
		{
			op = (*iter);
		}
	}
	return op;
}

AuctionType OrderBook::GetAuction() const {
	return Auction;
}

void OrderBook::SetAuction(AuctionType auction) {
	Auction = auction;
}
