#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int InversePairs(vector<int> data)
    {
        vector<int> copy = data;
        vector<int> tmp = data;
        return mergeCountHelper(copy, tmp, 0, data.size() - 1);
    }

private:
    int mergeCountHelper(vector<int> &data, vector<int> &tmp, int left, int right)
    {
        if (left >= right)
        {
            return 0;
        }
        long long cnt = 0;
        int mid = left + (right - left) / 2;

        long long leftCnt = mergeCountHelper(tmp, data, left, mid);
        long long rightCnt = mergeCountHelper(tmp, data, mid + 1, right);

        int index = right;
        int i = mid, j = right;
        while (i >= left && j >= mid + 1)
        {
            if (data[i] > data[j])
            {
                tmp[index--] = data[i--];
                cnt += j - (mid + 1) + 1;
            }
            else
            {
                tmp[index--] = data[j--];
            }
        }
        // Merge array
        for (; i >= left; --i)
            tmp[index--] = data[i];
        for (; j >= mid + 1; --j)
            tmp[index--] = data[j];
        for (i = left; i <= right; ++i)
            data[i] = tmp[i];
        return (cnt + leftCnt + rightCnt) % 1000000007;
    }
};

int main()
{
    Solution s;
    assert(s.InversePairs({}) == 0);
    assert(s.InversePairs({1, 2, 3}) == 0);
    assert(s.InversePairs({7, 5, 6, 4}) == 5);
    assert(s.InversePairs({1, 2, 3, 4, 5, 6, 7, 0}) == 7);
    assert(s.InversePairs({1, 2, 3, 4}) == 0);
    return 0;
}