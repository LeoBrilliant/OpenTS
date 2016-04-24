/*
 * TimePoint.cpp
 *
 *  Created on: 2016Äê4ÔÂ24ÈÕ
 *      Author: LeoBrilliant
 */


#include "TimePoint.h"

TimePoint::TimePoint() : t(duration<int> (0)) {

}

TimePoint::~TimePoint() {
}

time_point<system_clock> TimePoint::Now() {
	return system_clock::now();
}

time_t TimePoint::ToTimeT() {
	return system_clock::to_time_t(this->t);
}

void TimePoint::FromTimeT(time_t* tp) {
	this->t = system_clock::from_time_t(*tp);
}

char* TimePoint::GetCTime() {
	time_t tmp = this->ToTimeT();
	return ctime(&tmp);
}

tm* TimePoint::GetLocalTime() {
	time_t tmp = this->ToTimeT();
	return localtime(&tmp);
}
