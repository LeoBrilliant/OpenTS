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
#include "Queue.h"

class OrderBook
{
public:
	OrderBook();

private:
	//��Լ��Ϣ
	Instrument * IntrumentInfo;
	//������λ��ϣ����

	//������λ���ȶ���
	//TODO�Ȳ���������
	//��������

	Queue OrderQueue;
};



#endif /* ORDERBOOK_H_ */
