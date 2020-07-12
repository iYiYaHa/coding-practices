////Problem : Minimum ASCII Delete Sum for Two Strings
////
////Problem Description:
////  Given two strings s1, s2, find the lowest ASCII sum of deleted characters to make two strings equal.
////
////  Given a list of non - negative integers representing the amount of money of each house, 
////  determine the maximum amount of money you can rob tonight without alerting the police.
////
////  Example 1:
////  Input: s1 = "sea", s2 = "eat"
////  Output: 231
////  Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
////				 Deleting "t" from "eat" adds 116 to the sum.
////				 At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
////
////  Example 2 :
////  Input : s1 = "delete", s2 = "leet"
////  Output : 403
////  Explanation : Deleting "dee" from "delete" to turn the string into "let",
////  			  adds 100[d] + 101[e] + 101[e] to the sum.Deleting "e" from "leet" adds 101[e] to the sum.
////  			  At the end, both strings are equal to "let", and the answer is 100 + 101 + 101 + 101 = 403.
////  			  If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
////  
////  Note :
////  1. 0 < s1.length, s2.length <= 1000.
////  2. All elements of each string will have an ASCII value in[97, 122].
//#include <iostream>
//#include <string>
//#include <vector>
//#include <cassert>
//#include <algorithm>
//
//class Solution {
//public:
//	int minimumDeleteSum(std::string s1, std::string s2) {
//		std::vector<std::vector<int>> dp(s1.length() + 1, std::vector<int>(s2.length() + 1, 0));
//		for (int i = 1; i < s2.length() + 1; ++i) {
//			dp[0][i] = dp[0][i - 1] + s2[i - 1];
//		}
//		for (int i = 1; i < s1.size() + 1; ++i) {
//			dp[i][0] = dp[i - 1][0] + s1[i - 1];
//			for (int j = 1; j < s2.size() + 1; ++j) {
//				if (s1[i - 1] == s2[j - 1])
//					dp[i][j] = dp[i - 1][j - 1];
//				else
//					dp[i][j] = std::min(dp[i][j - 1] + s2[j - 1], dp[i - 1][j] + s1[i - 1]);
//			}
//		}
//		return dp[s1.size()][s2.size()];
//	}
//};
//
//std::string stringTostring(std::string input) {
//	assert(input.length() >= 2);
//	std::string result;
//	for (int i = 1; i < input.length() - 1; i++) {
//		char currentChar = input[i];
//		if (input[i] == '\\') {
//			char nextChar = input[i + 1];
//			switch (nextChar) {
//			case '\"': result.push_back('\"'); break;
//			case '/': result.push_back('/'); break;
//			case '\\': result.push_back('\\'); break;
//			case 'b': result.push_back('\b'); break;
//			case 'f': result.push_back('\f'); break;
//			case 'r': result.push_back('\r'); break;
//			case 'n': result.push_back('\n'); break;
//			case 't': result.push_back('\t'); break;
//			default: break;
//			}
//			i++;
//		}
//		else {
//			result.push_back(currentChar);
//		}
//	}
//	return result;
//}
//
//int main() {
//	std::string line;
//	while (getline(std::cin, line)) {
//		std::string s1 = stringTostring(line);
//		getline(std::cin, line);
//		std::string s2 = stringTostring(line);
//
//		int ret = Solution().minimumDeleteSum(s1, s2);
//
//		std::cout << ret << std::endl;
//	}
//	return 0;
//}