/*
 * PriorityQueue.h
 *
 *  Created on: 2016Äê1ÔÂ26ÈÕ
 *      Author: LeoBrilliant
 */

#ifndef STL_PriorityQueue_H_
#define STL_PriorityQueue_H_

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template<typename T, class Container = vector<T>,
typename Compare = less<typename Container::value_type> >
class PriorityQueue
{
private:
	priority_queue<T, Container, Compare> pqt;

public:
	//Constructor
	PriorityQueue():pqt() { cout << "VectorOps Constructor: Default" << endl; }
	PriorityQueue(PriorityQueue<T, Container, Compare>& pq):pqt(pq.GetPqt())
	{
		cout << "VectorOps Constructor: Copy" << endl;
	}
	PriorityQueue(typename Container::iterator first, typename Container::iterator last):pqt(first, last)
	{
		cout << "VectorOps Constructor: Fill dt with iterator from first to last" << endl;
	}

	//Destructor
	~PriorityQueue()
	{
		while(!this->Empty())
		{
			this->Pop();
		}
		cout << "DequeOps Destructor: Default" << endl;
	}

	//Capacity
	bool Empty() const { return pqt.empty(); }
	size_t Size() const { return pqt.size(); }

	//Element access
	const T& Top() { return pqt.top(); }

	//Modifiers
	void Push(const T& t) { pqt.push(t); }
	void Pop() { pqt.top(); }

	//Getter
	const priority_queue<T, Container, Compare>& GetPqt() const {
		return pqt;
	}

	//Summary
	void GetSummary();
	//Detail
	void GetDetail(const string &);
};

#endif /* STL_PriorityQueue_H_ */
