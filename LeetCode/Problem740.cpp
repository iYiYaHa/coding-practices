////Problem : Delete and Earn
////
////Problem Description:
////  Given an array nums of integers, you can perform operations on the array.
////  
////  In each operation, you pick any nums[i] and delete it to earn nums[i] points.
////  After, you must delete every element equal to nums[i] - 1 or nums[i] + 1.
////  
////  You start with 0 points.Return the maximum number of points you can earn by 
////  applying such operations.
////
////  Example 1:
////		Input: nums = [3, 4, 2]
////		Output : 6
////		Explanation :
////  		Delete 4 to earn 4 points, consequently 3 is also deleted.
////  		Then, delete 2 to earn 2 points. 6 total points are earned.
////
////  Example 2 :
////  	Input : nums = [2, 2, 3, 3, 3, 4]
////  	Output : 9
////  	Explanation :
////  		Delete 3 to earn 3 points, deleting both 2's and the 4.
////  		Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
////  		9 total points are earned.
////  Note :
////  1. The length of nums is at most 20000.
////  2. Each element nums[i] is an integer in the range[1, 10000].
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <cassert>
//#include <algorithm>
//
//class Solution {
//public:
//	// Think about its connection with problem 198 house robber.
//	int deleteAndEarn(std::vector<int>& nums) {
//		int max = 0;
//		for (int i = 0; i < nums.size(); ++i) {
//			max = std::max(max, nums[i]);
//		}
//		std::vector<int> num_sum(max + 1, 0);
//		for (const int &i : nums)
//			num_sum[i] += i;
//		int prev1 = 0;
//		int prev2 = 0;
//		for (int i = 0; i < num_sum.size(); ++i) {
//			int temp = std::max(prev2 + num_sum[i], prev1);
//			prev2 = prev1;
//			prev1 = temp;
//		}
//		return prev1;
//	}
//};
//
//int main() {
//	std::vector<std::vector<int>> testCase = { {2, 2, 3, 3, 3, 4 },{3, 4, 2}};
//	std::vector<int> testAns = { 9,6};
//	for (int i = 0; i < testCase.size(); ++i) {
//		bool res = Solution().deleteAndEarn(testCase[i]) == testAns[i];
//		if (res) {
//			std::cout << "Test case " << i << " passed.\n";
//		}
//		else {
//			std::cout << "Test case " << i << " failed.\n";
//
//		}
//	}
//	std::cin.get();
//	return 0;
//}