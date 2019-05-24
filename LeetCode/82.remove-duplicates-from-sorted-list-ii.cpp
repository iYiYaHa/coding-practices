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
class SolutionA
{
    // Original answer
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode dummy(0);
        ListNode *prev = &dummy, *beg = head,*cur = head;
        while (cur != nullptr)
        {
            while (cur->next != nullptr && cur->val == cur->next->val)
            {
                cur = cur->next;
            }
            if(beg==cur){
                prev->next=beg;
                prev=prev->next;
                prev->next=nullptr;
            }
            
        }
        return dummy.next;
    }
};
class Solution
{
    // It will cause memory leakage.
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        if (head->next->val == head->val)
        {
            while (head->next != nullptr && head->val == head->next->val)
                head = head->next;
            return deleteDuplicates(head->next);
        }
        else
        {
            head->next = deleteDuplicates(head->next);
            return head;
        }
    }
};
