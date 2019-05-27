/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prevEle = &dummy, *onePastEnd = &dummy;
        int i = 0;
        for (i=0; i < m - 1 && prevEle != nullptr; ++i, prevEle = prevEle->next)
            ;
        for (onePastEnd = prevEle; i < n + 1 && onePastEnd != nullptr; ++i, onePastEnd = onePastEnd->next)
            ;
        ListNode *beg = prevEle->next, *end = onePastEnd;
        prevEle->next = end;
        // Head Insert beg to end after prevEle;
        while (beg != end)
        {
            ListNode *toInsert = beg;
            beg = beg->next;
            toInsert->next = prevEle->next;
            prevEle->next = toInsert;
        }
        return dummy.next;
    }
};

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prevEle = &dummy;
        for(int i = 0;i<m-1;++i)prevEle=prevEle->next;
        ListNode *tail=prevEle->next,*start=tail->next;
        for(int i = m;i<n;++i){
            tail->next=start->next;
            start->next=prevEle->next;
            prevEle->next=start;
            start=tail->next;
        }
        return dummy.next;
    }
};
