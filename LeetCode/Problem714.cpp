////Problem : Best Time to Buy and Sell Stock with Transaction Fee
////
////Problem Description:
////  Your are given an array of integers prices, for which the i-th element 
////  is the price of a given stock on day i; and a non-negative integer fee
////  representing a transaction fee.
////  
////  You may complete as many transactions as you like, but you need to pay
////  the transaction fee for each transaction.You may not buy more than 1 
////  share of a stock at a time(ie.you must sell the stock share before you buy again.)
////  
////  Return the maximum profit you can make.
////
////  Example1:
////  Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
////  Output: 8
////  Explanation : The maximum profit can be achieved by :
////  			Buying at prices[0] = 1
////  			Selling at prices[3] = 8
////  			Buying at prices[4] = 4
////  			Selling at prices[5] = 9
////  			The total profit is((8 - 1) - 2) + ((9 - 4) - 2) = 8.
////
////  Note:
////  1. 0 < prices.length <= 50000.
////  2. 0 < prices[i] < 50000.
////  3. 0 <= fee < 50000.
//
//
//#include<iostream>
//#include<vector>
//
//#define max(a,b) ((a)>(b)?(a):(b))
//
//class Solution {
//public:
//	int maxProfit(std::vector<int>& prices, int fee) {
//		std::vector<int> dp(prices.size(), 0);
//		int buy = -prices[0] - fee;
//		for (int i = 1; i < prices.size(); ++i) {
//			int tmp = dp[i - 1];
//			tmp = max(prices[i] + buy, tmp);
//			dp[i] = tmp;
//			if ((dp[i] - fee - prices[i]) > buy)
//				buy = dp[i] - fee - prices[i];
//		}
//		return dp[prices.size() - 1];
//	}
//};
//
//int main() {
//	Solution solution;
//	std::vector<std::pair<std::vector<int>, int>> testCase = { {{1, 3, 2, 8, 4, 9},2 } };
//	std::vector<int> testAns = { 8 };
//	for (int i = 0; i < testCase.size(); ++i) {
//		if (solution.maxProfit(testCase[i].first,testCase[i].second) == testAns[i])
//			std::cout << "test case " << i << " passed.\n";
//		else
//			std::cout << "test case " << i << " failed.\n";
//	}
//	std::cin.get();
//	return 0;
//}