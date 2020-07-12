//#include<vector>
//#include<iostream>
//
//class Solution {
//	// Time Complexity: O(logn)
//
//	//ref: https://leetcode.com/problems/single-element-in-a-sorted-array/discuss/100754/Java-Binary-Search-short-(7l)-O(log(n))-w-explanations
//public:
//	int singleNonDuplicate(std::vector<int>& nums) {
//		// Based on binary search.
//				// Based on binary search.
//		int left = 0, right = nums.size() - 1;
//		while (left < right) {
//			int mid = (left + right) / 2;
//			mid = mid % 2 ? mid : mid + 1;
//			// 0...mid-1 odd numbers
//			// mid...n-1 even numbers
//			if (nums[mid] == nums[mid + 1])
//				right = mid - 1;
//			else
//				left = mid + 1;
//		}
//		return nums[left];
//	}
//};
//
//int main() {
//	std::vector<std::vector<int>> testCase = { {1,1,2} };
//		std::vector<int> testAns = { 2 };
//		for (int i = 0; i < testCase.size(); ++i) {
//			bool result = Solution().singleNonDuplicate(testCase[i]) == testAns[i];
//			if (result)
//				std::cout << "Test case " << i + 1 << " passed with solution A." << std::endl;
//			else
//				std::cout << "Test case " << i + 1 << " failed with solution A." << std::endl;
//		}
//		std::cin.get();
//		return 0;
//}