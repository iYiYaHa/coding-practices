//You are given the head of a singly linked-list. The list can be represented 
//as: 
//
// 
//L0 → L1 → … → Ln - 1 → Ln
// 
//
// Reorder the list to be on the following form: 
//
// 
//L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// 
//
// You may not modify the values in the list's nodes. Only nodes themselves may 
//be changed. 
//
// 
// Example 1: 
//
// 
//Input: head = [1,2,3,4]
//Output: [1,4,2,3]
// 
//
// Example 2: 
//
// 
//Input: head = [1,2,3,4,5]
//Output: [1,5,2,4,3]
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the list is in the range [1, 5 * 10⁴]. 
// 1 <= Node.val <= 1000 
// 
// Related Topics Linked List Two Pointers Stack Recursion 👍 3971 👎 168


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
    public void reorderList(ListNode head) {
        if(head == null){
            return;
        }
        ListNode right = cutFromMid(head);
        // Reverse the right part.
        ListNode reversedRight = reverseList(right);

        // Interweave the two parts.
        ListNode cur = head;
        while(reversedRight != null){
            ListNode tmp = reversedRight.next;
            reversedRight.next = cur.next;
            cur.next = reversedRight;
            cur = cur.next.next;
            reversedRight = tmp;
        }
    }

    private ListNode cutFromMid(ListNode head){
        // Find the half and cut.
        ListNode slow = head, fast = head;
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode right = slow.next;
        slow.next = null;
        return right;
    }

    private ListNode reverseList(ListNode head){
        if(head == null || head.next == null){
            return head;
        }
        ListNode restHead = reverseList(head.next);
        head.next.next = head;
        head.next = null;
        return restHead;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
