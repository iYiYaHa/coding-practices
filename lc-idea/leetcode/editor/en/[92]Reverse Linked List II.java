//Given the head of a singly linked list and two integers left and right where 
//left <= right, reverse the nodes of the list from position left to position 
//right, and return the reversed list. 
//
// 
// Example 1: 
//
// 
//Input: head = [1,2,3,4,5], left = 2, right = 4
//Output: [1,4,3,2,5]
// 
//
// Example 2: 
//
// 
//Input: head = [5], left = 1, right = 1
//Output: [5]
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the list is n. 
// 1 <= n <= 500 
// -500 <= Node.val <= 500 
// 1 <= left <= right <= n 
// 
//
// 
//Follow up: Could you do it in one pass? Related Topics Linked List 👍 4677 👎 
//235


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
class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        if(head == null) {
            return head;
        }

        ListNode dummy = new ListNode(0, head);
        // find the (left-1)th element.
        ListNode prev = dummy;
        for(int i = 1;i < left && prev != null; ++i){
            prev = prev.next;
        }

        if(prev == null || prev.next == null) {
            return head;
        }
        ListNode eleAtLeft = prev.next;
        // put the elements between left + 1 and right after the (left-1)th element reversely.
        for(int i = left + 1;eleAtLeft.next != null && i <= right; ++i){
            ListNode eleToReverse = eleAtLeft.next;
            eleAtLeft.next = eleToReverse.next;
            eleToReverse.next = prev.next;
            prev.next = eleToReverse;
        }

        return dummy.next;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
