/*
 * Instrument.h
 *
 *  Created on: 2016年4月11日
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
	//合约标的
	string Underlying;
	//合约乘数
	int Multiplier;
	//报价单位
	int QuotationUnit;
	//最小变动价位
	double Tick;
	//合约月份
	string Month;
	//交易时间
	//每日价格最大波动限制
	//最低交易保证金
	//最后交易日
	//交割日期
	//交割方式
	//交易代码（产品代码）
	//上市交易所

};


#endif /* INSTRUMENT_H_ */
