/*
 * @lc app=leetcode id=1470 lang=java
 *
 * [1470] Shuffle the Array
 *
 * https://leetcode.com/problems/shuffle-the-array/description/
 *
 * algorithms
 * Easy (89.02%)
 * Likes:    877
 * Dislikes: 98
 * Total Accepted:    149.8K
 * Total Submissions: 169.3K
 * Testcase Example:  '[2,5,1,3,4,7]\n3'
 *
 * Given the array nums consisting of 2n elements in the form
 * [x1,x2,...,xn,y1,y2,...,yn].
 * 
 * Return the array in the form [x1,y1,x2,y2,...,xn,yn].
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,5,1,3,4,7], n = 3
 * Output: [2,3,5,4,1,7] 
 * Explanation: Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is
 * [2,3,5,4,1,7].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,3,4,4,3,2,1], n = 4
 * Output: [1,4,2,3,3,2,4,1]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,1,2,2], n = 2
 * Output: [1,2,1,2]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 500
 * nums.length == 2n
 * 1 <= nums[i] <= 10^3
 * 
 */

// @lc code=start
class Solution {
    public int[] shuffle(int[] nums, int n) {
        if (nums == null)
            return null;
        for (int i = 0; i < n; ++i) {
            nums[i] <<= 10;
            nums[i] |= nums[n + i];
        }
        for (int i = n - 1; i >= 0; --i) {
            int num = nums[i];
            nums[2 * i] = num >> 10;
            nums[2 * i + 1] = num & (0x3ff);
        }
        return nums;
    }
}

class Solution {
    public int[] shuffle(int[] nums, int n) {
        int[] res = new int[2 * n];
        for (int i = 0; i < n; ++i) {
            res[2 * i] = nums[i];
            res[2 * i + 1] = nums[n + i];
        }
        return res;
    }
}
// @lc code=end
