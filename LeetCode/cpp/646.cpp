////Problem : Maximum Length of Pair Chain
////
////Problem Description:
////  You are given n pairs of numbers. In every pair, the first number is always 
////  smaller than the second number.
////  
////  Now, we define a pair(c, d) can follow another pair(a, b) if and only if b < c.
////  Chain of pairs can be formed in this fashion.
////  
////  Given a set of pairs, find the length longest chain which can be formed.You needn't 
////  use up all the given pairs. You can select pairs in any order.
////
////  Example 1:
////  Input: [[1,2], [2,3], [3,4]]
////  Output: 2
////  Explanation : The longest chain is[1, 2] ->[3, 4]
////  
////  Note :
////  1. The number of given pairs will be in the range [1, 1000].
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <cassert>
//#include <algorithm>
//
//class Solution {
//public:
//	int findLongestChain(std::vector<std::vector<int>>& pairs) {
//		std::vector<int> dp(pairs.size(), 1);//DP[i] the length of the longest pair chain ending at pairs[i]
//		
//		// Sort pairs according to the order of each pair's latter element to ensure that dp[i] can only be 
//		// appended to the end of previous longest chains.
//		// If not sorted, current pair may insert to any position of previous chains.
//		std::sort(pairs.begin(), pairs.end(), [](const std::vector<int> &lhs, const std::vector<int> &rhs) {
//			return lhs[0] < rhs[0];
//		});
//		int max = 0;
//		for (int i = 1; i < pairs.size(); ++i) {
//			for (int j = 0; j < i; ++j) {
//				if (pairs[i][0] > pairs[j][1])
//					dp[i] = std::max(dp[i], dp[j] + 1);
//			}
//			max = max > dp[i] ? max : dp[i];
//		}
//		return max;
//	}
//};
//
//int main() {
//	std::vector<std::vector<std::vector<int>>> testCase = { 
//															{{1,2},{2,3},{3,4}},
//															{{-6,9},{1,6},{8,10},{-1,4},{-6,-2},{-9,8},{-5,3},{0,3}},
//															{{-1,1},{-2,7},{-5,8},{-3,8},{1,3},{-2,9},{-5,2}},
//															{{7,9},{4,5},{7,9},{-7,-1},{0,10},{3,10},{3,6},{2,3}}
//														  };
//	std::vector<int> testAns = { 2, 3,1,4 };
//	for (int i = 0; i < testCase.size(); ++i) {
//		bool res = Solution().findLongestChain(testCase[i]) == testAns[i];
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