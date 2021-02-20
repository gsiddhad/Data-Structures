/* 
 * queu.h / Queue
 * Author: Gourav Siddhad
 * Created on April 9, 2014, 12:33 AM
 */

#ifndef QUEU_H
#define QUEU_H
#define SIZE 10
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
    void enqueue();
    void dequeue();
    void display();
};

template <class t>
void myqueue<t>::enqueue()
{
    if ((r == f - 1) || (f == 0 && r == SIZE - 1))
    {
        cout << " Queue Full .. Cannot Enter Further Elements ..\n";
        return;
    }
    cout << " Enter Element : ";
    int el;
    cin >> el;
    if (f == -1 && r == -1) // first element
        f = r = 0;
    else if (r == SIZE - 1) // at last
        r = 0;
    else // normal case
        r++;
    arr[r] = el;
}

template <class t>
void myqueue<t>::dequeue()
{
    int el = arr[f];
    if (f == -1)
    {
        cout << " Queue Empty .. Cannot Dequeue \n";
        return;
    }
    else if (f == r) // only one element
        f = r = -1;
    else if (f == SIZE - 1) // f at last
        f = 0;
    else //normal case
        f++;
    cout << " Element Dequeed : " << el;
    cout << endl;
}

template <class t>
void myqueue<t>::display()
{
    if (f == -1)
    {
        cout << " Queue Empty \n";
        return;
    }

    if (f <= r)
        for (int i = f; i <= r; i++)
            cout << " " << arr[i];
    else
    {
        for (int i = r; i < SIZE; i++)
            cout << " " << arr[i];
        for (int i = 0; i <= f; i++)
            cout << " " << arr[i];
    }
    cout << endl;
}

#endif /* QUEU_H */