/*
 *	main.cpp / Red Black Tree
 *
 *	Created on: 04-Apr-2015
 *		Author: Gourav Siddhad
 */

#include "rbtree.h"
using namespace std;

int main()

{
	NIL.left = NIL.right = NIL.p = NILPTR;
	NIL.color = BLACK;
	NODEPTR tree = NILPTR;
	int n=1, num=0;
	while (n)
	{
		cout<<	"\n\t\t\t\t\t\t Red Black Tree Implementation"
				"\n 01. Insert"
				"\n 02. Delete"
				"\n 03. Inorder Traversal"
				"\n 04. Display Tree"
				"\n 00. Exit"
				"\n Enter Choice ... ";
		cin>>n;
		switch(n)
		{
		case 1:
			cout<<" Enter Number To Be Inserted : ";
			cin>>num;
			rbinsert(&tree, num);
			break;
		case 2:
			cout<<" Enter The Number To Be Deleted : ";
			cin>>num;
			rbdelete(&tree, num);
			break;
		case 3:
			inorder(tree);
			cout<<endl;
			break;
		case 4:
			cout<<" Tree Is : "<<endl;
			levelorder(&tree);
			break;
		case 0:
			break;
		default:
			cout<<" Enter Valid Option ... Retry .. ";
		}
	}
	return 0;
}
