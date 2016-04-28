/*
 * Instrument.h
 *
 *  Created on: 2016年4月11日
 *      Author: user
 */

#ifndef INSTRUMENT_H_
#define INSTRUMENT_H_

#include <String>
#include "Types.h"
#include "Constants.h"

using namespace std;
using namespace constants;

class Instrument
{
public:
	Instrument();
	~Instrument();
private:
	//合约名称
	StringType Name;
	//合约代码
	StringType Code;
	//合约标的
	StringType Underlying;
	//合约乘数
	VolumeType Multiplier;
	//报价单位
	VolumeType QuotationUnit;
	//最小变动价位
	PriceType Tick;
	//合约月份
	StringType Month;
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
