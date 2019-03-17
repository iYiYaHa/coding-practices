/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 *
 * https://leetcode.com/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (37.30%)
 * Total Accepted:    142.1K
 * Total Submissions: 380.9K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * Given an array nums, there is a sliding window of size k which is moving
 * from the very left of the array to the very right. You can only see the k
 * numbers in the window. Each time the sliding window moves right by one
 * position. Return the max sliding window.
 *
 * Example:
 *
 *
 * Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
 * Output: [3,3,5,5,6,7]
 * Explanation:
 *
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 *
 *
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty
 * array.
 *
 * Follow up:
 * Could you solve it in linear time?
 */

class Solution
{
public:
  std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k)
  {
    std::deque<std::pair<int, int>> window;
    std::vector<int> ans;
    for (int i = 0; i < nums.size(); ++i)
    {
      if (!window.empty() && window.front().second == i - k)
        window.pop_front();
      while (!window.empty() && nums[i] > window.back().first)
        window.pop_back()
      window.emplace_back(nums[i], i);
      if (i >= k - 1)
        ans.push_back(window.front().first);
    }
    return ans;
  }
};
