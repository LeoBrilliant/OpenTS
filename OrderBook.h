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
#include "Types.h"

class OrderBook
{
public:
	OrderBook();

	~OrderBook();

private:
	//��Լ��Ϣ
	Instrument * IntrumentInfo;
	//������λ��ϣ����
	ChainHashTable<Order*, string> BidOrderHashQueue;
	ChainHashTable<Order*, string> AskOrderHashQueue;

	//������λ���ȶ���
	//TODO�Ȳ���������
	//��������
	Queue<Order*> OrderFlow;

	//���¼�
	PriceType LastPrice;

public:
	//���붩������
	ReturnType InsertOrderFlow(Order & o);
	//�����򶩵���
	ReturnType InsertOrderHashQueue(Order * op);
	//������������
	//ReturnType InsertAskOrder(Order * op);
	//��ȡ����һ������
	Order * GetBestPriceOrder(DirectionType direction);
	//Todo ��������
	//����㷨
	ReturnType OrderMatching(AuctionType auction);
	//ToDo ��¼ί����
	//ToDo ��¼�ɽ���
};



#endif /* ORDERBOOK_H_ */
