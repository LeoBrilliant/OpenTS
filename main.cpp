/*
 * main.cpp
 *
 *  Created on: 2016Äê4ÔÂ11ÈÕ
 *      Author: user
 */

#include <iostream>

using namespace std;

#include "UnitTest/ListTest.h"

int main()
{
	cout << "Hello OpenTS!" << endl;

	ListTest<int> lt;
	lt.TestSuite();
	return 0;
}


