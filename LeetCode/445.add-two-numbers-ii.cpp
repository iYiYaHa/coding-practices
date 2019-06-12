/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
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
    // Using stack to reverse numbers.
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);

        stack<ListNode *> stackA, stackB;
        for (ListNode *cur = l1; cur != nullptr; cur = cur->next)
            stackA.push(cur);
        for (ListNode *cur = l2; cur != nullptr; cur = cur->next)
            stackB.push(cur);

        int carry = 0;
        while (!stackA.empty() && !stackB.empty())
        {
            ListNode *topA = stackA.top();
            stackA.pop();
            ListNode *topB = stackB.top();
            stackB.pop();

            int val = topA->val + topB->val + carry;
            carry = val / 10;
            val = val % 10;

            ListNode *newNode = new ListNode(val);
            newNode->next = dummy.next;
            dummy.next = newNode;
        }

        stack<ListNode *> &left = !stackA.empty() ? stackA : stackB;
        while (!left.empty())
        {
            ListNode *topEle = left.top();
            left.pop();
            int val = topEle->val + carry;
            carry = val / 10;
            val = val % 10;
            ListNode *newNode = new ListNode(val);
            newNode->next = dummy.next;
            dummy.next = newNode;
        }

        if (carry != 0)
        {
            ListNode *newNode = new ListNode(carry);
            newNode->next = dummy.next;
            dummy.next = newNode;
        }
        return dummy.next;
    }
};

class SolutionB
{
    // Using stack to reverse numbers.
    // With logic optimized.
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);

        stack<ListNode *> stackA, stackB;
        for (ListNode *cur = l1; cur != nullptr; cur = cur->next)
            stackA.push(cur);
        for (ListNode *cur = l2; cur != nullptr; cur = cur->next)
            stackB.push(cur);

        int carry = 0;
        while (!stackA.empty() || !stackB.empty() || carry != 0)
        {
            int val = carry;
            if (!stackA.empty())
            {
                ListNode *topA = stackA.top();
                stackA.pop();
                val += topA->val;
            }
            if (!stackB.empty())
            {
                ListNode *topB = stackB.top();
                stackB.pop();
                val += topB->val;
            }
            carry = val / 10;
            val = val % 10;
            ListNode *newNode = new ListNode(val);
            newNode->next = dummy.next;
            dummy.next = newNode;
        }
        return dummy.next;
    }
};

class SolutionC
{

    // ref:https://leetcode.com/problems/add-two-numbers-ii/discuss/92624/C++-O(1)-extra-space-except-for-output.-Reverse-output-instead.-Is-this-cheating
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int len1 = 0, len2 = 0;

        for (ListNode *cur = l1; cur != nullptr; cur = cur->next)
            ++len1;
        for (ListNode *cur = l2; cur != nullptr; cur = cur->next)
            ++len2;

        ListNode *res = nullptr, *cur1 = l1, *cur2 = l2;
        while (len1 > 0 && len2 > 0)
        {
            int sum = 0;
            if (len1 >= len2)
            {
                sum += l1->val;
                l1 = l1->next;
                --len1;
            }
            if (len2 > len1)
            {
                sum += l2->val;
                l2 = l2->next;
                --len2;
            }

            ListNode *newNode = new ListNode(sum);
            newNode->next = res;
            res = newNode;
        }
        
        ListNode *cur = res;
        res = nullptr;
        int carry = 0, sum = 0;
        while (cur != nullptr)
        {
            ListNode *ele = cur;
            cur = cur->next;

            sum = carry + ele->val;
            ele->val = sum % 10;
            carry = sum / 10;
            ele->next = res;
            res = ele;
        }
        if (carry != 0)
        {
            ListNode *newNode = new ListNode(carry);
            newNode->next = res;
            res = newNode;
        }
        return res;
    }
};
