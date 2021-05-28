/*
 * @lc app=leetcode id=99 lang=java
 *
 * [99] Recover Binary Search Tree
 *
 * https://leetcode.com/problems/recover-binary-search-tree/description/
 *
 * algorithms
 * Hard (42.23%)
 * Likes:    2377
 * Dislikes: 91
 * Total Accepted:    207.8K
 * Total Submissions: 485.4K
 * Testcase Example:  '[1,3,null,null,2]'
 *
 * You are given the root of a binary search tree (BST), where exactly two
 * nodes of the tree were swapped by mistake. Recover the tree without changing
 * its structure.
 * 
 * Follow up: A solution using O(n) space is pretty straight forward. Could you
 * devise a constant space solution?
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,3,null,null,2]
 * Output: [3,1,null,null,2]
 * Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3
 * makes the BST valid.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [3,1,4,null,null,2]
 * Output: [2,1,4,null,null,3]
 * Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2
 * and 3 makes the BST valid.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [2, 1000].
 * -2^31 <= Node.val <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
/**
 * left; TreeNode right; TreeNode() {} TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left
 * = left; this.right = right; } }
 */
class SolutionA {
    public void recoverTree(TreeNode root) {
        // Traverse the tree by in-order and store the values in List
        List<Integer> vals = new LinkedList<>();
        inorder(root, node -> vals.add(node.val));
        // Sort the list
        Collections.sort(vals);
        // Put the sorted values back to the tree.
        Iterator<Integer> iterator = vals.iterator();
        inorder(root, node -> node.val = iterator.next());
    }

    private void inorder(TreeNode root, Consumer<TreeNode> fun) {
        LinkedList<TreeNode> stack = new LinkedList<>();
        while (root != null || !stack.isEmpty()) {
            if (root != null) {
                stack.push(root);
                root = root.left;
            } else {
                root = stack.pop();
                fun.accept(root);
                root = root.right;
            }
        }
    }
}

class SolutionB {
    private TreeNode prev;
    private TreeNode first;
    private TreeNode second;

    public void recoverTree(TreeNode root) {
        prev = null;
        first = null;
        second = null;
        inorderTraversal(root, this::nodeFun);
        swap(first, second);
    }

    private void swap(TreeNode first, TreeNode second){
        if(first == null || second == null)
            return;
        int temp = first.val;
        first.val = second.val;
        second.val = temp;
    }
    
    private void nodeFun(TreeNode root){
        if(root == null)
            return;
        if(prev != null && prev.val > root.val){
            if(first == null){
                first = prev;
                second = root;
            }else{
                second = root;
            }
        }
        prev = root;
    }

    private void inorderTraversal(TreeNode root, Consumer<TreeNode> nodeFun){
        if(root == null)
            return;
        inorderTraversal(root.left, nodeFun);
        nodeFun.accept(root);
        inorderTraversal(root.right, nodeFun);
    }
}

class Solution{
    private TreeNode prev;
    private TreeNode first;
    private TreeNode second;

    public void recoverTree(TreeNode root) {
        prev = null;
        first = null;
        second = null;
        inorderTraversal(root, this::nodeFun);
        swap(first, second);
    }

    private void inorderTraversal(TreeNode root, Consumer<TreeNode> nodeFun){
        if(root == null){
            return;
        }
        TreeNode cur = root;
        while(cur != null){
            if(cur.left == null){
                nodeFun.accept(cur);
                cur = cur.right;
            }else{
                TreeNode prev = cur.left;
                while(prev.right != null && prev.right != cur){
                    prev = prev.right;
                }
                if(prev.right == null){
                    prev.right = cur;
                    cur = cur.left;
                }else{
                    nodeFun.accept(cur);
                    prev.right = null;
                    cur = cur.right;
                }
            }
        }
    }
 
    private void nodeFun(TreeNode node){
        if(node == null)
            return;
        if(prev != null && prev.val > node.val){
            if(first == null){
                first = prev;
            }
            second = node;
        }
        prev = node;
    }
   
    private void swap(TreeNode first, TreeNode second){
        if(first == null || second == null)
            return;
        int tmp = first.val;
        first.val = second.val;
        second.val = tmp;
    }
}