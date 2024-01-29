#include <bits/stdc++.h>
using namespace std;
template <class t = int>
class StackArray
{
    t *a;
    int capacity;
    int pointer;

public:
    StackArray(int n)
    {
        a = new t[n];
        capacity = n;
        pointer = -1;
    }
    int empty()
    {
        return pointer == -1;
    }
    int isFull()
    {
        return pointer == capacity - 1;
    }
    void push(t value)
    {
        if (isFull())
        {
            cout << "Stack is full.\nOverflow\n";
            return;
        }
        a[++pointer] = value;
    }
    void pop()
    {
        if (empty())
        {
            cout << "Stack is empty.\nUnderflow.\n";
            return;
        }
        pointer--;
    }
    t top()
    {
        if (empty())
        {
            cout << "Stack is empty.\n";
            exit(0);
        }
        return a[pointer];
    }
    int size()
    {
        return pointer + 1;
    }
};



int main()
{
    StackArray<> s(5);
    s.push(5);
    s.push(4);
    s.push(90);
    s.push(78);
    s.push(12);
    s.push(8);
    while (s.size())
    {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}