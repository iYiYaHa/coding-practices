/*
 * @lc app=leetcode id=707 lang=java
 *
 * [707] Design Linked List
 *
 * https://leetcode.com/problems/design-linked-list/description/
 *
 * algorithms
 * Medium (25.78%)
 * Likes:    742
 * Dislikes: 821
 * Total Accepted:    95.3K
 * Total Submissions: 369.3K
 * Testcase Example:  '["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]\n' +
  '[[],[1],[3],[1,2],[1],[1],[1]]'
 *
 * Design your implementation of the linked list. You can choose to use a
 * singly or doubly linked list.
 * A node in a singly linked list should have two attributes: val and next. val
 * is the value of the current node, and next is a pointer/reference to the
 * next node.
 * If you want to use the doubly linked list, you will need one more attribute
 * prev to indicate the previous node in the linked list. Assume all nodes in
 * the linked list are 0-indexed.
 * 
 * Implement the MyLinkedList class:
 * 
 * 
 * MyLinkedList() Initializes the MyLinkedList object.
 * int get(int index) Get the value of the index^th node in the linked list. If
 * the index is invalid, return -1.
 * void addAtHead(int val) Add a node of value val before the first element of
 * the linked list. After the insertion, the new node will be the first node of
 * the linked list.
 * void addAtTail(int val) Append a node of value val as the last element of
 * the linked list.
 * void addAtIndex(int index, int val) Add a node of value val before the
 * index^th node in the linked list. If index equals the length of the linked
 * list, the node will be appended to the end of the linked list. If index is
 * greater than the length, the node will not be inserted.
 * void deleteAtIndex(int index) Delete the index^th node in the linked list,
 * if the index is valid.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input
 * ["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get",
 * "deleteAtIndex", "get"]
 * [[], [1], [3], [1, 2], [1], [1], [1]]
 * Output
 * [null, null, null, null, 2, null, 3]
 * 
 * Explanation
 * MyLinkedList myLinkedList = new MyLinkedList();
 * myLinkedList.addAtHead(1);
 * myLinkedList.addAtTail(3);
 * myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
 * myLinkedList.get(1);              // return 2
 * myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
 * myLinkedList.get(1);              // return 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= index, val <= 1000
 * Please do not use the built-in LinkedList library.
 * At most 2000 calls will be made to get, addAtHead, addAtTail,  addAtIndex
 * and deleteAtIndex.
 * 
 * 
 */

// @lc code=start
class MyLinkedList {

    private Node head;
    private Node tail;

    /** Initialize your data structure here. */
    public MyLinkedList() {
        head = new Node();
        tail = new Node();
        head.next = tail;
        tail.prev = head;
    }

    /**
     * Get the value of the index-th node in the linked list. If the index is
     * invalid, return -1.
     */
    public int get(int index) {
        Node node = getNodeAtIndex(index);
        return (node == head || node == tail) ? -1 : node.val;
    }

    /**
     * Add a node of value val before the first element of the linked list. After
     * the insertion, the new node will be the first node of the linked list.
     */
    public void addAtHead(int val) {
        Node node = new Node(val);
        node.next = head.next;
        node.next.prev = node;
        node.prev = head;
        head.next = node;
    }

    /** Append a node of value val to the last element of the linked list. */
    public void addAtTail(int val) {
        Node node = new Node(val);
        node.prev = tail.prev;
        node.prev.next = node;
        node.next = tail;
        tail.prev = node;
    }

    /**
     * Add a node of value val before the index-th node in the linked list. If index
     * equals to the length of linked list, the node will be appended to the end of
     * linked list. If index is greater than the length, the node will not be
     * inserted.
     */
    public void addAtIndex(int index, int val) {
        Node nextNode = getNodeAtIndex(index);
        Node node = new Node(val);
        node.next = nextNode;
        node.prev = nextNode.prev;
        node.prev.next = node;
        nextNode.prev = node;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    public void deleteAtIndex(int index) {
        Node node = getNodeAtIndex(index);
        if (node != head && node != tail)
            unlinkNode(node);
    }

    private Node getNodeAtIndex(int index) {
        Node cur = head;
        for (int i = 0; i <= index && cur != tail; ++i) {
            cur = cur.next;
        }
        return cur;
    }

    private void unlinkNode(Node node) {
        Node prev = node.prev;
        Node next = node.next;
        next.prev = prev;
        prev.next = next;
        node.next = null;
        node.prev = null;
    }

    private class Node {
        int val;
        Node prev;
        Node next;

        Node() {

        }

        Node(int val) {
            this.val = val;
        }
    }

}

class MyLinkedList {

    private Node head;
    private Node tail;
    private int size;

    /** Initialize your data structure here. */
    public MyLinkedList() {
        head = null;
        tail = null;
        size = 0;
    }

    /**
     * Get the value of the index-th node in the linked list. If the index is
     * invalid, return -1.
     */
    public int get(int index) {
        Node node = getNode(index);
        return node == null ? -1 : node.val;
    }

    /**
     * Add a node of value val before the first element of the linked list. After
     * the insertion, the new node will be the first node of the linked list.
     */
    public void addAtHead(int val) {
        Node oldHead = head;
        Node node = new Node(null, val, oldHead);
        head = node;
        if (oldHead == null) {
            tail = node;
        } else {
            oldHead.prev = node;
        }
        ++size;
    }

    /** Append a node of value val to the last element of the linked list. */
    public void addAtTail(int val) {
        Node oldTail = tail;
        Node node = new Node(oldTail, val, null);
        tail = node;
        if (oldTail == null) {
            head = node;
        } else {
            oldTail.next = node;
        }
        ++size;
    }

    /**
     * Add a node of value val before the index-th node in the linked list. If index
     * equals to the length of linked list, the node will be appended to the end of
     * linked list. If index is greater than the length, the node will not be
     * inserted.
     */
    public void addAtIndex(int index, int val) {
        if (!isPositionIndex(index))
            return;
        if (index == size) {
            addAtTail(val);
        } else {
            Node node = getNode(index);
            linkBefore(val, node);
            ++size;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    public void deleteAtIndex(int index) {
        if (!isElementIndex(index))
            return;
        Node node = getNode(index);
        unlink(node);
        --size;
    }

    private void unlink(Node node) {
        Node next = node.next;
        Node prev = node.prev;
        node.next = node.prev = null;
        if (prev == null) {
            head = next;
        } else {
            prev.next = next;
        }

        if (next == null) {
            tail = prev;
        } else {
            next.prev = prev;
        }
    }

    private Node linkBefore(int val, Node succ) {
        Node prev = succ.prev;
        Node node = new Node(prev, val, succ);
        succ.prev = node;
        if (prev == null) {
            head = node;
        } else {
            prev.next = node;
        }
        return node;
    }

    private Node getNode(int index) {
        if (!isElementIndex(index))
            return null;
        if (index < (size >> 1)) {
            Node cur = head;
            for (int i = 0; i < index; ++i) {
                cur = cur.next;
            }
            return cur;
        } else {
            Node cur = tail;
            for (int i = size - 1; i > index; --i) {
                cur = cur.prev;
            }
            return cur;
        }
    }

    private void checkPositionIndex(int index) {
        if (!isPositionIndex(index))
            throw new IndexOutOfBoundsException(outOfBoundMsg(index));
    }

    private String outOfBoundMsg(int index) {
        return "Index: " + index + ", Size: " + size;
    }

    private boolean isElementIndex(int index) {
        return 0 <= index && index < size;
    }

    private boolean isPositionIndex(int index) {
        return 0 <= index && index <= size;
    }

    private static class Node {
        Node prev;
        Node next;
        Integer val;

        Node(Integer val) {
            this.val = val;
            this.prev = this.next = null;
        }

        Node(Node prev, Integer val, Node next) {
            this.prev = prev;
            this.val = val;
            this.next = next;
        }
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList(); int param_1 = obj.get(index);
 * obj.addAtHead(val); obj.addAtTail(val); obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList(); int param_1 = obj.get(index);
 * obj.addAtHead(val); obj.addAtTail(val); obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList(); int param_1 = obj.get(index);
 * obj.addAtHead(val); obj.addAtTail(val); obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
// @lc code=end
