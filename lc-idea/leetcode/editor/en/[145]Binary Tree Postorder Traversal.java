//Given the root of a binary tree, return the postorder traversal of its nodes' 
//values. 
//
// 
// Example 1: 
//
// 
//Input: root = [1,null,2,3]
//Output: [3,2,1]
// 
//
// Example 2: 
//
// 
//Input: root = []
//Output: []
// 
//
// Example 3: 
//
// 
//Input: root = [1]
//Output: [1]
// 
//
// Example 4: 
//
// 
//Input: root = [1,2]
//Output: [2,1]
// 
//
// Example 5: 
//
// 
//Input: root = [1,null,2]
//Output: [2,1]
// 
//
// 
// Constraints: 
//
// 
// The number of the nodes in the tree is in the range [0, 100]. 
// -100 <= Node.val <= 100 
// 
//
// 
//Follow up: Recursive solution is trivial, could you do it iteratively? 
//Related Topics Stack Tree Depth-First Search Binary Tree 👍 3343 👎 128


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res = new LinkedList<>();
        postorderTraversal(root, res);
        return res;
    }

    private void postorderTraversal(TreeNode root, List<Integer> res) {
        if (root == null) {
            return;
        }
        postorderTraversal(root.left, res);
        postorderTraversal(root.right, res);
        res.add(root.val);
    }
}

class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res = new LinkedList<>();
        LinkedList<TreeNode> stack = new LinkedList<>();
        if (root != null) {
            stack.push(root);
        }
        while (!stack.isEmpty()) {
            TreeNode cur = stack.pop();
            if (cur == null) {
                cur = stack.pop();
                res.add(cur.val);
            } else {
                stack.push(cur);
                stack.push(null);
                if (cur.right != null) {
                    stack.push(cur.right);
                }
                if (cur.left != null) {
                    stack.push(cur.left);
                }
            }
        }
        return res;
    }
}

class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res = new LinkedList<>();
        LinkedList<TreeNode> stack = new LinkedList<>();
        TreeNode cur = root;
        TreeNode prev = null;
        while(cur != null || !stack.isEmpty()){
            if(cur != null){
                stack.push(cur);
                cur = cur.left;
            } else {
                cur = stack.pop();
                if(cur.right == null || cur.right == prev){
                    res.add(cur.val);
                    prev = cur;
                    cur = null;
                } else{
                    stack.push(cur);
                    cur = cur.right;
                }
            }
        }
        return res;
    }
}

class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res = new LinkedList<>();
        LinkedList<TreeNode> stack = new LinkedList<>();
        TreeNode cur = root;
        TreeNode prev = null;
        while (cur != null || !stack.isEmpty()) {
            if (cur != null) {
                stack.push(cur);
                if (cur.right != null) {
                    stack.push(cur.right);
                }
                cur = cur.left;
            } else {
                cur = stack.pop();
                if ((cur.left == null && cur.right == null) ||
                        (cur.left != null && cur.left == prev) ||
                        (cur.right != null && cur.right == prev)) {
                    res.add(cur.val);
                    prev = cur;
                    cur = null;
                }
            }
        }
        return res;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
