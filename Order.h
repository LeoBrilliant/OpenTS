/*
 * Order.h
 *
 *  Created on: 2016��4��11��
 *      Author: user
 */

#ifndef ORDER_H_
#define ORDER_H_

#include <String>
#include <chrono>

#include "Instruction.h"
#include "ProgramMessage.h"

using namespace std;
using namespace chrono;

class Order : public Instruction
{
public:
	Order();

private:
	//�ͻ�ID
	string ClientID;
	//��Լ��
	string IntrumentID;
	//ָ������
	string OrderType;
	//����
	char Direction;
	//��ƽ��־
	char OffsetFlag;
	//�۸�
	double OrderPrice;
	//����
	int Volume;
	//�������
	string OrderID;
	//���ر������
	string LocalOrderID;
	//������
	//����ʱ��
	chrono OrderTimePoint;
	//ʣ������
	int VolumeLeft;
	//����ʱ��
	chrono CancelTimePoint;
	//����״̬
	int OrderStatus;
};



#endif /* ORDER_H_ */
