////Problem : Climbing Stairs
////
////Problem Description:
////  You are climbing a stair case. It takes n steps to reach to the top.
//
////  Each time you can either climb 1 or 2 steps.In how many distinct ways can you climb to the top ?
//
////  Note : Given n will be a positive integer.
////
////  Example1:
////  Input: 2
////  Output: 2
////  Explanation : There are two ways to climb to the top.
////  1. 1 step + 1 step
////  2. 2 steps
//
////  Example2:
////  Input: 3
////  Output : 3
////  Explanation : There are three ways to climb to the top.
////  1. 1 step + 1 step + 1 step
////  2. 1 step + 2 steps
////  3. 2 steps + 1 step
//
//#include<iostream>
//#include<vector>
//
//class Solution {
//public:
//	// Solution One 
//	// Like Fibonacci.
//	int climbStairs(int n) {
//		int prev2 = 0;
//		int prev1 = 1;
//		for (int i = 0; i < n; ++i) {
//			int temp = prev1 + prev2;
//			prev2 = prev1;
//			prev1 = temp;
//		}
//		return prev1;
//	}
//};
//int main() 
//{
//	Solution solution;
//	std::vector<int> testCase = { 2,3 };
//	for (int i : testCase) {
//		std::cout << solution.climbStairs(i) << std::endl;
//	}
//	std::cin.get();
//	return 0;
//}