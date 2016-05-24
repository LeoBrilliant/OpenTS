/*
 * TimePoint.h
 *
 *  Created on: 2016Äê4ÔÂ24ÈÕ
 *      Author: LeoBrilliant
 */

#ifndef RIGHTTIMEPOINT_H_
#define RIGHTTIMEPOINT_H_

#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;

class RightTimePoint
{
public:
	RightTimePoint();
	~RightTimePoint();

private:
	time_point<system_clock> TimePoint;

public:
	static time_point<system_clock> Now();
	time_t ToTimeT();
	void FromTimeT(time_t * tp);
	void FromMicroSeconds(long long microseconds);

	char * GetCTime();
	tm * GetLocalTime();

	RightTimePoint & operator=(RightTimePoint & rtp);
	RightTimePoint & operator=(time_point<system_clock> tp);

	const time_point<system_clock>& GetTimePoint() const;
	void SetTimePoint(const time_point<system_clock>& timePoint);
	void SetTimePoint();

	long long GetMicroSeconds();
};



#endif /* RIGHTTIMEPOINT_H_ */
