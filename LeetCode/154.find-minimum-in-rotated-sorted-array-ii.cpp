/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Hard (40.25%)
 * Likes:    661
 * Dislikes: 190
 * Total Accepted:    159.4K
 * Total Submissions: 396.1K
 * Testcase Example:  '[1,3,5]'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 * 
 * Find the minimum element.
 * 
 * The array may contain duplicates.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,5]
 * Output: 1
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,2,0,1]
 * Output: 0
 * 
 * Note:
 * 
 * 
 * This is a follow up problem to Find Minimum in Rotated Sorted Array.
 * Would allow duplicates affect the run-time complexity? How and why?
 * 
 * 
 */

// @lc code=start


class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            if (nums[left] < nums[right])
                break;

            int mid = left + (right - left) / 2;

            if (nums[left] < nums[mid])
            {
                left = mid + 1;
            }
            else if (nums[left] > nums[mid])
            {
                right = mid;
            }
            else
                ++left;
        }
        return nums[left];
    }
};
// @lc code=end

