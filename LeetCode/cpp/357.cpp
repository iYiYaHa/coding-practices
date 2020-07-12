////Problem : Count Numbers with Unique Digits
////
////Problem Description:
////  Given a non-negative integer n, count all numbers with unique digits, x, where 0 ¡Ü x < 10^n
////
////  Example:
////  Input: 2
////  Output: 91
////  Explanation : The answer should be the total numbers in the range of 0 ¡Ü x < 100,
////  excluding 11, 22, 33, 44, 55, 66, 77, 88, 99
//
//#include<iostream>
//#include<vector>
//
//#define max(a,b) ((a)>(b)?(a):(b))
//
//class Solution {
//public:
//	int countNumbersWithUniqueDigits(int n) {
//		if (n == 0)
//			return 1;
//		std::vector<int> dp(n + 1, 1);
//		int sum = 0;
//		for (int i = 1; i <= n && i <= 10; ++i) {
//			if (i == 2)
//				dp[i] = (11 - i)* (dp[i - 1] - 1);
//			else
//				dp[i] = (11 - i) * dp[i - 1];
//			sum += dp[i];
//		}
//		return sum;
//	}
//};
//
//int main() {
//	Solution solution;
//	std::vector<int> testCase = { 0,1,2,3,10,11,100 };
//	std::vector<int> ans = {1,10,91,739,8877691 ,8877691 ,8877691 };
//	for (int i = 0; i < testCase.size();++i) {
//		if (solution.countNumbersWithUniqueDigits(testCase[i]) == ans[i])
//			std::cout << "test case " << testCase[i] << " passed.\n";
//		else
//			std::cout << "test case " << testCase[i] << " failed.\n";
//	}
//	std::cin.get();
//	return 0;
//}
