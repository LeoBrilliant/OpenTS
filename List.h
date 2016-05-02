/*
 * ListOperations.h
 *
 *  Created on: 2016��1��25��
 *      Author: LeoBrilliant
 */

#ifndef STL_LISTOPERATIONS_H_
#define STL_LISTOPERATIONS_H_

#include <iostream>
#include <list>
using namespace std;

template<typename T>
class List
{
public:
	typedef typename list<T>::iterator LstIter;
	typedef typename list<T>::const_iterator LstCstIter;
	typedef typename list<T>::const_reverse_iterator RLstCstIter;
	typedef bool(*Compare)(const T& , const T&);
	typedef bool(*BinaryPredicate)(const T& , const T&);
	typedef bool(*Predicate)(const T&);
private:
	list<T> lt;

public:
	//Constructor
	List():lt(){ cout << "List Constructor: Default" << endl; }
	List(size_t n, const T& t):lt(n, t) { 	cout << "List Constructor: Allocate N elements, initialized with default or value-given" << endl; }
	List(LstIter first, LstIter last):lt(first, last) { cout << "List Constructor: Fill dt with iterator from first to last" << endl;}
	List(List<T> & l):lt(l.GetLt()) { cout << "List Constructor: Copy" << endl; }

	//Destructor
	~List(){ lt.clear(); cout << "List Destructor: Default" << endl; }

	//Operator
	list<T> & operator=(List<T> & t) { lt = t.GetLt(); return *this ; }

	//Iterators
	LstCstIter Begin() { return lt.begin(); }
	LstCstIter End() { return lt.end(); }
	RLstCstIter Rbegin() { return lt.rbegin(); }
	RLstCstIter Rend() { return lt.rend(); }

	//Capacity
	bool Empty() { return lt.empty(); }
	size_t Size() { return lt.size(); }
	size_t MaxSize() { return lt.max_size(); }

	//Element access
	T& Front() { return lt.front(); }
	T& Back() { return lt.back(); }

	//Modifiers
	void Assign(LstIter first, LstIter last) { lt.assign(first, last); }
	void Assign(size_t n, const T& t) { lt.assign(n, t); }
	void PushFront(const T& t) { lt.push_front(t); }
	void PopFront() { lt.pop_front(); }
	void PushBack(const T& t) { lt.push_back(t); }
	void PopBack() { lt.pop_back(); }
	LstIter Insert(LstIter position, const T& t) { return lt.insert(position, t); }
	void Insert(LstIter position, size_t n, const T& t) { lt.insert(position, n, t); }
	void Insert(LstIter position, LstIter first, LstIter last) { lt.insert(position, first, last); }
	LstIter Erase(LstCstIter position) { return lt.erase(position); }
	LstIter Erase(LstIter first, LstIter last) { return lt.erase(first, last); }
	void Swap(List<T>& t) { lt.swap(t.GetLt()); }
	void Resize(size_t n) { lt.resize(n); }
	void Clear() { lt.clear(); }

	//Operations
	void Splice(LstIter position, List<T>& t) { lt.splice(position, t.GetLt()); }
	void Splice(LstIter position, List<T>& t, LstIter i) { lt.splice(position, t.GetLt(), i); }
	void Splice(LstIter position, List<T>& t, LstIter first, LstIter last) { lt.splice(position, t.GetLt(), first, last); }
	void Remove(const T& t) { lt.remove(t); }
	void RemoveIf(Predicate pred) { lt.remove_if(pred); }
	void Unique() { lt.unique(); }
	void Unique(BinaryPredicate bin_pred) { lt.unique(bin_pred); }
	void Merge(List<T> &t) { lt.merge(t.GetLt()); }
	void Merge(List<T> &t, Compare comp) { lt.merge(t.GetLt(), comp); }
	void Sort(){ lt.sort(); }
	//void Sort(Compare func) // This will work too.
	void Sort( bool(*func)(const T& , const T&) ) { lt.sort(func); }
	void Reverse() { lt.reverse(); }
	//Getter
	list<T> & GetLt(){ return lt; }

	//Compare
	bool compare_func (const T& first, const T& second)
	{
		return first < second;
	}

	//Summary
	void GetSummary();
	//Detail
	void GetDetail(const string &);

};

template<typename T>
void List<T>::GetSummary()
{
	cout << "Summary[" << endl;
	cout << "empty: \t" << (this->Empty()? "True":"False") << "\t" << endl;
	cout << "size: \t" << this->Size() << endl;
	cout << "max_size: \t" << this->MaxSize() << endl;
	cout << "]" << endl;
}

template<typename T>
void List<T>::GetDetail(const string & s)
{
	cout << s << endl;
	this->GetSummary();
	cout << "Elements[" << endl;
	LstCstIter iv = this->Begin();
	while(iv != this->End())
	{
		cout << "<" << (*iv) << ">" ;
		++iv;
	}
	cout << "]" << endl;
}

#endif /* STL_LISTOPERATIONS_H_ */
