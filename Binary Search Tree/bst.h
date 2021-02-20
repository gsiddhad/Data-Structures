/* 
 * bst.h / BST
 * Author : Gourav Siddhad
 * Created on April 16, 2014, 12:17 AM
 */

#ifndef BST_H
#define BST_H
#include <cstdio>
#include <cstdlib>
using namespace std;

template <class T>
class BSTNode
{
public:
    BSTNode()
    {
        info = 0;
        left = right = NULL;
    }
    T info;
    BSTNode<T> *left, *right;
};

template <class T>
class BST
{
public:
    BSTNode<T> *root;
    BST()
    {
        root = NULL;
    }
    bool isempty()
    {
        return root == NULL;
    }
    void visit(BSTNode<T> *p)
    {
        cout << " " << p->info;
    }
    void insert(T);
    void delbycopy(T);
    void delbymer(T);
    bool search(T);
    void preorder(BSTNode<T> *);
    void inorder(BSTNode<T> *);
    void postorder(BSTNode<T> *);
    void countnode(BSTNode<T> *, int &, int &);
    int height(BSTNode<T> *);
    void mirrorimage(BSTNode<T> *);
    void clear(BSTNode<T> *);
    T max(T, T);
    ~BST()
    {
        clear(root);
    }
};

template <class T>
void BST<T>::insert(T el)
{
    BSTNode<T> *t;
    t = new BSTNode<T>();
    t->info = el;
    if (root == NULL)
    {
        root = t;
    }
    else
    {
        BSTNode<T> *q, *p;
        q = p = root;
        while (p != NULL)
        {
            q = p;
            if (p->info < el)
                p = p->right;
            else
                p = p->left;
        }
        if (q->info < el)
            q->right = t;
        else
            q->left = t;
    }
}

template <class T>
void BST<T>::delbycopy(T el)
{
    BSTNode<T> *p = root, *q = NULL, *t = NULL;

    if (root == NULL)
        throw 1;
    while (el != p->info && p != NULL)
    {
        q = p;
        if (el < p->info)
            p = p->left;
        else
            p = p->right;
    }
    if (p->left != NULL && p->right != NULL)
    {
        q = p;
        t = p->left;
        while (t->right != NULL)
        {
            q = t;
            t = t->right;
        }
        p->info = t->info;
        q->right = t->left;
        t->left = NULL;
        delete t;
    }
    else if (p->left == NULL && p->right == NULL)
    {
    }
    if (p == NULL)
        throw 2;
    //delete p;
}

template <class T>
void BST<T>::delbymer(T el)
{
    if (root == NULL)
        throw 1;

    throw 2;
}

template <class T>
bool BST<T>::search(T el)
{
    if (isempty())
        throw 1;
    BSTNode<T> *p = root;
    while (p != NULL)
    {
        if (p->info == el)
            return true;
        if (p->info < el)
            p = p->right;
        else
            p = p->left;
    }
    return false;
}

template <class T>
void BST<T>::preorder(BSTNode<T> *p)
{
    if (isempty())
        throw 1;
    if (p != NULL)
    {
        visit(p);
        preorder(p->left);
        preorder(p->right);
    }
}

template <class T>
void BST<T>::inorder(BSTNode<T> *p)
{
    if (isempty())
        throw 1;
    if (p != NULL)
    {
        inorder(p->left);
        visit(p);
        inorder(p->right);
    }
}

template <class T>
void BST<T>::postorder(BSTNode<T> *p)
{
    if (isempty())
        throw 1;
    if (p != NULL)
    {
        postorder(p->left);
        postorder(p->right);
        visit(p);
    }
}

template <class T>
void BST<T>::countnode(BSTNode<T> *p, int &cl, int &cn)
{
    if (isempty())
        throw 1;
    while (p != NULL)
    {
        if (p->left == NULL && p->right == NULL)
            cl++;
        else
            cn++;
        countnode(p->left, cl, cn);
        countnode(p->right, cl, cn);
    }
}

template <class T>
int BST<T>::height(BSTNode<T> *p)
{
    if (isempty())
        throw 1;
    if (p == NULL)
        return 0;
    else
        return (1 + max(height(p->left), height(p->right)));
}

template <class T>
void BST<T>::mirrorimage(BSTNode<T> *p)
{
    if (isempty())
        throw 1;
    if (p != NULL)
    {
        BSTNode<T> *t = p->left;
        p->left = p->right;
        p->right = t;
        mirrorimage(p->left);
        mirrorimage(p->right);
    }
}

template <class T>
void BST<T>::clear(BSTNode<T> *p)
{
    if (p->left == NULL && p->right == NULL)
        delete p;
    clear(p->left);
    clear(p->right);
}

template <class T>
T BST<T>::max(T a, T b)
{
    if (a > b)
        return a;
    else
        return b;
}

#endif /* BST_H */