#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int GetUglyNumber_Solution(int index)
    {
        if (index <= 0)
            return 0;
        std::vector<int> table;
        table.push_back(1);
        int twoIndex = 0, threeIndex = 0, fiveIndex = 0;
        int resTwo = table[twoIndex] * 2;
        int resThree = table[threeIndex] * 3;
        int resFive = table[fiveIndex] * 5;
        for (int i = 1; i < index; ++i)
        {
            int res = std::min(resTwo, std::min(resThree, resFive));
            table.push_back(res);
            if (res == resTwo)
                resTwo = table[++twoIndex] * 2;
            if (res == resThree)
                resThree = table[++threeIndex] * 3;
            if (res == resFive)
                resFive = table[++fiveIndex] * 5;
        }
        return table.back();
    }
};

int main()
{
    Solution s;
    assert(s.GetUglyNumber_Solution(-1) == 0);
    assert(s.GetUglyNumber_Solution(0) == 0);
    assert(s.GetUglyNumber_Solution(1) == 1);
    assert(s.GetUglyNumber_Solution(2) == 2);
    assert(s.GetUglyNumber_Solution(3) == 3);
    assert(s.GetUglyNumber_Solution(1685) == 2066242608);
}