class CQueue {

    private LinkedList<Integer> stackIn;
    private LinkedList<Integer> stackOut;
    public CQueue() {
        stackIn = new LinkedList<>();
        stackOut = new LinkedList<>();
    }
    
    public void appendTail(int value) {
        stackIn.addLast(value);
    }
    
    public int deleteHead() {
        fillOutStackIfEmpty();
        if(stackOut.isEmpty())return -1;
        int val = stackOut.removeLast();
        return val;
    }

    private void fillOutStackIfEmpty(){
        if(stackOut.isEmpty()){
            while(!stackIn.isEmpty()){
                int val = stackIn.removeLast();
                stackOut.addLast(val);
            }
        }
    }
}

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue obj = new CQueue();
 * obj.appendTail(value);
 * int param_2 = obj.deleteHead();
 */