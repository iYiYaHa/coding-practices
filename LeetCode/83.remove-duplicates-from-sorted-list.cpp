/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  // No need for dummy node.
public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *cur = head;
    while (cur != nullptr && cur->next != nullptr) {
      if (cur->val == cur->next->val) {
        ListNode *tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
      } else {
        cur = cur->next;
      }
    }
    return head;
  }
};
