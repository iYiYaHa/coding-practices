//#include<vector>
//#include<algorithm>
//class SolutionA {
//	// dp
//public:
//	int lengthOfLIS(std::vector<int>& nums) {
//		if (nums.size() == 0)
//			return 0;
//		std::vector<int> dp(nums.size(), 1);
//		for (int i = 1; i < nums.size(); ++i) {
//			for (int j = 0; j < i; ++j) {
//				if (nums[i] > nums[j])
//					dp[i] = std::max(dp[i], dp[j] + 1);
//			}
//		}
//		return *std::max_element(dp.begin(), dp.end());
//	}
//};
//
//class SolutionB
//{
//private:
//	int binarySearch(const std::vector<int> &nums, int beg, int end, int target)
//	{
//		int left = beg, right = end;
//		while (left <= right)
//		{
//			int mid = (left + right) / 2;
//			if (nums[mid] > target)
//				right = mid - 1;
//			else if (nums[mid] < target)
//				left = mid + 1;
//			else
//				return mid;
//		}
//		return left;
//	}
//
//public:
//	int lengthOfLIS(std::vector<int> &nums)
//	{
//		std::vector<int> minOfLen(nums.size(), std::numeric_limits<int>::min());
//		int len = -1;
//		for (const int &num : nums) {
//			int pos = binarySearch(minOfLen, 0, len, num);
//			minOfLen[pos] = num;
//			len = std::max(pos, len);
//		}
//		return len + 1;
//	}
//};
//
//class SolutionC
//{
//	//ref:https://leetcode.com/problems/longest-increasing-subsequence/discuss/74919/Thinking-process-from-O(n2)-to-O(nlogn)-solution
////ref :https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
//public:
//	int lengthOfLIS(std::vector<int> &nums)
//	{
//		std::vector<int> minTails;
//		for (const int &num : nums)
//		{
//			auto it = std::lower_bound(minTails.begin(), minTails.end(), num);
//			if (it == minTails.end())
//				minTails.push_back(num);
//			else
//				*it = num;
//		}
//		return minTails.size();
//	}
//};
//class SolutionD
//{
//	//ref:https://leetcode.com/problems/longest-increasing-subsequence/discuss/74919/Thinking-process-from-O(n2)-to-O(nlogn)-solution
////ref :https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
//public:
//	int lengthOfLIS(std::vector<int> &nums)
//	{
//		std::vector<int> minTails;
//		for (const int &num : nums)
//		{
//			auto it = std::lower_bound(minTails.begin(), minTails.end(), num);
//			if (it == minTails.end())
//				minTails.push_back(num);
//			else
//				*it = num;
//		}
//		return minTails.size();
//	}
//};