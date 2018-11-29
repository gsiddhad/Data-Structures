/*
 *  pqueue.h / Priority Queue
 *
 *  Created on: 08-Feb-2015
 *      Author: Gourav Siddhad
 */

#ifndef PQUEUE_H_
#define PQUEUE_H_

#define PARENT(i)		(i-1)/2
#define LEFT(i)			(2*i)+1
#define RIGHT(i)		(2*i)+2
#define INF				9999

#include "iostream"
#include "iomanip"
#include "ctime"
using namespace std;

class pqueue
{
	int n, *data, length;
public:
	pqueue();
	void getdata();
	void maxheapify(int);
	void buildmaxheap();
	void display();
	int maximum();
	int extractmax();
	void increasekey(int, int);
	void insert(int);
	~pqueue();
};

pqueue :: pqueue()
{
	length=n=0;
	data=NULL;
}

void pqueue :: getdata()
{
	cout<<"\n Enter Number Of Elements : ";
	cin>>n;
	length=n-1;
	data=new int[2*n];
	cout<<" Enter Elements : ";
	for(int i=0; i<n; i++)
		cin>>data[i];
	cout<<" Data Entered Successfully";
}

void pqueue :: maxheapify(int i)
{
	int l=LEFT(i);
	int r=RIGHT(i);
	int largest=i;
	if(LEFT(i)<=length && data[l]>data[largest])
		largest=l;
	if(RIGHT(i)<=length && data[r]>data[largest])
		largest=r;

	if(largest!=i)
	{
		int temp=data[i];
		data[i]=data[largest];
		data[largest]=temp;
		maxheapify(largest);
	}
}

void pqueue :: buildmaxheap()
{
	for(int i=PARENT(length); i>=0; i--)
		maxheapify(i);
}

void pqueue :: display()
{
	if(n==0)
		cout<<"\n Array Empty";
	else
	{
		cout<<"\n Elements Are : ";
		for(int i=0; i<n; i++)
			cout<<setw(5)<<data[i];
	}
}

int pqueue :: maximum()
{
	return data[0];
}

int pqueue :: extractmax()
{
	int m=data[0];
	data[0]=data[length];
	n--;
	length--;
	maxheapify(0);
	return m;
}

void pqueue :: increasekey(int i, int key)
{
	if(data[i]>key)
		cout<<"\n Error : New Key Is Smaller Than Current Key";
	else
	{
		data[i]=key;
		while(data[PARENT(i)]<data[i] && i>0)
		{
			int temp=data[PARENT(i)];
			data[PARENT(i)]=data[i];
			data[i]=temp;
			i=PARENT(i);
		}
	}
}
void pqueue :: insert(int key)
{
	n++;
	length++;
	data[length]=-INF;
	increasekey(length,key);
}

pqueue :: ~pqueue()
{
	delete[] data;
}

#endif /* PQUEUE_H_ */
