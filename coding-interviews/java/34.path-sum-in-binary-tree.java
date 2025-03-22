/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
            List<List<Integer>> result = new LinkedList<>();
            pathSumCore(root, sum, new LinkedList<>(), result);
            return result;
    }

    private void pathSumCore(TreeNode root, int sum, LinkedList<Integer> path, List<List<Integer>> result){
        if(root == null)
            return;
        sum -= root.val;
        path.addLast(root.val);
        if(root.left == null && root.right == null && sum == 0){
            result.add(new LinkedList(path));
        }else{
            pathSumCore(root.left,sum,path,result);
            pathSumCore(root.right,sum,path,result);
        }
        path.removeLast();
    }
}