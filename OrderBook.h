/*
 * OrderBook.h
 *
 *  Created on: 2016��4��11��
 *      Author: user
 */

#ifndef ORDERBOOK_H_
#define ORDERBOOK_H_

#include <vector>
#include "Instrument.h"
#include "ChainHashTable.h"
#include "Order.h"
#include "Queue.h"
#include "List.h"
#include "Types.h"
#include "OrderChainHashTable.h"
#include "Constants.h"
#include "TradingRecord.h"

class OrderBook
{
public:
	OrderBook();

	~OrderBook();

private:
	//��Լ��Ϣ
	Instrument * IntrumentInfo;
	//������λ��ϣ����
	OrderChainHashTable BidOrderHashQueue;
	OrderChainHashTable AskOrderHashQueue;

	//������λ���ȶ���
	//TODO�Ȳ���������
	//��������
	List<Order*> OrderFlow;

	//�ɽ���
	List<TradingRecord*> TradingFlow;

	//���¼�
	PriceType LastPrice;

	//��������
	AuctionType Auction;

public:
	//��ȡ����һ������
	Order * GetBestPriceOrder(DirectionType direction);

	//��ȡ���¼�
	inline PriceType GetLastPrice();

	//�����û�ָ��
	ReturnType OrderAction(Instruction * inst);
private:
	//���붩������
	ReturnType InsertIntoOrderFlow(Order * o);
	//��ȡ���ַ�
	Order * GetCounterParties(Order *op);
	//��ȡ�޼�ָ��ɽ���
	PriceType GetTradingPrice(Order * buy, Order * sell);
	//��ȡ�ɽ���
	VolumeType GetTradingVolume(Order* buy, Order* sell);
	//���ɳɽ���¼
	TradingRecord* GenTradingRecord(IntIDType tradeID, Order* op, VolumeType volume, PriceType price);
	//����ɽ���
	ReturnType InsertIntoTradingFlow(TradingRecord * rec);
	//�����򶩵���
	ReturnType InsertIntoOrderHashQueue(Order * op);
	//������������
	//ReturnType InsertAskOrder(Order * op);
	//�Ӷ�������ɾ������
	Order* RemoveFromOrderHashQueue(Order* op);
	//����㷨
	ReturnType OrderMatching(Order * op);
	//�������¼�
	VoidType SetLastPrice(PriceType lastPrice);
	//Todo ��������
	ReturnType CancelOrderAction(Instruction * inst);
	//����OrderID���Ҷ���
	Order* GetOrderByID(IntIDType id);
	//ToDo ��¼ί����
	//ToDo ��¼�ɽ���
};



#endif /* ORDERBOOK_H_ */
