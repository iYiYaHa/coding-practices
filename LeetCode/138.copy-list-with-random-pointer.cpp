/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class SolutionA
{
    // Take care with logic behind this.
    // Especially handle situations like random points to itself.
public:
    Node *copyRandomList(Node *head)
    {
        map<Node *, Node *> memo;
        Node dummy(0, nullptr, nullptr);
        Node *prev = &dummy;
        memo.insert(make_pair(nullptr, nullptr));
        while (head != nullptr)
        {
            Node *copyCur = memo.count(head) != 0 ? memo[head] : new Node(head->val, nullptr, nullptr);
            memo.insert(make_pair(head, copyCur));
            Node *copyRandom = memo.count(head->random) != 0 ? memo[head->random] : new Node(head->random->val, nullptr, nullptr);
            memo.insert(make_pair(head->random, copyRandom));
            copyCur->random = copyRandom;
            prev->next = copyCur;
            prev = copyCur;
            head = head->next;
        }
        return dummy.next;
    }
};
class SolutionB
{
    // Take care with logic behind this.
    // Especially handle situations like random points to itself.
public:
    Node *copyRandomList(Node *head)
    {
        map<Node *, Node *> memo;
        memo.insert(make_pair(nullptr,nullptr));
        Node *cur=head;
        while(cur!=nullptr){
            Node *tmp = new Node(cur->val,nullptr,nullptr);
            memo.insert(make_pair(cur,tmp));
            cur=cur->next;
        }
        cur=head;
        while(cur!=nullptr){
            memo[cur]->next=memo[cur->next];
            memo[cur]->random=memo[cur->random];
            cur=cur->next;
        }
        return memo[head];
    }
};
class SolutionC
{
    //ref:https://leetcode.com/problems/copy-list-with-random-pointer/discuss/43491/A-solution-with-constant-space-complexity-O(1)-and-linear-time-complexity-O(N)
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return head;
        Node *cur = head;
        while (cur != nullptr)
        {
            Node *tmp = new Node(cur->val, nullptr, nullptr);
            tmp->next = cur->next;
            cur->next = tmp;
            cur = tmp->next;
        }

        cur = head;
        while (cur != nullptr)
        {
            Node *copy_cur = cur->next;
            Node *copy_random = cur->random ? cur->random->next : nullptr;
            copy_cur->random = copy_random;
            cur = copy_cur->next;
        }

        Node *res = head->next;
        cur = head;
        while (cur != nullptr&&cur->next!=nullptr)
        {
            Node *copy_cur = cur->next;
            cur->next = copy_cur->next;
            cur = copy_cur;
        }
        return res;
    }
};
