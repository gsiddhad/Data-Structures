/*
 * 	myqueue.h / Breadth First Traversal
 *
 *	Created on: 29-Mar-2015
 *	Author: Gourav Siddhad
 */

#ifndef MYQUEUE_H
#define MYQUEUE_H

#define SIZE 20
#include "iostream"
using namespace std;

template <class T>
class myqueue
{
	T arr[SIZE];
	int f, r;

public:
	myqueue()
	{
		f = r = -1;
	}
	void enqueue(T);
	T dequeue();
	bool isempty()
	{
		return f == -1;
	}
};

template <class T>
void myqueue<T>::enqueue(T el)
{
	if ((r == f - 1) || (f == 0 && r == SIZE - 1))
	{
		cout << " Queue Full .. Cannot Enter Further Elements ..\n";
		return;
	}
	if (f == -1 && r == -1) // first element
		f = r = 0;
	else if (r == SIZE - 1) // at last
		r = 0;
	else // normal case
		r++;
	arr[r] = el;
}

template <class T>
T myqueue<T>::dequeue()
{
	T el = arr[f];
	if (f == -1)
	{
		cout << " Queue Empty .. Cannot Dequeue \n";
		throw 1;
	}
	else if (f == r) // only one element
		f = r = -1;
	else if (f == SIZE - 1) // f at last
		f = 0;
	else //normal case
		f++;
	return el;
}

#endif /* MYQUEUE_H */
