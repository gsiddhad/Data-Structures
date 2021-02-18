/*
 *	rbtree.h / Red Black Tree
 *
 *	Created on: 04-Apr-2015
 *		Author: Gourav Siddhad
 */

#ifndef RBTREE_H_
#define RBTREE_H_

#include "iostream"
#include "myqueue.h"
#include "iomanip"
#include "cstdlib"
using namespace std;

#define RED		0
#define BLACK	1

struct node
{
	int key;
	struct node *left, *right, *p;
	bool color;
};

int total=0;
typedef struct node *NODEPTR;
struct node NIL;
NODEPTR NILPTR = &NIL;

void inorder(NODEPTR x) {
	if (x != NILPTR) {
		inorder(x->left);
		cout<<setw(3)<<x->key<<((x->color==BLACK) ? "B" : "R");
		inorder(x->right);
	}
}

NODEPTR search(NODEPTR root, int k) {
	if (root == NILPTR || root->key == k)
		return root;
	if (k < root->key)
		return search(root->left, k);
	else
		return search(root->right, k);
}

NODEPTR minimum(NODEPTR root) {
	while (root->left != NILPTR)
		root = root->left;
	return root;
}

void leftrotate(NODEPTR *treeroot, NODEPTR x) {
	NODEPTR y = x->right;
	x->right = y->left;
	if (y->left != NILPTR)
		y->left->p = x;
	y->p = x->p;
	if (x->p == NILPTR)
		*treeroot = y;
	else if (x->p->left == x)
		x->p->left = y;
	else
		x->p->right = y;
	y->left = x;
	x->p = y;
}

void rightrotate(NODEPTR *treeroot, NODEPTR y) {
	NODEPTR x = y->left;
	y->left = x->right;
	if (x->right != NILPTR)
		x->right->p = y;
	x->p = y->p;
	if (y->p == NILPTR)
		*treeroot = x;
	else if (y->p->left == y)
		y->p->left = x;
	else
		y->p->right = x;
	x->right = y;
	y->p = x;
}

void rbinsertfixup(NODEPTR *treeroot, NODEPTR z) {
	while (z->p->color == RED) {
		if (z->p == z->p->p->left) {
			NODEPTR y = z->p->p->right;
			if (y->color == RED) {
				z->p->color = BLACK;
				y->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p;
			}
			else {
				if (z == z->p->right) {
					z = z->p;
					leftrotate(treeroot,z);
				}
				z->p->color = BLACK;
				z->p->p->color = RED;
				rightrotate(treeroot,z->p->p);
			}
		}
		else {
			NODEPTR y = z->p->p->left;
			if (y->color == RED) {
				z->p->color = BLACK;
				y->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p;
			}
			else {
				if (z == z->p->left) {
					z = z->p;
					rightrotate(treeroot,z);
				}
				z->p->color = BLACK;
				z->p->p->color = RED;
				leftrotate(treeroot,z->p->p);
			}
		}
	}
	(*treeroot)->color = BLACK;
}

void rbinsert(NODEPTR *treeroot, int z) {
	NODEPTR Z = new node;
	total++;
	Z->key = z;
	NODEPTR y = NILPTR;
	NODEPTR x = *treeroot;
	while (x != NILPTR) {
		y = x;
		if (Z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	Z->p = y;
	if (y == NILPTR)
		*treeroot = Z;
	else if (Z->key < y->key)
		y->left = Z;
	else
		y->right = Z;
	Z->left = NILPTR;
	Z->right = NILPTR;
	Z->color = RED;
	rbinsertfixup(treeroot,Z);
}

void rbtransplant(NODEPTR *treeroot, NODEPTR u, NODEPTR v) {
	if (u->p == NILPTR)
		*treeroot = v;
	else if (u == u->p->left)
		u->p->left = v;
	else
		u->p->right = v;
	v->p = u->p;
}

void rbdeletefixup(NODEPTR *treeroot, NODEPTR x) {
	while (x != *treeroot && x->color == BLACK) {
		if (x == x->p->left) {
			NODEPTR w = x->p->right;
			if (w->color == RED) {
				w->color = BLACK;
				x->p->color = RED;
				leftrotate(treeroot,x->p);
				w = x->p->right;
			}
			if (w->left->color == BLACK && w->right->color == BLACK) {
				w->color = RED;
				x = x->p;
			}
			else {
			 	if (w->right->color == BLACK) {
					w->left->color = BLACK;
					w->color = RED;
					rightrotate(treeroot,w);
					w = x->p->right;
				}
				w->color = x->p->color;
				x->p->color = BLACK;
				w->right->color = BLACK;
				leftrotate(treeroot,x->p);
				x = *treeroot;
			}
		}
		else {
			NODEPTR w = x->p->left;
			if (w->color == RED) {
				w->color = BLACK;
				x->p->color = RED;
				rightrotate(treeroot,x->p);
				w = x->p->left;
			}
			if (w->left->color == BLACK && w->right->color == BLACK) {
				w->color = RED;
				x = x->p;
			}
			else {
				if (w->left->color == BLACK) {
					w->right->color = BLACK;
					w->color = RED;
					leftrotate(treeroot,w);
					w = x->p->left;
				}
				w->color = x->p->color;
				x->p->color = BLACK;
				w->left->color = BLACK;
				rightrotate(treeroot,x->p);
				x = *treeroot;
			}
		}
	}
	x->color = BLACK;
}

void rbdelete(NODEPTR *treeroot, int z) {
	NODEPTR Z = search(*treeroot, z);
	if (Z == NILPTR) {
		cout<<"Node To Be Deleted Not Found ... \n";
		return;
	}
	NODEPTR y = Z;
	int yoc = y->color;
	NODEPTR x;
	if (Z->left == NILPTR) {
		x = Z->right;
		rbtransplant(treeroot,Z,Z->right);
	}
	else if (Z->right == NILPTR) {
		x = Z->left;
		rbtransplant(treeroot,Z,Z->left);
	}
	else {
		y = minimum(Z->right);
		yoc = y->color;
		x = y->right;
		if (y->p == Z)
			x->p = y;
		else {
			rbtransplant(treeroot,y,y->right);
			y->right = Z->right;
			y->right->p = y;
		}
		rbtransplant(treeroot,Z,y);
		y->left = Z->left;
		y->left->p = y;
		y->color = Z->color;
	}
	if (yoc == BLACK)
		rbdeletefixup(treeroot,x);
}

void levelorder(NODEPTR *x) {
	bool flag=1;
	int n=0, enter=1;
	int dist=total*4, pre=total/2;
	myqueue<NODEPTR> q;
	q.enqueue(*x);
	NODEPTR tmp=NILPTR;
	cout<<setw(dist)<<"";
	while (!q.isempty()) {
		tmp=q.dequeue();
		n++;

		if(flag)
			flag=0;
		else
			cout<<setw(pre)<<"";

		if(tmp==NILPTR)
			cout<<"- ";
		else
			cout<<setw(3)<<tmp->key<<((tmp->color==BLACK) ? "B" : "R");
		if(n==enter) {
			cout<<endl<<endl;
			enter*=2;
			n=0;
			pre=dist;
			if(dist==1 || dist==2)
				dist=pre=0;
			dist/=2;
			cout<<setw(dist)<<"";
			flag=1;
		}
		if(tmp != NILPTR)
			q.enqueue(tmp->left);
		if(tmp != NILPTR)
			q.enqueue(tmp->right);
	}
}

#endif /* RBTREE_H_ */
