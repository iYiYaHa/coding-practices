/*
 * @lc app=leetcode id=725 lang=cpp
 *
 * [725] Split Linked List in Parts
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//ref: https://leetcode.com/problems/split-linked-list-in-parts/solution/

class SolutionA
{
public:
    vector<ListNode *> splitListToParts(ListNode *root, int k)
    {
        vector<ListNode *> res;

        int len = 0;
        for (ListNode *cur = root; cur != nullptr; cur = cur->next)
            ++len;

        int baseSize = len / k;
        int numOfBasePlusOne = len % k;

        ListNode *cur = root;
        ListNode dummy(0);
        for (int i = 0; i < k; ++i)
        {
            ListNode *start = &dummy;
            for (int j = 0; j < baseSize + (i < numOfBasePlusOne ? 1 : 0); ++j)
            {
                start->next = cur;
                start = cur;
                cur = cur->next;
            }
            start->next = nullptr;
            res.push_back(dummy.next);
        }
        return res;
    }
};

class SolutionB
{
public:
    vector<ListNode *> splitListToParts(ListNode *root, int k)
    {
        vector<ListNode *> res;

        int len = 0;
        for (ListNode *cur = root; cur != nullptr; cur = cur->next)
            ++len;

        int baseSize = len / k;
        int numOfBasePlusOne = len % k;

        ListNode *cur = root;
        ListNode dummy(0);
        for (int i = 0; i < k; ++i)
        {
            ListNode *start = cur;
            for (int j = 0; cur != nullptr && j < baseSize - 1 + (i < numOfBasePlusOne ? 1 : 0); ++j)
            {
                cur = cur->next;
            }
            if (cur != nullptr)
            {
                ListNode *end = cur;
                cur = cur->next;
                end->next = nullptr;
            }
            res.push_back(start);
        }
        return res;
    }
};
