/*
 * @lc app=leetcode id=430 lang=cpp
 *
 * [430] Flatten a Multilevel Doubly Linked List
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class SolutionA
{
public:
    Node *flatten(Node *head)
    {
        if (head == nullptr)
            return head;

        head->next = flatten(head->next);
        head->child = flatten(head->child);
        if (head->child)
        {
            // Find the end of the children list
            Node *childEnd = head->child;
            for (; childEnd->next != nullptr; childEnd = childEnd->next)
                ;

            // Insert the children list between head and head->next
            if (head->next)
            {
                childEnd->next = head->next;
                head->next->prev = childEnd;
            }
            head->next = head->child;
            head->child->prev = head;
            head->child = nullptr;
        }
        return head;
    }
};

class SolutionB
{
public:
    Node *flatten(Node *head)
    {
        if (head == nullptr)
            return nullptr;
        stack<Node *> stack;
        stack.push(head);
        Node *prev = nullptr;
        while (!stack.empty())
        {
            Node *top = stack.top();
            stack.pop();
            if (top == nullptr)
                continue;
            stack.push(top->next);
            stack.push(top->child);

            top->next = top->child = nullptr;
            if (prev != nullptr)
            {
                prev->next = top;
                top->prev = prev;
            }
            prev = top;
        }
        return head;
    }
};

class SolutionC
{
    // ref: Problem 114
    Node *flattenHelper(Node *head, Node *rest)
    {
        if (head == nullptr)
            return rest;
        head->next = flattenHelper(head->child, flattenHelper(head->next, rest));
        if (head->next)
            head->next->prev = head;
        head->child = nullptr;
        return head;
    }

public:
    Node *flatten(Node *head)
    {
        return flattenHelper(head, nullptr);
    }
};

class SolutionD
{
    // ref: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/discuss/152066/c++-about-10-lines-solution
    // ref: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/discuss/150321/Easy-Understanding-Java-beat-95.7-with-Explanation
public:
    Node *flatten(Node *head)
    {
        for(Node *cur=head;cur!=nullptr;cur=cur->next){
            if(cur->child){
                Node *child=cur->child;
                cur->child=nullptr;
                Node *childEnd=child;
                while(childEnd->next)childEnd=childEnd->next;
                if(cur->next){
                childEnd->next=cur->next;
                cur->next->prev=childEnd;
                }
                cur->next=child;
                child->prev=cur;
            }
        }
        return head;
    }
};
