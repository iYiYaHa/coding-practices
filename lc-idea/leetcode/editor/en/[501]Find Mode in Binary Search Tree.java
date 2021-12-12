//Given the root of a binary search tree (BST) with duplicates, return all the 
//mode(s) (i.e., the most frequently occurred element) in it. 
//
// If the tree has more than one mode, return them in any order. 
//
// Assume a BST is defined as follows: 
//
// 
// The left subtree of a node contains only nodes with keys less than or equal 
//to the node's key. 
// The right subtree of a node contains only nodes with keys greater than or 
//equal to the node's key. 
// Both the left and right subtrees must also be binary search trees. 
// 
//
// 
// Example 1: 
//
// 
//Input: root = [1,null,2,2]
//Output: [2]
// 
//
// Example 2: 
//
// 
//Input: root = [0]
//Output: [0]
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [1, 10⁴]. 
// -10⁵ <= Node.val <= 10⁵ 
// 
//
// 
//Follow up: Could you do that without using any extra space? (Assume that the 
//implicit stack space incurred due to recursion does not count). Related Topics 
//Tree Depth-First Search Binary Search Tree Binary Tree 👍 1812 👎 501


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
    private List<Integer> ansList;
    private int maxCnt;
    private int curVal;
    private int curCnt;

    public int[] findMode(TreeNode root) {
        ansList = new LinkedList<>();
        findModeCore(root);
        int[] ans = new int[ansList.size()];
        int ind = 0;
        for (Integer val : ansList) {
            ans[ind++] = val;
        }
        return ans;
    }

    private void findModeCore(TreeNode root) {
        if (root == null) {
            return;
        }
        findModeCore(root.left);
        if (curVal != root.val) {
            curVal = root.val;
            curCnt = 1;
        } else {
            ++curCnt;
        }
        if (curCnt > maxCnt) {
            ansList.clear();
            ansList.add(curVal);
            maxCnt = curCnt;
        } else if (curCnt == maxCnt) {
            ansList.add(curVal);
        }
        findModeCore(root.right);
    }
}
//leetcode submit region end(Prohibit modification and deletion)
