/*
 * TimePoint.cpp
 *
 *  Created on: 2016Äê4ÔÂ24ÈÕ
 *      Author: LeoBrilliant
 */


#include "RightTimePoint.h"

RightTimePoint::RightTimePoint() : TimePoint(duration<int> (0)) {

}

RightTimePoint::~RightTimePoint() {
}

time_point<system_clock> RightTimePoint::Now() {
	return system_clock::now();
}

time_t RightTimePoint::ToTimeT() {
	return system_clock::to_time_t(this->TimePoint);
}

void RightTimePoint::FromTimeT(time_t* tp) {
	this->TimePoint = system_clock::from_time_t(*tp);
}

char* RightTimePoint::GetCTime() {
	time_t tmp = this->ToTimeT();
	return ctime(&tmp);
}

tm* RightTimePoint::GetLocalTime() {
	time_t tmp = this->ToTimeT();
	return localtime(&tmp);
}

RightTimePoint& RightTimePoint::operator =(RightTimePoint& rtp) {
	this->TimePoint = rtp.GetTimePoint();
	return *this;
}

RightTimePoint& RightTimePoint::operator =(time_point<system_clock> tp) {
	this->TimePoint = tp;
	return *this;
}

const time_point<system_clock>& RightTimePoint::GetTimePoint() const {
	return TimePoint;
}

void RightTimePoint::SetTimePoint(const time_point<system_clock>& timePoint) {
	TimePoint = timePoint;
}

void RightTimePoint::SetTimePoint() {
	this->TimePoint = Now();
}

void RightTimePoint::FromMicroSeconds(int microsecs) {
	microseconds ms(microsecs);

	duration<time_t, std::micro> milli_dura = ms;

	time_point<system_clock> tmp(milli_dura);

	this->TimePoint = tmp;
}

int RightTimePoint::GetMicroSeconds() {
	duration<time_t, std::micro> milli_dura = duration_cast<microseconds>(this->TimePoint.time_since_epoch());

	return milli_dura.count();
}
