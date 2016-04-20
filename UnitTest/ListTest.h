/*
 * ListTest.h
 *
 *  Created on: 2016年4月20日
 *      Author: user
 */

#ifndef UNITTEST_LISTTEST_H_
#define UNITTEST_LISTTEST_H_

#include "../List.h"

#include <typeinfo>
#include <cassert>
#include <cerrno>
#include <stdexcept>
#include<iomanip>

template <typename T>
class ListTest
{
	static unsigned int caseCount;
	static unsigned int casePassed;
public:
	//Constructor
	ListTest() {}

	//Constructor Test
	void ContructorTest();

	//Operator= Test
	void OperatorEqualTest();

	//OperatorNew Test
	void OperatorNewTest();

	//Exception Test
	void ExceptioinTest();

	//Signal Test
	void SignalTest();

	//Operator[] Test
	void OperatorSquareBracketsTest();

	//Apply Test
	void ApplyTest();

	//Shift Test
	void ShiftTest();

	//Resize Test
	void ResizeTest();

	//Test suite
	void TestSuite();

};

template<typename T>
unsigned int ListTest<T>::caseCount = 0;
template<typename T>
unsigned int ListTest<T>::casePassed = 0;

template<typename T>
inline void ListTest<T>::ContructorTest() {

	//cout << __func__ << endl;
	//cout << "TestCase(" << caseCount << "\t): " << __FUNCTION__ << " \t"  ;
	cout << __FUNCTION__ << endl;

	cout << "TestCase(" << ++ caseCount << ")" ;
	List<T> va;
	//cout << typeid(va).name() << "\t";
	assert( typeid(va) == typeid(List<T>));
	//assert( &vi != NULL);
	assert(va.Size() == 0);
	//vi.GetDetail("Hello");
	casePassed ++;
	cout << "Passed" << endl;

	cout << "TestCase(" << ++ caseCount << ")" ;
	size_t n = 13;
	assert(typeid(T) == typeid(int));
	T val = 14;
	List<T> va2(n, val);
	assert(typeid(va2) == typeid(List<T>));
	assert(va2.Size() == n) ;
	//va2.GetDetail("N Element, Initialized with default value");
	casePassed ++;
	cout << "Passed" << endl;

/*
	cout << "TestCase(" << ++ caseCount << ")" ;

	class equal_n : public unary_function<bool, T>
	{
		T t;
	public:
		equal_n(T val):t(val) {}
		bool operator()(int n)
		{
			return  n == t;
		}
	};

	n = 15;
	int val = 14;
	equal_n eq_n(val);

	assert(typeid(T) == typeid(int));
	ValArrayOps<T> va3(val, n);
	assert(typeid(va3) == typeid(ValArrayOps<T>));
	assert(va3.Size() == n) ;
	assert(all_of(begin(va3.GetVt()), end(va3.GetVt()),  eq_n));
	//va3.GetDetail("N Element, Initialized with given value");
	casePassed ++;
	cout << "Passed" << endl;

	cout << "TestCase(" << ++ caseCount << ")" ;
	T * tp = new T(n);
	fill(tp, tp+n, val);
	ValArrayOps<T> va4(tp, n);
	assert(typeid(va4) == typeid(ValArrayOps<T>));
	assert(va4.Size() == n) ;
	//auto vtp = begin(va4.GetVt());
	//assert(all_of(begin(va4.GetVt()), end(va4.GetVt()),  eq_n));
	//va4.GetDetail("N Element, initialized to the values of the elements in the array pointed by p");
	//delete tp;
	casePassed ++;
	cout << "Passed" << endl;

	cout << "TestCase(" << ++ caseCount << ")" ;
	//T * tp = new T(n);
	//fill(tp, tp+n, val);
	ValArrayOps<T> va5(va3);
	//如果从va4处拷贝构造，调试时va5比较元素时发生异常退出信号
	//而且很奇怪，va4元素实际保存的地址在tp处。。。。
	assert(typeid(va5) == typeid(ValArrayOps<T>));
	assert(va5.Size() == n) ;
	//	auto vtp = begin(va5.GetVt());
	//	auto vtpend = end(va5.GetVt());
	//	int d = distance(vtp, vtpend);
	assert(all_of(begin(va5.GetVt()), end(va5.GetVt()),  eq_n));
	//va5.GetDetail("copy / move constructor");
	casePassed ++;
	cout << "Passed" << endl;

	cout << "TestCase(" << ++ caseCount << ")" ;
	//T * tp = new T(n);
	//fill(tp, tp+n, val);
	slice sl = slice(0, 4, 5);
	try
	{
		//valarray<T> vatmp = (va3.GetVt())[sl];
		valarray<T> vatmp = va2[sl];
		ValArrayOps<T> va6((va2.GetVt())[sl]);
		assert(typeid(va6) == typeid(ValArrayOps<T>));
		assert(va6.Size() ==  sl.size()) ;
		//auto vtp = begin(va4.GetVt());
		assert(equal(begin(va6.GetVt()), end(va6.GetVt()),  begin(vatmp)));
		//va6.GetDetail("copy / move constructor");
		casePassed ++;
		cout << "Passed" << endl;
	}
	catch(out_of_range& oor)
	{
		cerr << "out of range" << endl;
	}
	catch(...)
	{
		cout << "exception" << endl;
	}

	cout << "TestCase(" << ++ caseCount << ")" ;
	//T * tp = new T(n);
	//fill(tp, tp+n, val);
	size_t start = 1;
	size_t lengths[] = {4, 5};
	size_t strides[] = {7, 2};
	gslice gsl = gslice(start, valarray<size_t>(lengths, 2), valarray<size_t>(strides, 2));
	try
	{
		//valarray<T> vatmp = (va3.GetVt())[sl];
		valarray<T> vatmp = va3[gsl];
		ValArrayOps<T> va6((va3.GetVt())[gsl]);
		assert(typeid(va6) == typeid(ValArrayOps<T>));
		assert(va6.Size() ==  vatmp.size()) ;
		//auto vtp = begin(va4.GetVt());
		assert(equal(begin(va6.GetVt()), end(va6.GetVt()),  begin(vatmp)));
		//va6.GetDetail("copy / move constructor");
		casePassed ++;
		cout << "Passed" << endl;
	}
	catch(out_of_range& oor)
	{
		cerr << "out of range" << endl;
	}
	catch(...)
	{
		cout << "exception" << endl;
	}

	cout << "TestCase(" << ++ caseCount << ")" ;
	try
	{
		size_t sz = 10;
		valarray<int> vi(sz);
		valarray<bool> mask(sz);
		for(size_t i = 0; i < sz ; ++i)
		{
			vi[i] = i;
			mask[i] = ((i%2) == 1);
		}
		valarray<T> vatmp = vi[mask];
		ValArrayOps<T> va6(vi[mask]);
		assert(typeid(va6) == typeid(ValArrayOps<T>));
		assert(va6.Size() ==  vatmp.size()) ;
		//auto vtp = begin(va4.GetVt());
		assert(equal(begin(va6.GetVt()), end(va6.GetVt()),  begin(vatmp)));
		//va6.GetDetail("mask_array");
		casePassed ++;
		cout << "Passed" << endl;
	}
	catch(out_of_range& oor)
	{
		cerr << "out of range" << endl;
	}
	catch(...)
	{
		cout << "exception" << endl;
	}

	cout << "TestCase(" << ++ caseCount << ")" ;
	try
	{
		size_t sz = 10;
		valarray<int> vi(sz);
		valarray<size_t> ind(sz);
		for(size_t i = 1; i <= sz ; ++i)
		{
			vi[i - 1] = i;
			ind[i-1] = (i - 1);
		}
		ind[3] = ind[5] = 4;
		valarray<T> vatmp = vi[ind];
		ValArrayOps<T> va6(vi[ind]);
		assert(typeid(va6) == typeid(ValArrayOps<T>));
		assert(va6.Size() ==  vatmp.size()) ;
		//auto vtp = begin(va4.GetVt());
		assert(equal(begin(va6.GetVt()), end(va6.GetVt()),  begin(vatmp)));
		va6.GetDetail("indirect_array");

		valarray<size_t> ind2(3);
		ind2[0] = 3; ind2[1] = 6; ind2[2] = 9;
		va6[ind2] *= va6[ind2];
		//va6.GetDetail("indirect_array operation");
		casePassed ++;
		cout << "Passed" << endl;
	}
	catch(out_of_range& oor)
	{
		cerr << "out of range" << endl;
	}
	catch(...)
	{
		cout << "exception" << endl;
	}
*/
}

template<typename T>
void ListTest<T>::OperatorNewTest()
{
	cout << __FUNCTION__ << endl;

	cout << "TestCase(" << ++ caseCount << ")" ;
	List<T> * pl = NULL;
	//cout << typeid(va).name() << "\t";
	assert( typeid(pl) == typeid(List<T> *));
	pl = new List<T>();
	assert( pl != NULL);
	assert(pl->Size() == 0);
	pl->GetDetail("Hello");
	casePassed ++;
	delete pl;
	cout << "Passed" << endl;

	cout << "TestCase(" << ++ caseCount << ")" ;
	size_t n = 13;
	assert(typeid(T) == typeid(int));
	T val = 14;
	List<T> * pl2;
	assert(typeid(pl2) == typeid(List<T> *));
	pl2 = new List<T>(n, val);
	assert(pl2->Size() == n) ;

	for(typename List<T>::LstCstIter i = pl2->Begin(); i != pl2->End(); ++i)
	{
		assert(*i == val);
	}
	pl2->GetDetail("N Element, Initialized with default value");
	pl2[0].GetSummary();
	casePassed ++;
	delete pl2;
	cout << "Passed" << endl;

	cout << "TestCase(" << ++ caseCount << ")" ;
	try
	{
		size_t n = 15;
		assert(typeid(T) == typeid(int));
		//T val = 16;
		List<T> * pl3;
		assert(typeid(pl3) == typeid(List<T> *));
		pl3 = new List<T>[n];

		//assert(sizeof(pl3) == n);

		for(size_t i = 0; i < n; ++i)
		{
			assert(pl3[i].Size() == 0);
		}
		assert(pl3->Size() == 0) ;

		for(typename List<T>::LstCstIter i = pl3->Begin(); i != pl3->End(); ++i)
		{
			//assert(*i == val);
		}
		pl3->GetDetail("N Element, Initialized with default value");
		casePassed ++;
		delete[] pl3;
		cout << "Passed" << endl;
	}
	catch(out_of_range& oor)
	{
		cerr << "out of range" << endl;
	}
	catch(...)
	{
		cout << "exception" << endl;
	}

	//TODO

}

template<typename T>
inline void ListTest<T>::TestSuite() {
	this->ContructorTest();
	//this->OperatorEqualTest();
	this->OperatorNewTest();
	//this->ExceptioinTest();
	//this->SignalTest();
	//this->OperatorSquareBracketsTest();
	//this->ApplyTest();
	//this->ShiftTest();
	//this->ResizeTest();
}


#endif /* UNITTEST_LISTTEST_H_ */
