/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// When it comes to tree or linked-list,
// just think about recursion and solve it recursively.

class SolutionA
{
private:
    TreeNode *helper(ListNode *beg, ListNode *end)
    {
        if (beg == nullptr || beg == end)
            return nullptr;
        int len = 0;
        ListNode *cur = beg;
        for (len = 0, cur = beg; cur != end; ++len)
            cur = cur->next;
        int mid = len / 2;
        for (cur = beg; mid != 0; --mid)
            cur = cur->next;
        TreeNode *res = new TreeNode(cur->val);
        res->left = helper(beg, cur);
        res->right = helper(cur->next, end);
        return res;
    }

public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        return helper(head, nullptr);
    }
};

class Solution
{
    // Using fast and slow pointers to find middle pointer.
private:
    TreeNode *helper(ListNode *beg, ListNode *end)
    {
        if (beg == nullptr || beg == end)
            return nullptr;
        int len = 0;
        ListNode *slow = beg, *fast = beg;
        while (fast != end && fast->next != end)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        TreeNode *res = new TreeNode(slow->val);
        res->left = helper(beg, slow);
        res->right = helper(slow->next, end);
        return res;
    }

public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        return helper(head, nullptr);
    }
};
