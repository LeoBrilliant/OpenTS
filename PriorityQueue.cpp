/*
 * PriorityQueue.cpp
 *
 *  Created on: 2016Äê1ÔÂ26ÈÕ
 *      Author: LeoBrilliant
 */


#include "PriorityQueue.h"


template<typename T, class Container, typename Compare>
inline void PriorityQueue<T, Container, Compare>::GetSummary() {
	cout << "Summary[" << endl;
	cout << "empty: \t" << (this->Empty()? "True":"False") << "\t" << endl;
	cout << "size: \t" << this->Size() << endl;
	cout << "]" << endl;
}

template<typename T, class Container, typename Compare>
inline void PriorityQueue<T, Container, Compare>::GetDetail(
		const string& s) {
	cout << s << endl;
	this->GetSummary();
	cout << "Elements[" << endl;
	priority_queue<T, Container, Compare> tmp;
	while(!this->Empty())
	{
		tmp.push(this->Top());
		cout << tmp.Top() << "<->" ;
		this->Pop();
	}
	while(!tmp.empty())
	{
		//cout << tmp.Top() << "<->" ;
		this->Push(tmp.top());
		tmp.pop();
	}
	cout << "]" << endl;
}

