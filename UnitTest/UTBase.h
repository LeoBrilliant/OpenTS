/*
 * UTBase.h
 *
 *  Created on: 2016Äê4ÔÂ21ÈÕ
 *      Author: LeoBrilliant
 */

#ifndef UNITTEST_UTBASE_H_
#define UNITTEST_UTBASE_H_


#include <typeinfo>
#include <cassert>
#include <cerrno>
#include <stdexcept>
#include <iomanip>
#include <iostream>
#include <string>
#include <cstring>
#include "../ProgramMessage.h"

using namespace std;

template <typename T>
class UTBase
{
	static unsigned int caseCount;
	static unsigned int casePassed;
public:
	//Constructor
	UTBase() {}

	//Constructor Test
	virtual void ContructorTest();

	//Operator= Test
	virtual void OperatorEqualTest();

	//OperatorNew Test
	virtual void OperatorNewTest();

	//Exception Test
	virtual void ExceptioinTest();

	//Signal Test
	virtual void SignalTest();

	//Operator[] Test
	virtual void OperatorSquareBracketsTest();

	//Apply Test
	virtual void ApplyTest();

	//Shift Test
	virtual void ShiftTest();

	//Resize Test
	virtual void ResizeTest();

	//Test suite
	virtual void TestSuite();

	static unsigned int GetCaseCount(){ return caseCount; }
	static unsigned int IncCaseCount(){ return ++caseCount; }
	static unsigned int GetCasePassed(){ return casePassed; }
	static unsigned int IncCasePassed(){ return ++casePassed; }

	static void UnitTestStats();

	//Destructor
	virtual ~UTBase(){};

};

template<typename T>
unsigned int UTBase<T>::caseCount = 0;
template<typename T>
unsigned int UTBase<T>::casePassed = 0;

template<typename T>
inline void UTBase<T>::ContructorTest() {
}

template<typename T>
inline void UTBase<T>::OperatorEqualTest() {
}

template<typename T>
inline void UTBase<T>::OperatorNewTest() {
}

template<typename T>
inline void UTBase<T>::ExceptioinTest() {
}

template<typename T>
inline void UTBase<T>::SignalTest() {
}

template<typename T>
inline void UTBase<T>::OperatorSquareBracketsTest() {
}

template<typename T>
inline void UTBase<T>::ApplyTest() {
}

template<typename T>
inline void UTBase<T>::ShiftTest() {
}

template<typename T>
inline void UTBase<T>::ResizeTest() {
}

template<typename T>
inline void UTBase<T>::TestSuite() {
	this->ApplyTest();
	this->ContructorTest();
	this->ExceptioinTest();
	this->OperatorEqualTest();
	this->OperatorNewTest();
	this->OperatorSquareBracketsTest();
	this->ResizeTest();
	this->ShiftTest();
	this->SignalTest();
	this->UnitTestStats();
}

template<typename T>
void UTBase<T>::UnitTestStats() {
	ProgramMessage::Print<T>(UTBase<T>::GetCaseCount());
	ProgramMessage::Print(" Cases in total, ");
	ProgramMessage::Print<T>(UTBase<T>::GetCasePassed());
	ProgramMessage::PrintLine(" Cases Passed.");
}


#endif /* UNITTEST_UTBASE_H_ */
