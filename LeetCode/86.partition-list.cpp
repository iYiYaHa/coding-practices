/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode dummy(0);
        ListNode *cur = head, *tail1 = &dummy, *tail2 = nullptr;
        while (cur != nullptr)
        {
            if (cur->val >= x)
            {
                if (tail2 != nullptr)
                {
                    tail2->next = cur;
                }
                else
                {
                    tail1->next = cur;
                }
                tail2 = cur;
                cur = cur->next;
                tail2->next = nullptr;
            }
            else
            {
                ListNode *next = cur->next;
                cur->next = tail1->next;
                tail1->next = cur;
                tail1 = cur;
                cur = next;
            }
        }
        return dummy.next;
    }
};

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode less(0), gt(0);
        ListNode *lessPtr = &less, *gtPtr = &gt;
        while (head != nullptr)
        {
            if (head->val < x)
            {
                lessPtr = lessPtr->next = head;
            }
            else
            {
                gtPtr = gtPtr->next = head;
            }
            head=head->next;
        }
        gtPtr->next = nullptr;
        lessPtr->next = gt.next;
        return less.next;
    }
};
