/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class SolutionA
{
public:
    void reorderList(ListNode *head)
    {
        if (head == nullptr)
            return;
        ListNode *slow = head, *fast = head;
        ListNode *cur = head;
        stack<ListNode *> stack;

        // Find the middle element.
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Put the right half into a stack
        while (slow != nullptr)
        {
            stack.push(slow);
            slow = slow->next;
        }

        // Insert the elements of the right part reversely among the left part.
        while (!stack.empty())
        {
            ListNode *tmp = stack.top();
            stack.pop();
            tmp->next = cur->next;
            cur->next = tmp;
            cur = cur->next->next;
        }
        cur->next = nullptr;
    }
};

class SolutionB
{
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *rest = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return rest;
    }

public:
    void reorderList(ListNode *head)
    {
        if (head == nullptr)
            return;
        ListNode *slow = head, *fast = head;
        ListNode *cur = head;
        stack<ListNode *> stack;

        // Find the middle element.
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the right half
        ListNode *reversedList = reverseList(slow);

        // Insert the elements of the right part reversely among the left part.
        while (reversedList != nullptr)
        {
            ListNode *tmp = reversedList->next;

            reversedList->next = cur->next;
            cur->next = reversedList;
            cur = reversedList->next;

            reversedList = tmp;
        }
        cur->next = nullptr;
    }
};

class SolutionC
{
public:
    void reorderList(ListNode *head)
    {
        if (head == nullptr)
            return;
        ListNode *fast = head, *slow = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *halfHead = slow;
        slow = slow->next;
        halfHead->next = nullptr;
        while (slow != nullptr)
        {
            ListNode *tmp = slow->next;
            slow->next = halfHead;
            halfHead = slow;
            slow = tmp;
        }

        ListNode *cur = head;
        while (halfHead != nullptr)
        {
            ListNode *tmp = halfHead->next;
            halfHead->next = cur->next;
            cur->next = halfHead;
            cur = halfHead->next;
            halfHead = tmp;
        }
        cur->next = nullptr;
    }
};
