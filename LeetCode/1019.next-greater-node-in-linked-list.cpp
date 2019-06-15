/*
 * @lc app=leetcode id=1019 lang=cpp
 *
 * [1019] Next Greater Node In Linked List
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// ref:https://leetcode.com/problems/next-greater-node-in-linked-list/discuss/265508/JavaC%2B%2BPython-Next-Greater-Element
class SolutionA
{
    // Time Complexity: O(n^2)
public:
    vector<int> nextLargerNodes(ListNode *head)
    {
        vector<int> res;
        for (ListNode *cur = head; cur != nullptr; cur = cur->next)
        {
            int maxVal = cur->val;
            for (ListNode *bigger = cur->next; bigger != nullptr; bigger = bigger->next)
            {
                if (bigger->val > maxVal)
                {
                    maxVal = bigger->val;
                    break;
                }
            }
            res.push_back(maxVal > cur->val ? maxVal : 0);
        }
        return res;
    }
};

class SolutionB
{
    // Time Complexity: O(n)
    // ref:https://leetcode.com/problems/next-greater-node-in-linked-list/discuss/265548/C%2B%2B-O(n)-stack
public:
    vector<int> nextLargerNodes(ListNode *head)
    {
        vector<int> res;
        stack<int> stack;
        for (ListNode *cur = head; cur != nullptr; cur = cur->next)
            res.push_back(cur->val);
        for (int i = res.size() - 1; i >= 0; --i)
        {
            int val = res[i];
            while (!stack.empty() && stack.top() <= res[i])
                stack.pop();
            res[i] = stack.empty() ? 0 : stack.top();
            stack.push(val);
        }
        return res;
    }
};

class SolutionC
{
    // ref:https://leetcode.com/problems/next-greater-node-in-linked-list/discuss/265508/JavaC%2B%2BPython-Next-Greater-Element
public:
    vector<int> nextLargerNodes(ListNode *head)
    {
        vector<int> res, stack;
        for (ListNode *node = head; node; node = node->next)
        {
            while (stack.size() && res[stack.back()] < node->val)
            {
                res[stack.back()] = node->val;
                stack.pop_back();
            }
            stack.push_back(res.size());
            res.push_back(node->val);
        }
        for (int i : stack)
            res[i] = 0;
        return res;
    }
};
