/*
 * TimePointUnitTest.cpp
 *
 *  Created on: 2016Äê4ÔÂ24ÈÕ
 *      Author: LeoBrilliant
 */

#include "RightTimePointUnitTest.h"

unsigned int TimePointUnitTest::caseCount = 0;
unsigned int TimePointUnitTest::casePassed = 0;

TimePointUnitTest::TimePointUnitTest() {
}

TimePointUnitTest::~TimePointUnitTest() {
}

void TimePointUnitTest::TestSuite() {
	this->ContructorTest();
	this->NowTest();
	this->GetMicroSecondsTest();
	this->FromMicroSecondsTest();

	UnitTestStats();
}

void TimePointUnitTest::ContructorTest() {
	ProgramMessage::Debug(__FUNCTION__);

	ProgramMessage::Debug<int>(IncCaseCount());
	RightTimePoint tp;
	ProgramMessage::Debug(typeid(tp).name());
	assert( typeid(tp) == typeid(RightTimePoint));

	ProgramMessage::Debug(tp.GetCTime());
	//cht1.GetSummary();
	IncCasePassed();
	ProgramMessage::Debug("Passed");
}

void TimePointUnitTest::NowTest() {
	ProgramMessage::Debug(__FUNCTION__);

	ProgramMessage::Debug("Include GetCTime and ToTimeT");
	ProgramMessage::Debug<int>(IncCaseCount());
	time_t tbase ;
	time_point<system_clock> tmpp = RightTimePoint::Now();
	time(&tbase);
	time_t tmp = system_clock::to_time_t(tmpp);
	RightTimePoint tp;
	ProgramMessage::Debug(typeid(tp).name());
	assert( typeid(tp) == typeid(RightTimePoint));
	tp.FromTimeT(&tmp);

	char * cp1, * cp2;
	cp1 = ctime(&tbase);
	cp2 = tp.GetCTime();
	assert(strlen(cp1) == strlen(cp2));

	for(size_t i = 0; i < strlen(cp1); ++i)
	{
		assert(cp1[i] == cp2[i]);
	}
	ProgramMessage::Debug(tp.GetCTime());
	//cht1.GetSummary();
	IncCasePassed();
	ProgramMessage::Debug("Passed");
}

void TimePointUnitTest::UnitTestStats() {
	ProgramMessage::Print<int>(TimePointUnitTest::GetCaseCount());
	ProgramMessage::Print(" Cases in total, ");
	ProgramMessage::Print<int>(TimePointUnitTest::GetCasePassed());
	ProgramMessage::PrintLine(" Cases Passed.");
}

void TimePointUnitTest::GetMicroSecondsTest() {
	ProgramMessage::Debug(__FUNCTION__);

	ProgramMessage::Debug<int>(IncCaseCount());
	time_t tbase ;
	time_point<system_clock> tmpp = RightTimePoint::Now();
	time(&tbase);
	time_t tmp = system_clock::to_time_t(tmpp);
	RightTimePoint tp;
	ProgramMessage::Debug(typeid(tp).name());
	assert( typeid(tp) == typeid(RightTimePoint));
	tp.FromTimeT(&tmp);

	char * cp1, * cp2;
	cp1 = ctime(&tbase);
	cp2 = tp.GetCTime();
	assert(strlen(cp1) == strlen(cp2));

	for(size_t i = 0; i < strlen(cp1); ++i)
	{
		assert(cp1[i] == cp2[i]);
	}
	ProgramMessage::Debug(tp.GetCTime());
	ProgramMessage::Debug(asctime(tp.GetLocalTime()));
	long i = tp.GetMicroSeconds();
	//int l = sizeof(long);
	ProgramMessage::Debug<long long>(i);

	RightTimePoint tp2;
	tp2.FromMicroSeconds(i);
	ProgramMessage::Debug(tp2.GetCTime());

	IncCasePassed();
	ProgramMessage::Debug("Passed");
}

void TimePointUnitTest::FromMicroSecondsTest() {
}
