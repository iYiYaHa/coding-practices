/*
 * @lc app=leetcode id=155 lang=java
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {

    private Node head;

    public MinStack() {
        head = null;    
    }
    
    public void push(int val) {
        Node node = new Node(val, head == null ? val : Math.min(head.min, val));
        if (head == null) {
            head = node;
        } else {
            node.next = head;
            head = node;
        }
    }
    
    public void pop() {
        if (head == null) {
            throw new RuntimeException("The stack is empty...");
        }
        head = head.next;
    }
    
    public int top() {
        if (head == null) {
            throw new RuntimeException("The stack is empty...");
        }
        return head.val;
    }
    
    public int getMin() {
        if (head == null) {
            throw new RuntimeException("The stack is empty...");
        }
        return head.min;
    }

    private class Node {
        private int val;

        private int min;

        private Node next;

        public Node(int val, int min) {
            this.val = val;
            this.min = min;
        }
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
// @lc code=end

