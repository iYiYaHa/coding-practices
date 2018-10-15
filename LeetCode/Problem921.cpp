////Problem : Minimum Add to Make Parentheses Valid
////
////Problem Description:
////  Given a string S of '(' and ')' parentheses, we add the minimum number of 
//// parentheses ( '(' or ')', and in any positions ) so that the resulting 
//// parentheses string is valid.
//// 
//// Formally, a parentheses string is valid if and only if:
//// 
//// It is the empty string, or
//// * It can be written as AB(A concatenated with B), where A and B are 
//// * valid strings, or
//// * It can be written as(A), where A is a valid string.
//// 
//// Given a parentheses string, return the minimum number of parentheses we must add to make the resulting string valid.
//
////  Example 1:
////		Input: "())"
////		Output : 1
//// 
////  Example 2 :
////		Input : "((("
////		Output : 3
//// 
////  Example 3 :
////		Input : "()"
////		Output : 0
//// 
////  Example 4 :
////		Input : "()))(("
////		Output : 4
//// 
////  Note :
//// 
////  1. S.length <= 1000
////  2. S only consists of '(' and ')' characters.
//
//#include <iostream>
//#include <vector>
//#include <string>
//#define max(a,b) ((a)>(b)?(a):(b))
//
//class Solution {
//public:
//	int minAddToMakeValid(std::string S) {
//		int left = 0;
//		int right = 0;
//		int sum = 0;
//		for (int i = 0; i < S.size(); ++i) {
//			if (S[i] == '(') {
//				++left;
//			}
//			else {//S[i]==')'
//				if (left >= 1) {
//					left -= 1;
//
//				}
//				else {
//					sum += 1;
//				}
//			}
//		}
//		return sum + left + right;
//	}
//};
//int main() {
//	std::vector<std::string> testCase = { "())","(((", "()","()))((" };
//	std::vector<int> testAns = { 1,3,0,4 };
//	for (int i = 0; i < testCase.size(); ++i) {
//		bool result = Solution().minAddToMakeValid(testCase[i]) == testAns[i];
//		if (result)
//			std::cout << "Test case " << i + 1 << "passed with solution A." << std::endl;
//		else
//			std::cout << "Test case " << i + 1 << "failed with solution A." << std::endl;
//	}
//	std::cin.get();
//	return 0;
//}