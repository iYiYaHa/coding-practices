/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class SolutionA
{
public:
    RandomListNode *Clone(RandomListNode *pHead)
    {
        unordered_map<RandomListNode *, RandomListNode *> memo;
        memo.insert(make_pair(nullptr, nullptr));
        RandomListNode *cur = pHead;
        RandomListNode dummy(0);
        RandomListNode *prev = &dummy;
        while (cur != nullptr)
        {
            RandomListNode *copyNode = memo.count(cur) ? memo[cur] : new RandomListNode(cur->label);
            memo.insert(make_pair(cur, copyNode));
            RandomListNode *randomNode = memo.count(cur->random) ? memo[cur->random] : new RandomListNode(cur->random->label);
            memo.insert(make_pair(cur->random, randomNode));

            copyNode->random = randomNode;
            prev->next = copyNode;
            prev = copyNode;
            cur = cur->next;
        }
        return dummy.next;
    }
};

class SolutionB
{
public:
    RandomListNode *Clone(RandomListNode *pHead)
    {
        unordered_map<RandomListNode *, RandomListNode *> memo;
        memo.insert(make_pair(nullptr, nullptr));
        RandomListNode *cur = pHead;
        while (cur != nullptr)
        {
            RandomListNode *copy = new RandomListNode(cur->label);
            memo.insert(make_pair(cur, copy));
            cur = cur->next;
        }

        cur = pHead;
        while (cur != nullptr)
        {
            memo[cur]->next = memo[cur->next];
            memo[cur]->random = memo[cur->random];
            cur = cur->next;
        }
        return memo[pHead];
    }
};

class Solution
{
public:
    RandomListNode *Clone(RandomListNode *pHead)
    {
        if (pHead == nullptr)
            return nullptr;

        // Insert a cloned node after its original node.
        RandomListNode *cur = pHead;
        while (cur != nullptr)
        {
            RandomListNode *copy = new RandomListNode(cur->label);
            copy->next = cur->next;
            cur->next = copy;
            cur = copy->next;
        }

        // Copy the random link.
        cur = pHead;
        while (cur != nullptr)
        {
            RandomListNode *copy = cur->next;
            copy->random = cur->random ? cur->random->next : nullptr;
            cur = copy->next;
        }

        // Split the original list and the cloned list.

        RandomListNode *res = pHead->next;
        cur = pHead;
        while (cur != nullptr && cur->next != nullptr)
        {
            RandomListNode *nextNode = cur->next;
            cur->next = nextNode->next;
            cur = nextNode;
        }
        return res;
    }
};
