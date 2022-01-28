#include <bits/stdc++.h>
using namespace std;

struct myStack
{
    vector<int> v;
    int top;

    void push(int x)
    {
        v.push_back(x);
    }
    int pop()
    {
        int e = v.back();
        v.pop_back();
        return e;
    }
    int peek()
    {
        return v.back();
    }
    bool isempty()
    {
        return v.empty();
    }
};

int main()
{
    myStack s;
    s.push(3);
    s.push(4);
    s.push(5);
    cout << s.peek();
    s.pop();
    cout << "\n"
         << s.peek();
    s.pop();
    cout << "\n"
         << s.peek();
    return 0;
}