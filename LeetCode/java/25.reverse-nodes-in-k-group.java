/*
 * @lc app=leetcode id=25 lang=java
 *
 * [25] Reverse Nodes in k-Group
 */

// @lc code=start
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
        if(head == null||k<=1)
            return head;
        ListNode dummy = new ListNode(0, head);
        ListNode prevRange = dummy;
        while(prevRange.next != null){
            ListNode rangeEnd = prevRange;
            for(int i = 0;i<k && rangeEnd != null;++i){rangeEnd = rangeEnd.next;}
            if(rangeEnd == null)break;

            ListNode prev = prevRange.next;
            for(int i = 0;i<k-1;++i){
                ListNode ele = prev.next;
                prev.next = ele.next;
                ele.next=prevRange.next;
                prevRange.next=ele;
            }
            prevRange = prev;
        }
        return dummy.next;
    }

    private void printList(ListNode head){
        while(head != null){
            System.out.print(head.val+" ");
            head = head.next;
        }
        System.out.println();
    }
}

class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        if(head == null||k<=1)
            return head;

        ListNode cur = head;
        for(int i = 0;i<k-1 && cur != null;++i){cur = cur.next;}
        if(cur == null)return head;

        ListNode rest = cur.next;
        cur = head;
        head = reverseKGroup(rest, k);
        for(int i = 0;i<k;++i){
            ListNode tmp = cur.next;
            cur.next=head;
            head = cur;
            cur = tmp;
        }
        return head;

    }
}
// @lc code=end

