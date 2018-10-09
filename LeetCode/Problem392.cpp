////Problem : Is Subsequence
////
////Problem Description:
//// Given a string s and a string t, check if s is subsequence of t.
//// 
//// You may assume that there is only lower case English letters in 
//// both s and t.t is potentially a very long(length ~= 500, 000) 
//// string, and s is a short string(<= 100).
//// 
//// A subsequence of a string is a new string which is formed from 
//// the original string by deleting some(can be none) of the characters 
//// without disturbing the relative positions of the remaining characters. 
//// (ie, "ace" is a subsequence of "abcde" while "aec" is not).
////  
////  
////  Example1:
////  Input: s = "abc", t = "ahbgdc"
////  Output: Return true.
////  Example2:
////  Input: s = "axc", t = "ahbgdc"
////  Output: Return false.
//
//#include <iostream>
//#include <vector>
//#include <string>
//
//class Solution {
//public:
//	bool isSubsequence(std::string s, std::string t) {
//		int i = 0, j = 0;
//		while (i<s.size() && j<t.size()) {
//			if (s[i] == t[j]) {
//				++i;
//				++j;
//			}
//			else {
//				++j;
//			}
//		}
//		if (i == s.size())
//			return true;
//		else
//			return false;
//	}
//	bool isSubsequenceDP(std::string s, std::string t) {
//		int i = 0, j = 0;
//		std::vector<std::vector<bool>> dp(s.size()+1, std::vector<bool>(t.size()+1, true));
//
//		for (int j = 1; j <= t.size(); ++j)
//			dp[0][j] = true;
//		for (int i = 1; i <=s.size(); ++i) {
//			dp[i][0] = false;
//			for (int j = 1; j <= t.size();++j){
//				if(s[i-1] == t[j-1])
//				dp[i][j] = dp[i - 1][j - 1];
//				else {
//					dp[i][j] = dp[i][j - 1];
//				}
//			}
//		}
//		return dp[s.size()][t.size()];
//	}
//};
//int main() {
//	Solution solution;
//	std::vector<std::pair<std::string, std::string>> testCase = { {"abc","ahbgdc"},{"axc","ahbgdc"} };
//	std::vector<bool> testAns = { true, false };
//	for (int i = 0; i < testCase.size(); ++i) {
//		bool result = solution.isSubsequenceDP(testCase[i].first, testCase[i].second) == testAns[i];
//		if (result)
//			std::cout << "Test case " << i + 1 << " passed." << std::endl;
//		else
//			std::cout << "Test case " << i + 1 << " failed." << std::endl;
//	}
//	std::cin.get();
//	return 0;
//}