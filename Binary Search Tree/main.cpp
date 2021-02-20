/* 
 * BST
 * Author : Gourav Siddhad
 * Created on April 10, 2014, 2:12 PM
 */

#include <iostream>
#include "bst.h"
using namespace std;

int main()
{
    BST<int> bst;
    int el = 0;
    int ch = 0;
    do
    {
        cout << "\n Binary Search Tree";
        cout << "\n 01. Insertion";
        cout << "\n 02. Delete";
        cout << "\n\t 21. By Copying";
        cout << "\n\t 22. By Merging";
        cout << "\n 03. Search";
        cout << "\n 04. Display";
        cout << "\n\t 41. Pre-Order";
        cout << "\n\t 42. In-Order";
        cout << "\n\t 43. Post-Order";
        cout << "\n\t 44. Level By Level";
        cout << "\n 05. Count Leaf & Non-Leaf Nodes";
        cout << "\n 06. Display Height Of Tree";
        cout << "\n 07. Create Mirror Image";
        cout << "\n 08. Exit";
        cout << "\n Enter Choice ... ";
        cin >> ch;
        system("clear");
        cout << endl;
        switch (ch)
        {
        case 1:
            cout << " Enter Element To Insert : ";
            cin >> el;
            bst.insert(el);
            break;
        case 21:
            cout << " Enter Element To Delete : ";
            cin >> el;
            try
            {
                bst.delbycopy(el);
            }
            catch (int er)
            {
                if (er == 1)
                    cout << " Empty";
                if (er == 2)
                    cout << " Element Not Found";
            }
            break;
        case 22:
            cout << " Enter Element To Delete : ";
            cin >> el;
            try
            {
                bst.delbymer(el);
            }
            catch (int er)
            {
                if (er == 1)
                    cout << " Empty";
                if (er == 2)
                    cout << " Element Not Found";
            }
            break;
        case 3:
            cout << " Enter Element To Search : ";
            cin >> el;
            try
            {
                if (bst.search(el))
                    cout << " Element Found";
                else
                    cout << " Element Not Found";
            }
            catch (int er)
            {
                if (er == 1)
                    cout << " Empty";
                if (er == 2)
                    cout << " Element Not Found";
            }
            break;
        case 41:
            try
            {
                bst.preorder(bst.root);
            }
            catch (int er)
            {
                if (er == 1)
                    cout << " Empty";
            }
            break;
        case 42:
            try
            {
                bst.inorder(bst.root);
            }
            catch (int er)
            {
                if (er == 1)
                    cout << " Empty";
            }
            break;
        case 43:
            try
            {
                bst.postorder(bst.root);
            }
            catch (int er)
            {
                if (er == 1)
                    cout << " Empty";
            }
            break;
        case 44:
            break;
        case 5:
            int cl, cn;
            cl = cn = 0;
            try
            {
                bst.countnode(bst.root, cl, cn);
                cout << " Leaf Nodes : " << cl;
                cout << "\n Non-Leaf Nodes : " << cn;
            }
            catch (int er)
            {
                if (er == 1)
                    cout << " Empty";
            }
            break;
        case 6:
            try
            {
                int h = bst.height(bst.root);
                cout << " Height : " << h;
            }
            catch (int er)
            {
                if (er == 1)
                    cout << " Empty";
            }
            break;
        case 7:
            try
            {
                bst.mirrorimage(bst.root);
            }
            catch (int er)
            {
                if (er == 1)
                    cout << " Empty";
            }
            break;
        }
        cout << endl;
    } while (ch != 8);
    return 0;
}