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

class SolutionA
{
  // Using deque to solve this problem.
  // The elements in deque is in decreasing order.
  // Each time you get a new an element, you pop out all numbers smaller than it and close to slip out of the window.
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
        window.pop_back();
      window.emplace_back(nums[i], i);
      if (i >= k - 1)
        ans.push_back(window.front().first);
    }
    return ans;
  }
};

using std::max;
using std::vector;
class SolutionB
{
    // ref:https://leetcode.com/problems/sliding-window-maximum/discuss/65881/O(n)-solution-in-Java-with-two-simple-pass-in-the-array
    // Two-pass approach which is really brilliant.
    // From analysises of the above reference, we can see that from some aspects this approach is equivalent to the deque approach.
    // Each time we want to output the maximum number of a sliding window, the sliding window can be partitioned into two parts from those boundaries(i % w ==0)
    // Compare the maximum of each part, we have the maximum number of each window.
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        std::vector<int> left(nums.size() + 1);  // from left to right
        std::vector<int> right(nums.size() + 1); // from right to left
        std::vector<int> ans;

        for (int i = 0; i < nums.size(); ++i)
        {
            left[i] = i % k == 0 ? nums[i] : max(left[i - 1], nums[i]);
            const int j = nums.size() - 1 - i;
            right[j] = j % k == 0 ? nums[j] : max(right[j + 1], nums[j]);
        }

        for (int i = 0; i + k - 1 < nums.size(); ++i)
        {
            ans.push_back(max(right[i], left[i + k - 1]));
        }
        return ans;
    }
};
