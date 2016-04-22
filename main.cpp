/*
 * main.cpp
 *
 *  Created on: 2016Äê4ÔÂ11ÈÕ
 *      Author: user
 */

#include <iostream>

using namespace std;

#include "UnitTest/ListTest.h"
#include "UnitTest/ChainHashTableTest.h"

int main()
{
	cout << "Hello OpenTS!" << endl;

	ChainHashTableTest<int, char> chtt;
	chtt.ContructorTest();
	//chtt.TestSuite();
	//ListTest<int> lt;
	//lt.TestSuite();
	return 0;
}


