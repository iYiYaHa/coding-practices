////Problem : Min Cost Climbing Stairs
////
////Problem Description:
////  On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).
////
////  Once you pay the cost, you can either climb one or two steps.You need to find minimum 
////  cost to reach the top of the floor, and you can either start from the step with index 
////  0, or the step with index 1.
////
////  Example1:
////  Input: cost = [10, 15, 20]
////  Output: 15
////  Explanation : Cheapest is start on cost[1], pay that cost and go to the top.
//
////               _Top_
////           _20_|
////       _15_|
////  _10_|
//
////  Example2:
////  Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
////  Output : 6
////  Explanation : Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
////
////Note:
////  1.cost will have a length in the range[2, 1000].
////  2.Every cost[i] will be an integer in the range[0, 999].
//
//#include<iostream>
//#include<vector>
//
//class Solution {
//
//public:
//	// Solution One
//	// dp[i] = min(dp[i-2] + cost[i-2], dp[i-1] + cost[i-1])
//	int minCostClimbingStairsA(std::vector<int>& cost) {
//		std::vector<int> minCost(cost.size()+1, 0);
//		minCost[0] = 0;
//		minCost[1] = 0;
//		for (int i = 2; i < cost.size()+1; ++i) {
//			int oneStep = minCost[i - 1] + cost[i - 1];
//			int twoStep = minCost[i - 2] + cost[i - 2];
//			minCost[i] = oneStep > twoStep ? twoStep : oneStep;
//		}
//		return minCost[cost.size()];
//	}
//
//	// Solution Two
//	// Solution One with memory space optimized.
//	int minCostClimbingStairsB(std::vector<int>& cost) {
//		int prevCost1 = 0;
//		int prevCost2 = 0;
//		for (int i = 2; i < cost.size()+1; ++i) {
//			int curMinCost = (prevCost2 + cost[i - 2]) > (prevCost1 + cost[i - 1]) ? prevCost1 + cost[i - 1] : (prevCost2 + cost[i - 2]);
//			prevCost2 = prevCost1;
//			prevCost1 = curMinCost;
//		}
//		return prevCost1;
//	}
//};
//
//int main() 
//{
//	Solution solution;
//	std::vector<int> testCase1 = { 10,15,20};
//	std::vector<int> testCase2 = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
//	std::cout << solution.minCostClimbingStairsA(testCase1) << std::endl;
//	std::cout << solution.minCostClimbingStairsA(testCase2) << std::endl;
//	std::cout << solution.minCostClimbingStairsB(testCase1) << std::endl;
//	std::cout << solution.minCostClimbingStairsB(testCase2) << std::endl;
//	std::cin.get();
//	return 0;
//}