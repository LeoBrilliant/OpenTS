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

	Queue<Order&> OrderQueue;
};



#endif /* ORDERBOOK_H_ */
