/*
 * main.cpp
 *
 *  Created on: 2016��4��11��
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


