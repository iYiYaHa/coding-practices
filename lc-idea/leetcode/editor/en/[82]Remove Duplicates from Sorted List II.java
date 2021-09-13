//Given the head of a sorted linked list, delete all nodes that have duplicate 
//numbers, leaving only distinct numbers from the original list. Return the linked 
//list sorted as well. 
//
// 
// Example 1: 
//
// 
//Input: head = [1,2,3,3,4,4,5]
//Output: [1,2,5]
// 
//
// Example 2: 
//
// 
//Input: head = [1,1,1,2,3]
//Output: [2,3]
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the list is in the range [0, 300]. 
// -100 <= Node.val <= 100 
// The list is guaranteed to be sorted in ascending order. 
// 
// Related Topics Linked List Two Pointers 👍 3533 👎 132


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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode dummy = new ListNode();
        ListNode tail = dummy;
        while(head != null){
            if(head.next == null || head.next.val != head.val){
                tail.next = head;
                head = head.next;
                tail = tail.next;
                tail.next = null;
            }else{
                while(head.next != null && head.val == head.next.val){
                    head = head.next;
                }
                head = head.next;
            }
        }
        return dummy.next;
    }
}

class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode dummy = new ListNode();
        ListNode prev = dummy;
        ListNode tail = head;
        while(head != null){
            if(tail.next != null && head.val == tail.next.val){
                tail = tail.next;
            }else{
                if(head == tail){
                    prev.next = head;
                    prev = prev.next;
                }
                head = tail.next;
                tail = head;
                prev.next = null;
            }
        }
        return dummy.next;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
