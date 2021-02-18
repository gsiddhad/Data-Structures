/*
 *  main.cpp / Priority Queue
 *
 *  Created on: 08-Feb-2015
 *      Author: Gourav Siddhad
 */

#include "pqueue.h"
using namespace std;

int main()
{
	pqueue array;
	array.getdata();
	array.buildmaxheap();
	array.display();
	int ch, i, key, max;
	ch=i=key=max=0;
	do{
		cout<<"\n 1. Re-Enter Array";
		cout<<"\n 2. Display Maximum Value";
		cout<<"\n 3. Extract Maximum Value";
		cout<<"\n 4. Increase Key //Experimental";
		cout<<"\n 5. Insert Element";
		cout<<"\n 6. Display Array";
		cout<<"\n 0. Exit";
		cout<<"\n Enter Choice... ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			array.getdata();
			array.buildmaxheap();
			break;
		case 2:
			cout<<" Maximum Element In The Array Is : "<<array.maximum();
			break;
		case 3:
			max=array.extractmax();
			cout<<" Maximum Element In The Array Is : "<<max;
			break;
		case 4:
			cout<<" Enter The Position For The Key To Be Increased : ";
			cin>>i;
			cout<<" Enter Key To Be Inserted : ";
			cin>>key;
			array.increasekey(i, key);
			break;
		case 5:
			cout<<" Enter Key To Be Inserted : ";
			cin>>key;
			array.insert(key);
			break;
		case 6:
			break;
		case 0:
			break;
		default:
			cout<<" Enter Valid Option";
		}
		if(ch>0 && ch<7)
			array.display();
	}while(ch>0);
	return 0;
}
