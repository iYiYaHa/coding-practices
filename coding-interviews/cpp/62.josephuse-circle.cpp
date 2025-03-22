#include <iostream>
#include <list>

using namespace std;

class SolutionA
{
public:
    int LastRemaining_Solution(int n, int m)
    {
        if (n == 0 || m == 0)
            return -1;
        list<int> nums;
        for (int i = 0; i < n; ++i)
            nums.push_back(i);
        list<int>::iterator cur = nums.begin();

        while (nums.size() > 1)
        {
            for (int i = 1; i < m; ++i)
            {
                ++cur;
                if (cur == nums.end())
                    cur = nums.begin();
            }

            list<int>::iterator next = ++cur;
            if (next == nums.end())
                next = nums.begin();
            --cur;
            nums.erase(cur);
            cur = next;
        }
        return nums.front();
    }
};

class SolutionB
{
public:
    int LastRemaining_Solution(int n, int m)
    {
        if (n < 1)
            return -1;
        if (n == 1)
            return 0;
        return (LastRemaining_Solution(n - 1, m) + m) % n;
    }
};

class Solution
{
public:
    int LastRemaining_Solution(int n, int m)
    {
        if (n < 1)
            return -1;
        int prev = 0;
        for (int i = 2; i <= n; ++i)
            prev = (prev + m) % i;
        return prev;
    }
};

int main()
{
    Solution s;
    assert(s.LastRemaining_Solution(5, 3) == 3);
    return 0;
}
