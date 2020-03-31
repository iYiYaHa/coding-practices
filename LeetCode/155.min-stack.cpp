/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (41.07%)
 * Likes:    2767
 * Dislikes: 280
 * Total Accepted:    429.7K
 * Total Submissions: 1M
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n' +
  '[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 * 
 * 
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 * 
 * 
 * 
 * 
 */

// @lc code=start
class MinStack
{
public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        data.push(x);
        if (minVals.empty() || minVals.top() > x)
            minVals.push(x);
        else
            minVals.push(minVals.top());
    }

    void pop()
    {
        if (minVals.empty() || data.empty())
        {
            throw runtime_error("Try to pop from an empty stack.");
        }
        data.pop();
        minVals.pop();
    }

    int top()
    {
        if (data.empty())
        {
            throw runtime_error("Try to get top of an empty stack.");
        }
        return data.top();
    }

    int getMin()
    {
        if (minVals.empty())
        {
            throw runtime_error("Try to get min of an empty stack.");
        }
        return minVals.top();
    }

private:
    stack<int> data;
    stack<int> minVals;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
