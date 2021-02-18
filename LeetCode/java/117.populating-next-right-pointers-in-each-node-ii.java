/*
 * @lc app=leetcode id=117 lang=java
 *
 * [117] Populating Next Right Pointers in Each Node II
 *
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/
 *
 * algorithms
 * Medium (41.80%)
 * Likes:    2263
 * Dislikes: 195
 * Total Accepted:    317.6K
 * Total Submissions: 756.1K
 * Testcase Example:  '[1,2,3,4,5,null,7]'
 *
 * Given a binary tree
 * 
 * 
 * struct Node {
 * ⁠ int val;
 * ⁠ Node *left;
 * ⁠ Node *right;
 * ⁠ Node *next;
 * }
 * 
 * 
 * Populate each next pointer to point to its next right node. If there is no
 * next right node, the next pointer should be set to NULL.
 * 
 * Initially, all next pointers are set to NULL.
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * You may only use constant extra space.
 * Recursive approach is fine, you may assume implicit stack space does not
 * count as extra space for this problem.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: root = [1,2,3,4,5,null,7]
 * Output: [1,#,2,3,#,4,5,7,#]
 * Explanation: Given the above binary tree (Figure A), your function should
 * populate each next pointer to point to its next right node, just like in
 * Figure B. The serialized output is in level order as connected by the next
 * pointers, with '#' signifying the end of each level.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the given tree is less than 6000.
 * -100 <= node.val <= 100
 * 
 * 
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    public Node connect(Node root) {
        if (root == null)
            return null;
        // Connect the two children
        if (root.left != null) {
            root.left.next = root.right;
        }

        // Follow the next chain to find the next node with any child node.
        Node cur = root.next;
        while (cur != null) {
            if (cur.left != null || cur.right != null)
                break;
            cur = cur.next;
        }

        // If found
        if (cur != null) {
            if (root.right != null) {
                root.right.next = cur.left == null ? cur.right : cur.left;
            } else if (root.left != null) {
                root.left.next = cur.left == null ? cur.right : cur.left;
            }
        }
        connect(root.right);
        connect(root.left);
        return root;
    }
}

class Solution {
    public Node connect(Node root) {
        if (root == null)
            return null;
        Node cur = root;
        Node dummy = new Node();
        while (cur != null) {
            Node head = dummy;
            while (cur != null) {
                if (cur.left != null) {
                    head.next = cur.left;
                    head = cur.left;
                }
                if (cur.right != null) {
                    head.next = cur.right;
                    head = cur.right;
                }
                cur = cur.next;
            }
            cur = dummy.next;
            dummy.next = null;
        }
        return root;
    }
}
// @lc code=end
