/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class SolutionA {
  // Original answer
public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return head;
    ListNode dummy(0);
    ListNode *prev = &dummy, *slow = head, *fast = head;
    while (fast != nullptr) {
      if (fast->next != nullptr && fast->val == fast->next->val) {
        fast = fast->next;
      } else {
        if (slow == fast) {
          prev->next = fast;
          prev = prev->next;
        }
        slow = fast = fast->next;
        prev->next = nullptr;
      }
    }
    return dummy.next;
  }
};
class SolutionB {
  // Recursive
  // It will cause memory leakage.
public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return head;
    if (head->val == head->next->val) {
      while (head->next != nullptr && head->val == head->next->val)
        head = head->next;
      return deleteDuplicates(head->next);
    } else {
      head->next = deleteDuplicates(head->next);
      return head;
    }
  }
};
