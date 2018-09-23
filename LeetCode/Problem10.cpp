////Problem : Regular Expression Matching
////
////Problem Description:
////	Implement regular expression matching with support for '.' and '*'.
////	'.' Matches any single character.
////	'*' Matches zero or more of the preceding element.
////
////	The matching should cover the entire input string(not partial).
////
////	The function prototype should be :
////		  bool isMatch(const char *s, const char *p)
////
////	Some examples :
////		isMatch("aa", "a") ¡ú false
////		isMatch("aa", "aa") ¡ú true
////		isMatch("aaa", "aa") ¡ú false
////		isMatch("aa", "a*") ¡ú true
////		isMatch("aa", ".*") ¡ú true
////		isMatch("ab", ".*") ¡ú true
////		isMatch("aab", "c*a*b") ¡ú true
//
//
////"aa" "a"
////"aab" "c*a*b"
////"aa" ".*"
////"ab" ".*"
////"aaa" "a*a"
//#include<iostream>
//#include<string>
//#include<vector>
//
//class Solution {
//public:
//	//Dynamic Programming Method
//	bool isMatchDP(std::string s, std::string p) {
//		int sLen = s.length();
//		int pLen = p.length();
//		std::vector<std::vector<bool>> d(sLen, std::vector<bool>(pLen, false));
//
//		for (size_t i = 0; i < sLen; ++i) {
//			for (size_t j = 0; j < pLen; ++j) {
//				bool value = false;
//				d[i][j] = value;
//			}
//		}
//		return d[sLen - 1][pLen - 1];
//	}
//
//	//Recursive Approach(Exceed time limited)
//	bool isMatchRecursion(std::string s, std::string p) {
//		bool firstMatch = false;
//		return recursion(0, 0, s, p);
//	}
//
//	bool recursion(size_t i, size_t j, std::string s, std::string p) {
//		if (j >= p.length())
//			return i >= s.length();
//		bool firstMatch = p[j] == '.' || s[i] == p[j];
//
//		if (j + 1 < p.length() && p[j + 1] == '*')
//			return recursion(i, j + 2, s, p) || (firstMatch && recursion(i + 1, j, s, p));
//		else
//			return firstMatch && recursion(i + 1, j + 1, s, p);
//	}
//
//
//};
//
//int main()
//{
//	std::string str, pattern;
//	Solution solution;
//	while (std::cin >> str >> pattern) {
//		std::cout << (solution.isMatchRecursion(str, pattern) ? "true" : "false") << std::endl;
//	}
//	return 0;
//}