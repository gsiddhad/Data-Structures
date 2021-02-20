/* 
 * Reverse Stack
 * Author : Gourav Siddhad
 * Created on April 8, 2014, 3:06 PM
 */

#include <cstdlib>
#include <iostream>
#include "stst.h"
using namespace std;

int main()
{
    mystack<int> s1;
    int el, ch = 0;
    do
    {
        cout << "\n Stack Implementation ";
        cout << "\n 1. Push";
        cout << "\n 2. Pop";
        cout << "\n 3. Clear";
        cout << "\n 4. Reverse Using Stack";
        cout << "\n 5. Display";
        cout << "\n 6. Exit";
        cout << "\n Enter Choice .. ";
        cin >> ch;
        system("clear");
        cout << endl;
        switch (ch)
        {
        case 1:
            cout << " Enter Element To Push : ";
            cin >> el;
            s1.push(el);
            cout << " Element " << el << " Pushed Succesfully";
            s1.display();
            break;
        case 2:
            try
            {
                el = s1.pop();
                cout << " Element " << el << " Poped Succesfully";
                s1.display();
            }
            catch (int er)
            {
                if (er == 1)
                    cout << " Stack Empty";
            }
            break;
        case 3:
            if (s1.clear())
                cout << " Stack Cleared Succesfully";
            break;
        case 4:
            try
            {
                mystack<int> s2, s3;
                if (s1.isempty())
                    throw 1;
                while (!s1.isempty())
                    s2.push(s1.pop());
                while (!s2.isempty())
                    s3.push(s2.pop());
                while (!s3.isempty())
                    s1.push(s3.pop());
                cout << " Stack Reversed Successfully \n";
                s1.display();
            }
            catch (int er)
            {
                if (er == 1)
                    cout << " Stack Empty";
            }
            break;
        case 5:
            try
            {
                s1.display();
            }
            catch (int er)
            {
                if (er == 1)
                    cout << " Stack Empty";
            }
            break;
        }
        cout << endl;
    } while (ch != 6);
    return 0;
}