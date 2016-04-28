/*
 * Queue.h
 *
 *  Created on: 2016��4��18��
 *      Author: user
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <queue>

using namespace std;

template <typename T, typename Container = deque<T> >
class Queue
{
private:
	queue<T, Container> qt;

public:
	//Constructor
	Queue():qt() { cout << "Queue Constructor: Default" << endl;  }
	Queue(const Container & c): qt(c) { cout << "Queue Constructor: Copy Container" << endl; }
	Queue(Queue<T, Container> & q): qt(q.GetQt()) { cout << "Queue Constructor: Copy" << endl;}

	//Destructor
	~Queue() { while(! qt.empty()) qt.pop(); cout << "Queue Destructor: Default" << endl; }

	//Capacity
	bool Empty() const { return qt.empty(); }
	size_t Size() const { return qt.size(); }

	//Element access
	T& Front() { return qt.front(); }
	T& Back() { return qt.back(); }

	//Modifier
	void Push(const T& val) { qt.push(val); }
	void Push(T& val) { qt.push(val); }
	void Pop() { qt.pop(); }

	//Getter
	queue<T, Container> & GetQt() { return qt; }

	//Summary
	void GetSummary();
	//Detail
	void GetDetail(const string &);
};

#endif /* QUEUE_H_ */
