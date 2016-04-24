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

	//Destructor
	virtual ~UTBase(){};

};

template<typename T>
unsigned int UTBase<T>::caseCount = 0;
template<typename T>
unsigned int UTBase<T>::casePassed = 0;


#endif /* UNITTEST_UTBASE_H_ */
