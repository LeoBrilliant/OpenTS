/*
 * QueueOps.cpp
 *
 *  Created on: 2016Äê1ÔÂ26ÈÕ
 *      Author: LeoBrilliant
 */

#include "Queue.h"


template<typename T, typename Container>
inline void Queue<T, Container >::GetSummary()
{
	cout << "Summary[" << endl;
	cout << "empty: \t" << (this->Empty()? "True":"False") << "\t" << endl;
	cout << "size: \t" << this->Size() << endl;
	cout << "]" << endl;
}

template<typename T, typename Container>
inline void Queue<T, Container >::GetDetail(const string& s)
{
	cout << s << endl;
	this->GetSummary();
	cout << "Elements[" << endl;
	queue<T> tmp;
	while(!this->Empty())
	{
		tmp.push(this->Back());
		this->Pop();
	}
	while(!tmp.empty())
	{
		cout << tmp.back() << "<->" ;
		this->Push(tmp.back());
		tmp.pop();
	}
	cout << "]" << endl;
}
