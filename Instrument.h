/*
 * Instrument.h
 *
 *  Created on: 2016��4��11��
 *      Author: user
 */

#ifndef INSTRUMENT_H_
#define INSTRUMENT_H_

#include <String>

using namespace std;

class Instrument
{
public:
	Instrument();

private:
	//��Լ���
	string Underlying;
	//��Լ����
	int Multiplier;
	//���۵�λ
	int QuotationUnit;
	//��С�䶯��λ
	double Tick;
	//��Լ�·�
	string Month;
	//����ʱ��
	//ÿ�ռ۸���󲨶�����
	//��ͽ��ױ�֤��
	//�������
	//��������
	//���ʽ
	//���״��루��Ʒ���룩
	//���н�����

};


#endif /* INSTRUMENT_H_ */
