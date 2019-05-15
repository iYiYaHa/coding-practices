/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{

public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *newHead = new ListNode(0), *newEnd = newHead;
        ListNode *head1 = l1, *head2 = l2;
        while (head1 != nullptr && head2 != nullptr)
        {

            if (head1->val < head2->val)
            {
                newEnd->next = head1;
                head1 = head1->next;
            }
            else
            {
                newEnd->next = head2;
                head2 = head2->next;
            }
            newEnd = newEnd->next;
        }
        head1 = head1 == nullptr ? head2 : head1;
        newEnd->next = head1;
        return newHead->next;
    }
};

class SolutionA
{

public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        if (l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
