#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    void push(int value)
    {
        valStack.push(value);
        if (minStack.empty() || value < minStack.top())
        {
            minStack.push(value);
        }
        else
        {
            minStack.push(minStack.top());
        }
    }
    void pop()
    {
        if (valStack.empty())
        {
            throw runtime_error("Try to pop the top element of an empty stack.");
        }
        valStack.pop();
        minStack.pop();
    }
    int top()
    {
        if (valStack.empty())
        {
            throw runtime_error("Try to obtain the top element of an empty stack.");
        }
        return valStack.top();
    }
    int min()
    {
        if (minStack.empty())
        {
            throw runtime_error("Try to obtain the min value of an empty stack.");
        }
        return minStack.top();
    }

private:
    stack<int> valStack;
    stack<int> minStack;
};

int main()
{
    Solution s;
    s.push(3);
    cout << s.min()<<endl;
    s.push(4);
    cout << s.min()<<endl;
    s.push(2);
    cout << s.min()<<endl;
    s.push(1);
    cout << s.min()<<endl;
    s.pop();
    cout << s.min()<<endl;
    s.pop();
    cout << s.min()<<endl;
    s.push(0);
    cout << s.min()<<endl;
    s.pop();
    s.pop();
    s.pop();
    return 0;
}