/*
 * @lc app=leetcode id=817 lang=cpp
 *
 * [817] Linked List Components
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
    int numComponents(ListNode *head, vector<int> &G)
    {
        unordered_set<int> setG(G.begin(), G.end());
        int cnt = 0;
        for (; head != nullptr; head = head->next)
        {
            // Find the triggering point
            if (setG.count(head->val) && (head->next == nullptr || !setG.count(head->next->val)))
                ++cnt;
        }
        return cnt;
    }
};
