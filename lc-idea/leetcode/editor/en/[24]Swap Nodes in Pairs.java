//Given a linked list, swap every two adjacent nodes and return its head. You mu
//st solve the problem without modifying the values in the list's nodes (i.e., onl
//y nodes themselves may be changed.) 
//
// 
// Example 1: 
//
// 
//Input: head = [1,2,3,4]
//Output: [2,1,4,3]
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
//Input: head = [1]
//Output: [1]
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the list is in the range [0, 100]. 
// 0 <= Node.val <= 100 
// 
// Related Topics Linked List Recursion 
// 👍 4449 👎 236


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
    public ListNode swapPairs(ListNode head) {
        if(head == null || head.next == null)
            return head;
        ListNode dummy = new ListNode(0, head);
        ListNode prev = dummy;
        while(prev != null && prev.next != null){
            ListNode nodeA = prev.next;
            ListNode nodeB = nodeA.next;
            if(nodeB == null)
                break;
            nodeA.next = nodeB.next;
            nodeB.next = nodeA;
            prev.next = nodeB;
            prev = nodeA;
        }
        return dummy.next;
    }
}
class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head == null || head.next == null)
            return head;
        ListNode cur = head, neighbor = head.next;
        cur.next = swapPairs(neighbor.next);
        neighbor.next = cur;
        return neighbor;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
