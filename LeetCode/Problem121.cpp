////Problem : Regular Expression Matching
////
////Problem Description:
////  Say you have an array for which the ith element is the price of a given stock on day i.
////
////  If you were only permitted to complete at most one transaction(i.e., buy one and sell 
////  one share of the stock), design an algorithm to find the maximum profit.
////
////  Note that you cannot sell a stock before you buy one.
////
////  Example1:
////  Input: [7, 1, 5, 3, 6, 4]
////  Output : 5
////  Explanation : Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6 - 1 = 5.
////  Not 7 - 1 = 6, as selling price needs to be larger than buying price.
//
////  Example2:
////  Input : [7, 6, 4, 3, 1]
////  Output : 0
////  Explanation : In this case, no transaction is done, i.e.max profit = 0.
//
//#include<iostream>
//#include<vector>
//
//class Solution {
//
//public:
//	//Solution One (Naive Approach)
//	int maxProfitA(std::vector<int>& prices) {
//		int maxProfit = 0;
//		for (int i = 0; i < prices.size(); ++i) {
//			for (int j = i; j < prices.size(); ++j) {
//				if ((prices[j] - prices[i]) > maxProfit)
//					maxProfit = prices[j] - prices[i];
//			}
//		}
//		return maxProfit;
//	}
//
//	//Solution Two
//	// Remember the minimum price so far and compare it with the current price.
//	int maxProfitB(std::vector<int>& prices) {
//		if (prices.size() == 0 || prices.size() == 1)
//			return 0;
//		int leastPrice = prices[0];
//		int maxProfit = 0;
//		for (int i = 1; i < prices.size(); ++i) {
//			if (prices[i] < leastPrice)
//				leastPrice = prices[i];
//			else {
//				int diff = prices[i] - leastPrice;
//				maxProfit = diff > maxProfit ? diff : maxProfit;
//			}
//		}
//		return maxProfit;
//	}
//
//	// Solution C
//	// Kadane's Algorithm
//	int maxProfitC(std::vector<int>& prices) {
//		int curProfit = 0;
//		int maxProfit = 0;
//		for (int i = 1; i < prices.size(); ++i) {
//			curProfit += prices[i] - prices[i - 1];    // prices[i] - prices[i-1] is the difference between day i and day i-1, that is, 
//													   // the profit made buying at day i-1 and selling at day i-1.
//			curProfit = curProfit < 0 ? 0 : curProfit; // Find the price lower than the price bought in.
//			                                           // set curProfit to 0 as buying in with the prices[i] and 
//													   // the curProfit at day i is 0 since the difference buying 
//													   // and selling at the same day with the same price is 0.			
//			maxProfit = curProfit > maxProfit ? curProfit : maxProfit;
//		}
//		return maxProfit;
//	}
//};
//
//int main() 
//{
//	Solution solution;
//	std::vector<int> testCase1 = { 7,1,5,3,6,4 };
//	std::vector<int> testCase2 = { 7,6,4,3,1 };
//	std::cout << solution.maxProfitA(testCase1) << std::endl;
//	std::cout << solution.maxProfitA(testCase2) << std::endl;
//	std::cout << solution.maxProfitB(testCase1) << std::endl;
//	std::cout << solution.maxProfitB(testCase2) << std::endl;
//	std::cout << solution.maxProfitC(testCase1) << std::endl;
//	std::cout << solution.maxProfitC(testCase2) << std::endl;
//	std::cin.get();
//	return 0;
//}