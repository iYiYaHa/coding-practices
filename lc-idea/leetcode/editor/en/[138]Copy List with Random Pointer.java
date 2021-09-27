//A linked list of length n is given such that each node contains an additional 
//random pointer, which could point to any node in the list, or null. 
//
// Construct a deep copy of the list. The deep copy should consist of exactly n 
//brand new nodes, where each new node has its value set to the value of its 
//corresponding original node. Both the next and random pointer of the new nodes 
//should point to new nodes in the copied list such that the pointers in the original 
//list and copied list represent the same list state. None of the pointers in the 
//new list should point to nodes in the original list. 
//
// For example, if there are two nodes X and Y in the original list, where X.
//random --> Y, then for the corresponding two nodes x and y in the copied list, x.
//random --> y. 
//
// Return the head of the copied linked list. 
//
// The linked list is represented in the input/output as a list of n nodes. 
//Each node is represented as a pair of [val, random_index] where: 
//
// 
// val: an integer representing Node.val 
// random_index: the index of the node (range from 0 to n-1) that the random 
//pointer points to, or null if it does not point to any node. 
// 
//
// Your code will only be given the head of the original linked list. 
//
// 
// Example 1: 
//
// 
//Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
//Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
// 
//
// Example 2: 
//
// 
//Input: head = [[1,1],[2,1]]
//Output: [[1,1],[2,1]]
// 
//
// Example 3: 
//
// 
//
// 
//Input: head = [[3,null],[3,0],[3,null]]
//Output: [[3,null],[3,0],[3,null]]
// 
//
// Example 4: 
//
// 
//Input: head = []
//Output: []
//Explanation: The given linked list is empty (null pointer), so return null.
// 
//
// 
// Constraints: 
//
// 
// 0 <= n <= 1000 
// -10000 <= Node.val <= 10000 
// Node.random is null or is pointing to some node in the linked list. 
// 
// Related Topics Hash Table Linked List 👍 6184 👎 868


//leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/
class Solution {
    public Node copyRandomList(Node head) {
        Map<Node, Node> copieNodeMap = new HashMap<>();
        copieNodeMap.put(null, null);
        return copyRandomList(head, copieNodeMap);
    }

    private Node copyRandomList(Node head, Map<Node, Node> copiedMap){
        if(copiedMap.containsKey(head)){
            return copiedMap.get(head);
        }

        Node copiedHead = new Node(head.val);
        copiedMap.put(head, copiedHead); // Put after the creation of copiedHead to deal with circular reference.
        copiedHead.next = copyRandomList(head.next, copiedMap);
        copiedHead.random = copyRandomList(head.random, copiedMap);
        return copiedHead;
    }
}

class Solution {
    public Node copyRandomList(Node head) {
        if(head == null){
            return null;
        }
        // Put copied nodes after its original nodes.
        Node cur = head;
        while(cur != null){
            Node copied = new Node(cur.val);
            copied.next = cur.next;
            cur.next = copied;
            cur = copied.next;
        }

        // Assign the random links of the copied nodes.
        cur = head;
        while(cur != null){
            Node copied = cur.next;
            if(cur.random != null) {
                copied.random = cur.random.next;
            }
            cur = copied.next;
        }

        // Unlink the copied nodes.
        Node copiedHead = head.next;
        cur = head;
        while(cur != null){
            Node copied = cur.next;
            // Unlink the copied node.
            cur.next = copied.next;

            // Link the copied node with its next node.
            if(copied.next != null) {
                copied.next = copied.next.next;
            }

            cur = cur.next;
        }
        return copiedHead;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
