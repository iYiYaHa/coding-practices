/*
 * @lc app=leetcode id=155 lang=java
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {

    LinkedList<Integer> stack;
    LinkedList<Integer> min;
    /** initialize your data structure here. */
    public MinStack() {
        stack = new LinkedList<>();
        min = new LinkedList<>();
    }
    
    public void push(int x) {
        stack.addLast(x);
        
        if(!min.isEmpty())
        min.addLast(Math.min(min.getLast(),x));
        else
        min.addLast(x);

    }
    
    public void pop() {
        if(stack.isEmpty())
            throw new RuntimeException("Pop on an empty stack.");
        stack.removeLast();
        min.removeLast();
    }
    
    public int top() {
        if(stack.isEmpty())
            throw new RuntimeException("Top on an empty stack.");
        return stack.getLast();
    }
    
    public int getMin() {
        if(min.isEmpty())
            throw new RuntimeException("Min on an empty stack.");
        return min.getLast();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
// @lc code=end

