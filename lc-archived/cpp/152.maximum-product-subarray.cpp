/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152[1,2,3,4,-3,2,2,4,1,23,45,4,32,34,2,-12,-2,3,4,-334,-1,123,12]] Maximum
 * Product Subarray
 */

// Think about its difference with problem 53 maximum subarray.
// If nums contains only positive numbers, then the two problems are actually
// the same. Since nums contains negative number and a negative number
// multiplies a negative number produces a positive number, they are quite
// different.

class SolutionA {
public:
  int maxProduct(vector<int> &nums) {
    int ans = nums[0];
    for (int i = 1, maxVal = ans, minVal = ans; i < nums.size(); ++i) {
      if (nums[i] < 0)
        swap(maxVal, minVal);
      maxVal = max(nums[i], maxVal * nums[i]);
      minVal = min(nums[i], minVal * nums[i]);
      ans = max(ans, maxVal);
    }
    return ans;
  }
};

class SolutionB {
  // Note that when updating maxVal and minVal, we need to record previous
  // values.
public:
  int maxProduct(vector<int> &nums) {
    int n = nums.size();
    int ans = nums[0], maxVal = nums[0], minVal = nums[0];
    for (int i = 1; i < n; ++i) {
      int tmp = maxVal;
      maxVal = max(maxVal * nums[i], max(minVal * nums[i], nums[i]));
      minVal = min(tmp * nums[i], min(minVal * nums[i], nums[i]));
      ans = max(ans, maxVal);
    }
    return ans;
  }
};
class Solution {
    //ref:https://leetcode.com/problems/maximum-product-subarray/discuss/48302/2-Passes-scan-beats-99
    //ref:https://leetcode.com/problems/maximum-product-subarray/discuss/227725/Java-solution-with-explanations-in-Chinese
    //ref:https://leetcode.com/problems/maximum-product-subarray/discuss/48448/A-O(n)-solution-though-not-as-great-as-answer-provided-by-Leetcode
public:
  int maxProduct(vector<int> &nums) {
    int n = nums.size();
    int ans = numeric_limits<int>::min();
    for (int i = 0, res = 1; i < n; ++i) {
      res *= nums[i];
      ans = max(res, ans);
      if (nums[i] == 0)
        res = 1;
    }
    for (int i = n - 1, res = 1; i >= 0; --i) {
      res *= nums[i];
      ans = max(res, ans);
      if (nums[i] == 0)
        res = 1;
    }
    return ans;
  }
};
