//Given the head of a singly linked list where elements are sorted in ascending 
//order, convert it to a height balanced BST. 
//
// For this problem, a height-balanced binary tree is defined as a binary tree 
//in which the depth of the two subtrees of every node never differ by more than 1.
// 
//
// 
// Example 1: 
//
// 
//Input: head = [-10,-3,0,5,9]
//Output: [0,-3,9,-10,null,5]
//Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the 
//shown height balanced BST.
// 
//
// Example 2: 
//
// 
//Input: head = []
//Output: []
// 
//
// Example 3: 
//
// 
//Input: head = [0]
//Output: [0]
// 
//
// Example 4: 
//
// 
//Input: head = [1,3]
//Output: [3,1]
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in head is in the range [0, 2 * 10⁴]. 
// -10⁵ <= Node.val <= 10⁵ 
// 
// Related Topics Linked List Divide and Conquer Tree Binary Search Tree Binary 
//Tree 👍 3765 👎 104


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
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
    public TreeNode sortedListToBST(ListNode head) {
        if(head == null){
            return null;
        }
        if(head.next == null){
            return new TreeNode(head.val);
        }

        // Find the element between the middle node.
        ListNode dummy = new ListNode(0, head);
        ListNode slow = dummy, fast = dummy.next;
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }

        // Split the middle element from the list
        ListNode ele = slow.next;
        slow.next = null;
        ListNode rightHead = ele.next;
        ele.next = null;

        // Convert the parts around the middle element separately.
        return new TreeNode(ele.val, sortedListToBST(head), sortedListToBST(rightHead));
    }
}
//leetcode submit region end(Prohibit modification and deletion)
