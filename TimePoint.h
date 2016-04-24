/*
 * TimePoint.h
 *
 *  Created on: 2016Äê4ÔÂ24ÈÕ
 *      Author: LeoBrilliant
 */

#ifndef TIMEPOINT_H_
#define TIMEPOINT_H_

#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;

class TimePoint
{
public:
	TimePoint();
	~TimePoint();

private:
	time_point<system_clock> t;

public:
	static time_point<system_clock> Now();
	time_t ToTimeT();
	void FromTimeT(time_t * tp);

	char * GetCTime();
	tm * GetLocalTime();


};



#endif /* TIMEPOINT_H_ */
