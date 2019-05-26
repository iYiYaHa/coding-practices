/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
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
    ListNode *middleNode(ListNode *head)
    {
        int len = 0;
        ListNode *cur = head;
        for(;cur!=nullptr;cur=cur->next,++len);
        for(cur=head,len=len/2;len!=0;--len,cur=cur->next);
        return cur;
    }
};
