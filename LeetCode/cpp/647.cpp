////Given a string, your task is to count how many palindromic substrings in this string.
////
////The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.
////
////Example 1:
////Input: "abc"
////	Output : 3
////	Explanation : Three palindromic strings : "a", "b", "c".
////	Example 2 :
////	Input : "aaa"
////	Output : 6
////	Explanation : Six palindromic strings : "a", "a", "a", "aa", "aa", "aaa".
////	Note :
////	The input string length won't exceed 1000.
//#include<string>
//#include<iostream>
//#include<vector>
//#include<memory>
//class Solution {
//public:
//	//Manacher's Algorithm
//	int countSubstrings(std::string s)
//	{
//		std::string str = "@#";
//		for (const auto &i : s) {
//			str += i;
//			str += "#";
//		}
//		str += "$";
//
//		int count = 0, length = str.length();
//		std::vector<int> rightMost(length, 0);
//		int center = 0, right = 0;
//		for (size_t i = 1; i < length-1; ++i) {
//			if (i < right) {
//				rightMost[i] = rightMost[2 * center - i] > (right-i) ? (right-i) : rightMost[2 * center - i];
//			}
//			while ((i - rightMost[i]) >= 1 &&
//				(i + rightMost[i]) < length-1 &&
//				str[i + rightMost[i]] == str[i - rightMost[i]]) {
//				++rightMost[i];
//			}
//			if ((i + rightMost[i]) > right) {
//				center = i;
//				right = i+rightMost[i];
//			}
//		}
//		for (const auto &i : rightMost)
//			count += (i)/2;
//		return count;
//	}
//	//int countSubstrings(std::string s)
//	//{
//	//	int N = s.length(), ans = 0;
//	//	for (int center = 0; center <= 2 * N - 1; ++center) {//center = odd for odd substring even for even substring
//	//		int left = center / 2;
//	//		int right = left + center % 2;
//	//		while (left >= 0 && right < N && s[left] == s[right]) {
//	//			ans++;
//	//			left--;
//	//			right++;
//	//		}
//	//	}
//	//	return ans;
//	//}
//	//int countSubstrings(std::string s)
//	//{
//	//	int count = 0, length = s.length();
//	//	for (float center = 0.5; center < length; center += 0.5) {
//	//		for (int left = int(center - 0.2), right = int(center + 1);
//	//			left >= 0 && right < length && s[left] == s[right];
//	//			++right, --left)
//	//			++count;
//	//	}
//	//	return count+length;
//	//}
//	//int countSubstrings(std::string s)
//	//{
//	//	int count = 0,length = s.length();
//	//	for (int i = 0; i < length; ++i) {
//	//		for (int j = 0; i - j >= 0 && i + j < length && s[i - j] == s[i + j]; ++j)
//	//			++count;
//	//		for (int j = 0; i - j >= 0 && i + 1 + j < length && s[i - j] == s[i + 1 + j]; ++j)
//	//			++count;
//	//	}
//	//	return count;
//	//}
//	//int countSubstrings(std::string s)
//	//{
//	//	int count = 0;
//	//	size_t length = s.size();
//	//	std::vector<std::vector<bool>> dp(length, std::vector<bool>(length, false));
//
//	//	for (int i = length - 1; i >= 0; --i) {
//	//		for (int j = i; j < length; ++j) {
//	//			dp[i][j] = ((i + 1 >= j - 1 || dp[i + 1][j - 1]) && s[i] == s[j]) ? true : false;
//	//			count = dp[i][j] ? (count + 1) : count;
//	//		}
//	//	}
//	//	//for (size_t i = 0; i < s.size(); ++i) {
//	//	//	for (size_t j = 0; j < s.size(); ++j) {
//	//	//		std::cout << "dp["<<i<<"]["<<j<<"]="<<dp[i][j] << std::endl;
//	//	//	}
//	//	//}
//	//	return count;
//	//}
//	//
//	//int countSubstrings(std::string s) {
//	//	int num = s.size();
//	//	for (float center = 0.5; center < s.size(); center += 0.5) {
//	//		int left = int(center - 0.5), right = int(center + 1);
//	//		while (left >= 0 && right < s.size() && s[left--] == s[right++]) ++num;
//	//	}
//	//	return num;
//	//}
//};
//int main() {
//	std::string str;
//	Solution solution;
//	while (std::cin >> str) {
//		std::cout << solution.countSubstrings(str) << std::endl;
//	}
//}