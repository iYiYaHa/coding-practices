#include <iostream>
#include <vector>

using namespace std;

class SolutionA
{
public:
    int GetNumberOfK(vector<int> data, int k)
    {
        if (data.size() == 0)
            return 0;
        int firstInd = getFirstK(data, k);
        int lastInd = getLastK(data, k);
        if (firstInd == -1 || lastInd == -1)
            return 0;
        return lastInd - firstInd + 1;
    }

private:
    int getFirstK(vector<int> &data, int k)
    {
        int left = 0, right = data.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (data[mid] < k)
            {
                left = mid + 1;
            }
            else if (data[mid] > k)
            {
                right = mid - 1;
            }
            else
            {
                if (mid - 1 >= left && data[mid - 1] == data[mid])
                    right = mid - 1;
                else
                    return mid;
            }
        }
        return -1;
    }
    int getLastK(vector<int> &data, int k)
    {
        int left = 0, right = data.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (data[mid] < k)
            {
                left = mid + 1;
            }
            else if (data[mid] > k)
            {
                right = mid - 1;
            }
            else
            {
                if (mid + 1 <= right & &data[mid + 1] == data[mid])
                    left = mid + 1;
                else
                    return mid;
            }
        }
        return -1;
    }
};

class Solution
{
public:
    int GetNumberOfK(vector<int> data, int k)
    {
        int leftPos = getInsertPos(data, k - 0.5);
        int rightPos = getInsertPos(data, k + 0.5);
        return rightPos - leftPos;
    }

private:
    int getInsertPos(vector<int> data, double k)
    {
        int left = 0, right = data.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (data[mid] < k)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }
};

int main()
{
    Solution s;
    assert(s.GetNumberOfK({}, 2) == 0);
    assert(s.GetNumberOfK({1, 2, 2, 2, 2, 3, 3, 4, 5, 5, 5, 6}, 2) == 4);
    assert(s.GetNumberOfK({1, 2, 2, 2, 2, 3, 3, 4, 5, 5, 5, 6}, 5) == 3);
    assert(s.GetNumberOfK({1, 2, 2, 2, 2, 3, 3, 4, 5, 5, 5, 6}, 1) == 1);
    assert(s.GetNumberOfK({1, 2, 2, 2, 2, 3, 3, 4, 5, 5, 5, 6}, 6) == 1);
    assert(s.GetNumberOfK({1, 2, 2, 2, 2, 3, 3, 4, 5, 5, 5, 6}, 7) == 0);
    return 0;
}