/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
  // Using Recursion but don't looks recursive.
  // Use recusive stack to access linked list nodes backwards
  // User head to traverse list forward, and tail to backward.
  bool checkPalindrome(ListNode *&head, ListNode *tail) {
    if (tail == nullptr)
      return true;
    bool res = checkPalindrome(head, tail->next) && (head->val == tail->val);
    head = head->next;
    return res;
  }

public:
  bool isPalindrome(ListNode *head) { return checkPalindrome(head, head); }
};

class SolutionB {
  // Use stack to reversely access the right part elements.
public:
  bool isPalindrome(ListNode *head) {
    // Find the middle element
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    // Push the right part into the stack
    stack<ListNode *> stack;
    for (; slow != nullptr; slow = slow->next) {
      stack.push(slow);
    }

    // Judge equailty between two parts.
    while (!stack.empty()) {
      ListNode *top = stack.top();
      stack.pop();
      if (top->val != head->val)
        return false;
      head = head->next;
    }
    return true;
  }
};

class SolutionC {
  // Reverse the right part without recovering it to the origin form.
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return head;
    ListNode *res = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return res;
  }

public:
  bool isPalindrome(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return true;
    // Find the middle element
    ListNode *slow = head, *fast = head->next;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    // Reverse the right part
    ListNode *rightReverse = reverseList(slow->next);

    // Judge equailty between two parts.
    while (rightReverse != nullptr) {
      if (head->val != rightReverse->val)
        return false;
      rightReverse = rightReverse->next;
      head = head->next;
    }
    return true;
  }
};

class Solution {
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return head;
    ListNode *res = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return res;
  }

public:
  bool isPalindrome(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return true;
    // Find the middle element
    ListNode *slow = head, *fast = head->next;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    // Reverse the right part
    ListNode *rightReverse = reverseList(slow->next);
    bool flag = true;
    ListNode *rightMemeo = rightReverse;
    // Judge equailty between two parts.
    while (rightReverse != nullptr) {
      if (head->val != rightReverse->val) {
        flag = false;
        break;
      }
      rightReverse = rightReverse->next;
      head = head->next;
    }
    slow->next = reverseList(rightMemeo);
    return flag;
  }
};
