#include <bits/stdc++.h>
using namespace std;
template <class t = int>

// stack using array
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

// stack using linked list
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

// conversions
int priority(char ch)
{

    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/' || ch == '%')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    return -1;
}

// infix to postfix
string infixToPostfix(string word) // assumig valid expression
{
    string ans = "";
    stack<char> s;
    for (int i = 0; i < word.size(); ++i)
    {
        char ch = word[i];
        if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (s.top() != '(')
            {
                ans.push_back(s.top());
                s.pop();
            }
            s.pop();
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^')
        {
            while (!s.empty() && s.top() != '(' && priority(ch) <= priority(s.top()))
            {
                ans.push_back(s.top());
                s.pop();
            }
            s.push(ch);
        }
        else if (ch != ' ')
        {
            ans.push_back(ch);
        }
    }
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

// infix to prefix
string infixToPrefix(string word) // assumig that given string is valid
{
    string ans = "";
    stack<char> s;
    reverse(word.begin(), word.end());
    for (int i = 0; i < word.size(); i++)
    {
        char ch = word[i];

        if (ch == ')')
        {
            s.push(ch);
        }
        else if (ch == '(')
        {
            while (s.top() != ')')
            {
                ans.push_back(s.top());
                s.pop();
            }
            s.pop();
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^')
        {
            while (!s.empty() && s.top() != ')' && priority(ch) < priority(s.top()))
            {
                ans.push_back(s.top());
                s.pop();
            }
            s.push(ch);
        }
        else if (ch != ' ')
        {
            ans.push_back(ch);
        }
    }
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// labda expression-nameless function
unordered_map<char, function<int(int, int)>> m = {
    {'+', [&](int a, int b)
     { return a + b; }},
    {'-', [&](int a, int b)
     { return a - b; }},
    {'*', [&](int a, int b)
     { return a * b; }},
    {'/', [&](int a, int b)
     { return a / b; }},
    {'%', [&](int a, int b)
     { return a % b; }},
    {'^', [&](int a, int b)
     { return pow(a, b); }},
};

// solve postfix
int postfixEvaluation(string word)
{
    stack<int> s;

    for (int i = 0; i < word.size(); i++)
    {
        char ch = word[i];
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^')
        {
            int op2 = s.top();
            s.pop();
            int op1 = s.top();
            s.pop();
            s.push(m[ch](op1, op2));
        }
        else if (ch != ' ')
        {
            s.push(ch - '0');
        }
    }
    return s.top();
}

// solve prefix
int pretfixEvaluation(string word)
{
    stack<int> s;
    reverse(word.begin(), word.end());

    for (int i = 0; i < word.size(); i++)
    {
        char ch = word[i];
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^')
        {
            int op1 = s.top();
            s.pop();
            int op2 = s.top();
            s.pop();
            s.push(m[ch](op1, op2));
        }
        else if (ch != ' ')
        {
            s.push(ch - '0');
        }
    }
    return s.top();
}

int main()
{
    string s;
    getline(cin, s);
    cout << pretfixEvaluation(s);
    return 0;
}