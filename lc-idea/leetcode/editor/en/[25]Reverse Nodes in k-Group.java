//Given a linked list, reverse the nodes of a linked list k at a time and 
//return its modified list. 
//
// k is a positive integer and is less than or equal to the length of the 
//linked list. If the number of nodes is not a multiple of k then left-out nodes, in 
//the end, should remain as it is. 
//
// You may not alter the values in the list's nodes, only nodes themselves may 
//be changed. 
//
// 
// Example 1: 
//
// 
//Input: head = [1,2,3,4,5], k = 2
//Output: [2,1,4,3,5]
// 
//
// Example 2: 
//
// 
//Input: head = [1,2,3,4,5], k = 3
//Output: [3,2,1,4,5]
// 
//
// Example 3: 
//
// 
//Input: head = [1,2,3,4,5], k = 1
//Output: [1,2,3,4,5]
// 
//
// Example 4: 
//
// 
//Input: head = [1], k = 1
//Output: [1]
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the list is in the range sz. 
// 1 <= sz <= 5000 
// 0 <= Node.val <= 1000 
// 1 <= k <= sz 
// 
//
// 
//Follow-up: Can you solve the problem in O(1) extra memory space? Related 
//Topics Linked List Recursion 👍 4901 👎 440


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
    public ListNode reverseKGroup(ListNode head, int k) {
        if(head == null || k <= 0){
            return head;
        }
        ListNode dummy = new ListNode(0, head);
        ListNode prev = dummy;
        while(prev != null){
            // find the tail node.
            ListNode tail = prev;
            for(int i = 0;tail != null && i < k; ++i){
                tail = tail.next;
            }

            // if tail equals null, then there is less than k nodes.
            if(tail == null){
                break;
            }

            // reverse the section between prev and tail.
            ListNode rest = tail.next;
            ListNode tailAfterReverse = prev.next;
            ListNode cur = tailAfterReverse.next;
            while(cur != rest){
                ListNode next = cur.next;
                tailAfterReverse.next = next;
                cur.next = prev.next;
                prev.next = cur;
                cur = next;
            }
            prev = tailAfterReverse;
        }
        return dummy.next;
    }
}

class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        if(head == null || k <= 0){
            return head;
        }
        ListNode dummy = new ListNode(0, head);
        ListNode prev = dummy;
        while(prev != null){
            // find the tail node.
            ListNode tail = prev;
            for(int i = 0;tail != null && i < k; ++i){
                tail = tail.next;
            }

            // if tail equals null, then there is less than k nodes.
            if(tail == null){
                break;
            }

            // reverse the section between prev and tail.
            ListNode tailOfReverseSec = prev.next;
            for (int i = 1; i < k; ++i) {
                ListNode cur = tailOfReverseSec.next;
                tailOfReverseSec.next = cur.next;
                cur.next = prev.next;
                prev.next = cur;
            }
            prev = tailOfReverseSec;
        }
        return dummy.next;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
