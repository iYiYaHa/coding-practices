/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// In-place insertion sort.
class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode dummy(0);
        ListNode *cur = head;
        while (cur != nullptr)
        {
            ListNode *ele = cur;
            cur = cur->next;
            ListNode *prev = &dummy;
            while (prev->next != nullptr && prev->next->val <= ele->val)
            {
                prev = prev->next;
            }
            ele->next = prev->next;
            prev->next = ele;
        }
        return dummy.next;
    }
};


// Copy and sort. Just for comparing.
// Note that the problem is specified to insertion sort.
// ref:https://stackoverflow.com/questions/1525117/whats-the-fastst-algorithm-for-sorting-a-linked-list
class Solution_SortList
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        vector<int> nums;ListNode *cur = head;
        for (cur = head; cur != nullptr; cur = cur->next)
            nums.push_back(cur->val);

        sort(nums.begin(), nums.end());

        cur = head;
        for (int i = 0; i < nums.size(); ++i, cur = cur->next)
        {
            cur->val = nums[i];
        }
        return head;
    }
}
