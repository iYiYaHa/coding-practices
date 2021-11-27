//Given a binary tree 
//
// 
//struct Node {
//  int val;
//  Node *left;
//  Node *right;
//  Node *next;
//}
// 
//
// Populate each next pointer to point to its next right node. If there is no 
//next right node, the next pointer should be set to NULL. 
//
// Initially, all next pointers are set to NULL. 
//
// 
// Example 1: 
//
// 
//Input: root = [1,2,3,4,5,null,7]
//Output: [1,#,2,3,#,4,5,7,#]
//Explanation: Given the above binary tree (Figure A), your function should 
//populate each next pointer to point to its next right node, just like in Figure B. 
//The serialized output is in level order as connected by the next pointers, with 
//'#' signifying the end of each level.
// 
//
// Example 2: 
//
// 
//Input: root = []
//Output: []
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [0, 6000]. 
// -100 <= Node.val <= 100 
// 
//
// 
// Follow-up: 
//
// 
// You may only use constant extra space. 
// The recursive approach is fine. You may assume implicit stack space does not 
//count as extra space for this problem. 
// 
// Related Topics Tree Depth-First Search Breadth-First Search Binary Tree 👍 30
//94 👎 222


//leetcode submit region begin(Prohibit modification and deletion)
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
        LinkedList<Node> queue = new LinkedList<>();
        if (root != null) {
            queue.add(root);
        }
        while (!queue.isEmpty()) {
            Node prev = null;
            int layerSize = queue.size();
            for (int i = 0; i < layerSize; ++i) {
                Node cur = queue.poll();
                if (prev != null) {
                    prev.next = cur;
                }
                prev = cur;
                if (cur.left != null) {
                    queue.offer(cur.left);
                }
                if (cur.right != null) {
                    queue.offer(cur.right);
                }
            }
        }
        return root;
    }
}

class Solution {
    public Node connect(Node root) {
        if (root == null) {
            return null;
        }

        // Connect two children
        if (root.left != null) {
            root.left.next = root.right;
        }

        // Follow the next chain to find the next node with any child node.
        Node cur = root.next;
        while (cur != null && (cur.left == null && cur.right == null)) {
            cur = cur.next;
        }

        // Connect if found.
        if (cur != null) {
            Node sibling = cur.left != null ? cur.left : cur.right;
            if (root.right != null) {
                root.right.next = sibling;
            } else if (root.left != null) {
                root.left.next = sibling;
            }
        }

        connect(root.right);
        connect(root.left);
        return root;
    }
}

class Solution {
    public Node connect(Node root) {
        if (root == null) {
            return null;
        }

        Node cur = root;
        Node dummy = new Node();
        while (cur != null) {
            Node prev = dummy;
            while (cur != null) {
                if (cur.left != null) {
                    prev.next = cur.left;
                    prev = prev.next;
                }
                if (cur.right != null) {
                    prev.next = cur.right;
                    prev = prev.next;
                }
                cur = cur.next;
            }
            cur = dummy.next;
            dummy.next = null;
        }
        return root;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
