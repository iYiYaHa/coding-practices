//Design your implementation of the linked list. You can choose to use a singly 
//or doubly linked list. 
//A node in a singly linked list should have two attributes: val and next. val 
//is the value of the current node, and next is a pointer/reference to the next 
//node. 
//If you want to use the doubly linked list, you will need one more attribute 
//prev to indicate the previous node in the linked list. Assume all nodes in the 
//linked list are 0-indexed. 
//
// Implement the MyLinkedList class: 
//
// 
// MyLinkedList() Initializes the MyLinkedList object. 
// int get(int index) Get the value of the indexᵗʰ node in the linked list. If 
//the index is invalid, return -1. 
// void addAtHead(int val) Add a node of value val before the first element of 
//the linked list. After the insertion, the new node will be the first node of the 
//linked list. 
// void addAtTail(int val) Append a node of value val as the last element of 
//the linked list. 
// void addAtIndex(int index, int val) Add a node of value val before the indexᵗ
//ʰ node in the linked list. If index equals the length of the linked list, the 
//node will be appended to the end of the linked list. If index is greater than the 
//length, the node will not be inserted. 
// void deleteAtIndex(int index) Delete the indexᵗʰ node in the linked list, if 
//the index is valid. 
// 
//
// 
// Example 1: 
//
// 
//Input
//["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", 
//"deleteAtIndex", "get"]
//[[], [1], [3], [1, 2], [1], [1], [1]]
//Output
//[null, null, null, null, 2, null, 3]
//
//Explanation
//MyLinkedList myLinkedList = new MyLinkedList();
//myLinkedList.addAtHead(1);
//myLinkedList.addAtTail(3);
//myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
//myLinkedList.get(1);              // return 2
//myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
//myLinkedList.get(1);              // return 3
// 
//
// 
// Constraints: 
//
// 
// 0 <= index, val <= 1000 
// Please do not use the built-in LinkedList library. 
// At most 2000 calls will be made to get, addAtHead, addAtTail, addAtIndex and 
//deleteAtIndex. 
// 
// Related Topics Linked List Design 👍 1061 👎 989


//leetcode submit region begin(Prohibit modification and deletion)
class MyLinkedList {

    private Node head;
    private Node tail;

    class Node{
        Node prev;
        Node next;
        int val;

        Node(){}
        Node(int val){this.val = val;}
    }

    public MyLinkedList() {
        head = new Node();
        tail = new Node();
        head.next = tail;
        tail.prev = head;
    }
    
    public int get(int index) {
        Node cur = head.next;
        for(int i = 0;i < index && cur != tail; ++i){
            cur = cur.next;
        }
        return cur == tail ? -1 : cur.val;
    }
    
    public void addAtHead(int val) {
        Node node = new Node(val);
        node.next = head.next;
        head.next = node;
        node.prev = head;
        node.next.prev = node;
    }
    
    public void addAtTail(int val) {
        Node node = new Node(val);
        node.prev = tail.prev;
        node.next = tail;
        tail.prev = node;
        node.prev.next = node;
    }
    
    public void addAtIndex(int index, int val) {
        Node cur = head;
        for(int i = 0;i < index && cur != tail; ++i){
            cur = cur.next;
        }
        if(cur != tail){
            Node node = new Node(val);
            node.next = cur.next;
            cur.next = node;
            node.prev = cur;
            node.next.prev = node;
        }
    }
    public void deleteAtIndex(int index) {
        Node cur = head;
        for(int i = 0;i < index && cur.next != tail; ++i){
            cur = cur.next;
        }
        if(cur.next != tail) {
            Node node = cur.next;
            cur.next = node.next;
            node.next.prev = cur;
            node.next = null;
            node.prev = null;
        }
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
//leetcode submit region end(Prohibit modification and deletion)
