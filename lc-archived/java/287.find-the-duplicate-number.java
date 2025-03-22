import java.util.Set;

/*
 * @lc app=leetcode id=287 lang=java
 *
 * [287] Find the Duplicate Number
 *
 * https://leetcode.com/problems/find-the-duplicate-number/description/
 *
 * algorithms
 * Medium (55.08%)
 * Likes:    5419
 * Dislikes: 623
 * Total Accepted:    377K
 * Total Submissions: 674.5K
 * Testcase Example:  '[1,3,4,2,2]'
 *
 * Given an array of integers nums containing n + 1 integers where each integer
 * is in the range [1, n] inclusive.
 * 
 * There is only one duplicate number in nums, return this duplicate number.
 * 
 * Follow-ups:
 * 
 * 
 * How can we prove that at least one duplicate number must exist in nums? 
 * Can you solve the problem without modifying the array nums?
 * Can you solve the problem using only constant, O(1) extra space?
 * Can you solve the problem with runtime complexity less than O(n^2)?
 * 
 * 
 * 
 * Example 1:
 * Input: nums = [1,3,4,2,2]
 * Output: 2
 * Example 2:
 * Input: nums = [3,1,3,4,2]
 * Output: 3
 * Example 3:
 * Input: nums = [1,1]
 * Output: 1
 * Example 4:
 * Input: nums = [1,1,2]
 * Output: 1
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= n <= 3 * 10^4
 * nums.length == n + 1
 * 1 <= nums[i] <= n
 * All the integers in nums appear only once except for precisely one integer
 * which appears two or more times.
 * 
 * 
 */

// @lc code=start
// // Question Two
class Solution {
    public int findDuplicate(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for(int num:nums){
            if(set.contains(num))
                return num;
            set.add(num);
        }
        return -1;
    }
}

// Question Three
class Solution {
    public int findDuplicate(int[] nums) {
        for(int i = 0;i<nums.length;++i){
            while(nums[i] != i+1){
                int pos = nums[i]-1;
                if(nums[pos] == nums[i]){
                    return nums[i];
                }else{
                    swap(nums,i,pos);
                }
            }
        }
        return -1;
    }

    private void swap(int[] nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}
// @lc code=end

