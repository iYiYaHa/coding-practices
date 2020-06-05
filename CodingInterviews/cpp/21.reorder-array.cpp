#include <iostream>
#include <vector>

using namespace std;

bool isOdd(int num)
{
    return num & 1;
}

// This solutio is aimed for the problem without requirements on the stability。
class Solution
{
public:
    void reOrderArray(vector<int> &nums, bool (*func)(int) = isOdd)
    {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            while (left < nums.size() && func(nums[left]))
                ++left;
            while (right >= 0 && !func(nums[right]))
                --right;
            if (left < right)
            {
                int tmp = nums[left];
                nums[left] = nums[right];
                nums[right] = tmp;
            }
        }
        return;
    }
};

// This solution satisfies the requirement for the stability.
class SolutionB
{
public:
    void reOrderArray(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] & 1)
            {
                for (int j = i - 1; j >= 0 && !(nums[j] & 1); --j)
                {
                    int tmp = nums[j + 1];
                    nums[j + 1] = nums[j];
                    nums[j] = tmp;
                }
            }
        }
        return;
    }
};

int main()
{
    Solution s;
    // vector<int> nums = {3, 4, 1, 2, 3, 4, 5, 76, 2, 342, 314, 5, 123, 4, 124, 122, 3, 28, 465, 64, 5645};
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    s.reOrderArray(nums);
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
}
