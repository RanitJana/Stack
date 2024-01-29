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
    bool empty()
    {
        return pointer == -1;
    }
    bool isFull()
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
template <typename t = int>
class StackLinkedList
{
    struct Node
    {
        t data;
        Node *next;
        Node(int value) : data(value), next(NULL) {}
    } *head;

public:
    StackLinkedList()
    {
        head = NULL;
    }
    void push(t value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    void pop()
    {
        if (head == NULL)
        {
            cout << "Underflow.\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    bool empty()
    {
        return head == NULL;
    }
    t top()
    {
        if (empty())
        {
            cout << "Empty.\n";
            exit(0);
        }
        return head->data;
    }
    int size()
    {
        Node *temp = head;
        int ans = 0;
        while (temp)
        {
            ans++;
            temp = temp->next;
        }
        return ans;
    }
};

int main()
{
    StackLinkedList<char> s;
    s.push('j');
    s.push('c');
    s.push('t');
    s.push('7');
    s.push('1');
    s.push('8');
    while (s.size())
    {
        cout << s.top() << endl;
        s.pop();
    }
    s.pop();
    return 0;
}