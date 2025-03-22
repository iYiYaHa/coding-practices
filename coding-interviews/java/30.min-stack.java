class MinStack {
    LinkedList<Integer> stack;
    LinkedList<Integer> minStack;
    /** initialize your data structure here. */
    public MinStack() {
        this.stack = new LinkedList<>();
        this.minStack = new LinkedList<>();
    }
    
    public void push(int x) {
        stack.addLast(x);
        if(minStack.isEmpty()||x<minStack.getLast())
            minStack.addLast(x);
        else
            minStack.addLast(minStack.getLast());
    }
    
    public void pop() {
        if(this.stack.isEmpty()){
            throw new RuntimeException("top() on an empty stack.");
        }
        stack.removeLast();
        minStack.removeLast();
    }
    
    public int top() {
        if(stack.isEmpty()){
            throw new RuntimeException("top() on an empty stack.");
        }
        return stack.getLast();
    }
    
    public int min() {
        if(stack.isEmpty()){
            throw new RuntimeException("min() on an empty stack.");
        }
        return minStack.getLast();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.min();
 */