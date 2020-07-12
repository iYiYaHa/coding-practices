/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
    // Merge sort elements between beg and end (excluding end)
    // Not elegant enough
    ListNode *mergeSort(ListNode *beg, ListNode *end)
    {
        if (beg == end)
            return nullptr;

        if (beg->next == end)
            return beg;

        // Find the middle point
        ListNode *slow = beg, *fast = beg;
        while (fast != end && fast->next != end)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Merge sort the left part
        ListNode *left = mergeSort(beg, slow);

        // Merge sort the right part
        ListNode *right = mergeSort(slow, end);

        // Merge both parts
        ListNode dummy(0);
        ListNode *prev = &dummy;
        while (left != slow && right != end)
        {
            if (left->val <= right->val)
            {
                prev->next = left;
                left = left->next;
            }
            else
            {
                prev->next = right;
                right = right->next;
            }
            prev = prev->next;
        }
        while (left != slow)
        {

            prev->next = left;
            left = left->next;
            prev = prev->next;
        }

        while (right != end)
        {

            prev->next = right;
            right = right->next;
            prev = prev->next;
        }
        prev->next = end;
        return dummy.next;
    }

public:
    ListNode *sortList(ListNode *head)
    {
        return mergeSort(head, nullptr);
    }
};

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        // Find the middle point
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Sort the two parts accordingly
        
        ListNode *right = sortList(slow->next);
        // Cut the list off from the middle element
        slow->next = nullptr;

        ListNode *left = sortList(head);

        // Merge two parts.
        ListNode dummy(0);
        ListNode *prev = &dummy;
        while (left && right)
        {
            if (left->val <= right->val)
            {
                prev->next = left;
                left = left->next;
            }
            else
            {
                prev->next = right;
                right = right->next;
            }
            prev = prev->next;
        }
        left = left ? left : right;
        prev->next = left;
        return dummy.next;
    }
};
