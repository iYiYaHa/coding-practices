/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    using valType = pair<int, int>;

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode head(0);
        ListNode *end = &head;
        auto cmp = [](valType a, valType b) { return a.first > b.first; };
        priority_queue<valType, vector<valType>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < lists.size(); ++i)
        {
            if (lists[i] != nullptr)
                pq.push(make_pair(lists[i]->val, i));
        }
        while (!pq.empty())
        {
            int ind = pq.top().second;
            pq.pop();

            end->next = lists[ind];
            end = end->next;

            lists[ind] = lists[ind]->next;
            if (lists[ind] != nullptr)
                pq.push(make_pair(lists[ind]->val, ind));
        }
        return head.next;
    }
};

class SolutionB
{
    ListNode *merge2Lists(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        if (l1->val < l2->val)
        {
            l1->next = merge2Lists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = merge2Lists(l1, l2->next);
            return l2;
        }
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return nullptr;
        for (int step = 1; step < lists.size(); step *= 2)
        {
            for (int i = 0; i < lists.size() - step; i += step * 2)
                lists[i] = merge2Lists(lists[i], lists[i + step]);
        }
        return lists[0];
    }
};
