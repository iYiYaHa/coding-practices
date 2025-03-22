/*
 * @lc app=leetcode id=138 lang=java
 *
 * [138] Copy List with Random Pointer
 *
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (35.61%)
 * Likes:    3908
 * Dislikes: 722
 * Total Accepted:    457.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[7,null],[13,0],[11,4],[10,2],[1,0]]'
 *
 * A linked list is given such that each node contains an additional random
 * pointer which could point to any node in the list or null.
 * 
 * Return a deep copy of the list.
 * 
 * The Linked List is represented in the input/output as a list of n nodes.
 * Each node is represented as a pair of [val, random_index] where:
 * 
 * 
 * val: an integer representing Node.val
 * random_index: the index of the node (range from 0 to n-1) where random
 * pointer points to, or null if it does not point to any node.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [[1,1],[2,1]]
 * Output: [[1,1],[2,1]]
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * 
 * Input: head = [[3,null],[3,0],[3,null]]
 * Output: [[3,null],[3,0],[3,null]]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: head = []
 * Output: []
 * Explanation: Given linked list is empty (null pointer), so return null.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * -10000 <= Node.val <= 10000
 * Node.random is null or pointing to a node in the linked list.
 * The number of nodes will not exceed 1000.
 * 
 * 
 */

// @lc code=start
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
        Map<Node, Node> copyMap = new HashMap<>();
        copyMap.put(null, null);
        return getCopiedNode(head, copyMap);
    }

    private Node getCopiedNode(Node node, Map<Node, Node> copyMap) {
        if (copyMap.containsKey(node)) {
            return copyMap.get(node);
        } else {
            Node copy = new Node(node.val);
            copyMap.put(node, copy);
            copy.next = getCopiedNode(node.next, copyMap);
            copy.random = getCopiedNode(node.random, copyMap);
            return copy;
        }
    }
}

class Solution {
    public Node copyRandomList(Node head) {
        Queue<Node> queue = new LinkedList<>();
        Map<Node, Node> copyMap = new HashMap<>();
        copyMap.put(null, null);
        if (head != null) {
            queue.add(head);
            copyMap.put(head, new Node(head.val));
        }
        while (!queue.isEmpty()) {
            Node front = queue.remove();
            Node copy = copyMap.get(front);
            if (!copyMap.containsKey(front.next)) {
                queue.add(front.next);
                Node nextCopy = new Node(front.next.val);
                copyMap.put(front.next, nextCopy);
            }

            if (!copyMap.containsKey(front.random)) {
                queue.add(front.random);
                Node randomCopy = new Node(front.random.val);
                copyMap.put(front.random, randomCopy);
            }

            copy.next = copyMap.get(front.next);
            copy.random = copyMap.get(front.random);
        }
        return copyMap.get(head);
    }
}

class Solution {
    public Node copyRandomList(Node head) {
        if (head == null)
            return null;
        // Create copied nodes
        Node cur = head;
        while (cur != null) {
            Node copy = new Node(cur.val);
            copy.next = cur.next;
            cur.next = copy;
            cur = copy.next;
        }

        // Adjust random pointers
        cur = head;
        while (cur != null) {
            Node copy = cur.next;
            if (cur.random != null)
                copy.random = cur.random.next;
            cur = copy.next;
        }

        // Unlink the copied list
        Node copyHead = head.next;
        cur = head;
        while (cur != null) {
            Node copy = cur.next;
            cur.next = copy.next;
            if (cur.next != null)
                copy.next = copy.next.next;
            cur = cur.next;
        }
        return copyHead;
    }
}

class Solution {
    public Node copyRandomList(Node head) {
        Map<Node, Node> copyMap = new HashMap<>();
        copyMap.put(null, null);
        Node cur = head;
        while (cur != null) {
            copyMap.put(cur, new Node(cur.val));
            cur = cur.next;
        }

        cur = head;
        while (cur != null) {
            Node copied = copyMap.get(cur);
            copied.next = copyMap.get(cur.next);
            copied.random = copyMap.get(cur.random);
            cur = cur.next;
        }

        return copyMap.get(head);
    }
}
// @lc code=end
