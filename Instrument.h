/*
 * Instrument.h
 *
 *  Created on: 2016��4��11��
 *      Author: user
 */

#ifndef INSTRUMENT_H_
#define INSTRUMENT_H_

#include <string>
#include "Types.h"
#include "Constants.h"

using namespace std;
using namespace constants;

class Instrument
{
public:
	Instrument();
	Instrument(StringType name,
		StringType code,
		StringType underlying,
		VolumeType multiplier,
		VolumeType quotationUnit,
		PriceType tick,
		StringType month
	);
	~Instrument();
	const StringType& GetCode() const;
	const StringType& GetMonth() const;
	VolumeType GetMultiplier() const;
	const StringType& GetName() const;
	VolumeType GetQuotationUnit() const;
	PriceType GetTick() const;
	const StringType& GetUnderlying() const;

private:
	//��Լ����
	StringType Name;
	//��Լ����
	StringType Code;
	//��Լ���
	StringType Underlying;
	//��Լ����
	VolumeType Multiplier;
	//���۵�λ
	VolumeType QuotationUnit;
	//��С�䶯��λ
	PriceType Tick;
	//��Լ�·�
	StringType Month;
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
