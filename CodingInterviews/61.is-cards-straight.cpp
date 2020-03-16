#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool IsContinuous(vector<int> numbers)
    {
        if (numbers.size() < 5)
            return false;
        vector<int> cnt(14, 0);
        for (int num : numbers)
            cnt[num] += 1;

        int gap = 0;
        int leftNum = -1;
        for (int i = 1; i <= 13; ++i)
        {
            if (cnt[i] >= 2)
                return false;
            if (cnt[i] != 0)
            {
                if (leftNum != -1)
                {
                    gap += (i - leftNum - 1);
                }
                leftNum = i;
            }
        }
        return gap == 0 ? true : cnt[0] >= gap;
    }
};

int main()
{
    Solution s;
    assert(s.IsContinuous({1, 2, 3, 4, 5}) == true);
    assert(s.IsContinuous({4, 5, 6, 7, 8}) == true);
    assert(s.IsContinuous({9, 10, 11, 12, 13}) == true);
    assert(s.IsContinuous({9, 0, 11, 12, 13}) == true);
    assert(s.IsContinuous({9, 10, 11, 12, 0}) == true);
    assert(s.IsContinuous({1, 2, 3, 0, 0}) == true);
    assert(s.IsContinuous({1, 3, 5, 0, 0}) == true);
    assert(s.IsContinuous({1, 4, 5, 0, 0}) == true);
    assert(s.IsContinuous({3, 4, 5, 0, 0}) == true);
    assert(s.IsContinuous({1, 3, 5, 7, 9}) == false);

    assert(s.IsContinuous({3, 4, 5, 8, 9, 0, 0}) == true);
    assert(s.IsContinuous({6, 4, 5, 8, 9, 11, 0, 0}) == true);
    assert(s.IsContinuous({3, 4, 5, 6, 7, 0, 0}) == true);

    return 0;
}