#include <iostream>

using namespace std;

class Solution
{
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int nums[], int length, int *duplication)
    {
        if (nums == nullptr || length == 0)
            return false;
        for (int i = 0; i < length; ++i)
        {
            if (nums[i] < 0 || nums[i] > length - 1)
                return false;
        }
        for (int i = 0; i < length; ++i)
        {
            while (nums[i] != i)
            {
                if (nums[i] == nums[nums[i]])
                {
                    *duplication = nums[i];
                    return true;
                }

                int tmp = nums[i];
                nums[i] = nums[nums[i]];
                nums[tmp] = tmp; // Note this line.
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    int nums[] = {2, 3, 1, 0, 2, 5, 3};
    int duplication;
    assert(s.duplicate(nums, 7, &duplication) == true);
    assert(duplication == 2);
    return 0;
}