#include <iostream>
#include <vector>

using namespace std;

class QuickSorter
{
public:
    void sort(vector<int> &nums)
    {
        quickSort(nums, 0, nums.size() - 1);
    }

private:
    void quickSort(vector<int> &nums, int left, int right)
    {
        if (left >= right)
            return;

        int ind = partition(nums, left, right);
        for (int num : nums)
        {
            cout << num << " ";
        }
        cout << endl;
        quickSort(nums, left, ind - 1);
        quickSort(nums, ind + 1, right);
    }

    int partition(vector<int> &nums, int left, int right)
    {
        // int pivot = nums[left];
        // int k = left+1;
        // for(int i = left;i<=right;++i){
        //     if(nums[i]<=pivot){
        //         swap(nums[i],nums[k++]);
        //     }
        // }
        // swap(nums[left],nums[k-1]);
        // return k-1;

        int pivot = nums[left];
        int i = left + 1, j = right;
        while (i < j)
        {
            while (i < j && nums[i] <= pivot)
                ++i;
            while (i < j && nums[j] >= pivot)
                --j;
            if(i<j)swap(nums[i],nums[j]);
        }
        swap(nums[i-1],nums[left]);
        return i-1;
    }
};

int main()
{
    QuickSorter sorter;
    vector<int> nums = {9, 4, 3, 1, 4, 6, 8, 54, 1, 2, 4, 9, 100, 29, 38, 57, 2, 3, 4, 2, 1, 5, 4, 13, 15, 17, 19, 21, 28, 34, 54, 18, 15, 13, 12, -1, 0};
    // vector<int> nums = {5, 4, 3, 2, 1};
    sorter.sort(nums);
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}