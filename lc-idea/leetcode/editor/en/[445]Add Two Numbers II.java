//You are given two non-empty linked lists representing two non-negative 
//integers. The most significant digit comes first and each of their nodes contains a 
//single digit. Add the two numbers and return the sum as a linked list. 
//
// You may assume the two numbers do not contain any leading zero, except the 
//number 0 itself. 
//
// 
// Example 1: 
//
// 
//Input: l1 = [7,2,4,3], l2 = [5,6,4]
//Output: [7,8,0,7]
// 
//
// Example 2: 
//
// 
//Input: l1 = [2,4,3], l2 = [5,6,4]
//Output: [8,0,7]
// 
//
// Example 3: 
//
// 
//Input: l1 = [0], l2 = [0]
//Output: [0]
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in each linked list is in the range [1, 100]. 
// 0 <= Node.val <= 9 
// It is guaranteed that the list represents a number that does not have 
//leading zeros. 
// 
//
// 
// Follow up: Could you solve it without reversing the input lists? 
// Related Topics Linked List Math Stack 👍 2848 👎 216


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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int len1 = getListLen(l1);
        int len2 = getListLen(l2);
        ListNode dummy = new ListNode();
        // Add two lists
        while (len1 > 0 || len2 > 0) {
            int val1 = 0, val2 = 0;
            if (len1 >= len2) {
                val1 = l1.val;
                l1 = l1.next;
                --len1;
            }
            if (len1 + 1 <= len2) {
                val2 = l2.val;
                l2 = l2.next;
                --len2;
            }
            ListNode node = new ListNode(val1 + val2);
            node.next = dummy.next;
            dummy.next = node;
        }

        // Normalize the dummy list
        int carry = 0;
        ListNode cur = dummy.next;
        dummy.next = null;
        while (cur != null) {
            ListNode next = cur.next;
            int sum = cur.val + carry;
            carry = sum / 10;
            cur.val = sum % 10;
            cur.next = dummy.next;
            dummy.next = cur;
            cur = next;
        }
        if(carry != 0){
            ListNode node = new ListNode(carry);
            node.next = dummy.next;
            dummy.next = node;
        }
        return dummy.next;
    }

    private int getListLen(ListNode head) {
        if (head == null) {
            return 0;
        }
        return 1 + getListLen(head.next);
    }
}
//leetcode submit region end(Prohibit modification and deletion)
