//Merge two sorted linked lists and return it as a sorted list. The list should 
//be made by splicing together the nodes of the first two lists. 
//
// 
// Example 1: 
//
// 
//Input: l1 = [1,2,4], l2 = [1,3,4]
//Output: [1,1,2,3,4,4]
// 
//
// Example 2: 
//
// 
//Input: l1 = [], l2 = []
//Output: []
// 
//
// Example 3: 
//
// 
//Input: l1 = [], l2 = [0]
//Output: [0]
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in both lists is in the range [0, 50]. 
// -100 <= Node.val <= 100 
// Both l1 and l2 are sorted in non-decreasing order. 
// 
// Related Topics Linked List Recursion 
// 👍 8197 👎 856


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
//class Solution {
//    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
//        if(l1 == null)
//            return l2;
//        if(l2 == null)
//            return l1;
//        if(l1.val <= l2.val){
//            l1.next = mergeTwoLists(l1.next, l2);
//            return l1;
//        }else{
//            l2.next = mergeTwoLists(l1, l2.next);
//            return l2;
//        }
//    }
//}
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode();
        ListNode cur = dummy;
        while(l1 != null && l2 != null){
            if(l1.val <= l2.val){
                cur.next = l1;
                l1 = l1.next;
                cur = cur.next;
            }else{
                cur.next = l2;
                l2 = l2.next;
                cur = cur.next;
            }
        }
        cur.next = l1 == null ? l2 : l1;
        return dummy.next;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
