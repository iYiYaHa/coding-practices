//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//
//class Solution {
//public:
//	std::string longestPalindrome(const std::string & s);
//	std::string SolutionA(std::string str);
//	std::string SolutionB(std::string str);
//	std::string SolutionC(std::string str);
//	std::string SolutionD(std::string str);
//	std::string SolutionE(std::string str);
//	std::string SolutionF(std::string str);
//	std::string manacherSolution(const std::string & s) const;
//	bool isPalindrome(std::string str, int begin, int end);
//};
//
//int main()
//{
//	int c = 0;
//	std::string str = "Hello World!";
//	Solution solution;
//	while (std::cin >> str) {
//		std::cout << "The longest palindromic substring is "
//			<< solution.longestPalindrome(str) << std::endl;
//	}
//	return 0;
//}
//
//std::string Solution::longestPalindrome(const std::string & str)
//{
//	return manacherSolution(str);
//}
//
////The naive approach
//std::string Solution::SolutionA(std::string str)
//{
//	int maxLength = 0;
//	size_t ansI = 0;
//	for (size_t i = 0; i < str.size(); ++i) {
//		for (size_t j = i; j < str.size(); ++j) {
//			int left = i;
//			int right = j;
//
//			while (left <= right && str[left] == str[right]) {//Judge whether str[i..j]
//				++left;                                      // is a palindrome string
//				--right;
//			}
//			if (left > right) {//str[i..j] is a Palindrome Substring.
//				if ((j - i + 1) > maxLength) {
//					maxLength = j - i + 1;
//					ansI = i;
//				}
//			}
//		}
//	}
//	return str.substr(ansI, maxLength);
//}
//
////The dynamic programming approach
//// m[i][j] = -1 indicates str[i..j] isn't a Palindrome
//// m[i][j] = m[i+1][j-1] + 2 if m[i+1][j-1] != -1 and str[i] == str[j]
////           -1              else
//
//std::string Solution::SolutionB(std::string str)
//{
//	int ** m = new int *[1000];
//	for (size_t i = 0; i < 1000; ++i)
//		m[i] = new int[1000];
//
//	int maxLength = 0;
//	int ansInd = 0;
//	for (size_t i = 1; i <= str.length(); ++i) {
//		for (size_t j = 0; j < str.length() && (j + i - 1) < str.length(); ++j) {
//			bool isPalidromic = false;
//			int left = j;
//			int right = j + i - 1;
//			if (i == 1) {
//				m[left][left] = 1;
//				isPalidromic = true;
//			}
//			else if (i == 2) {
//				if (str[left] == str[right]) {
//					m[left][right] = 2;
//					isPalidromic = true;
//				}
//				else
//					m[left][right] = -1;
//			}
//			else {
//				if (m[left + 1][right - 1] != -1 && (str[left] == str[right])) {
//					m[left][right] = m[left + 1][right - 1] + 2;
//					isPalidromic = true;
//				}
//				else
//					m[left][right] = -1;
//			}
//
//			if (isPalidromic == true && i > maxLength) {
//				maxLength = i;
//				ansInd = left;
//			}
//		}
//	}
//
//	//for (size_t i = 0; i < str.length(); ++i) {
//	//	for (size_t j = 0; j < str.length(); ++j) {
//	//		std::cout << m[i][j] << " ";
//	//	}
//	//	std::cout << std::endl;
//	//}
//
//	for (size_t i = 0; i < 1000; ++i)
//		delete m[i];
//	delete m;
//
//	return str.substr(ansInd, maxLength);
//}
//
////The approach using the center of palidromic substring
//
//std::string Solution::SolutionC(std::string str)
//{
//	int maxLength = 0;
//	int maxI = 0;
//	int maxJ = 0;
//	for (size_t i = 0; i < str.length(); ++i) {
//		//odd length
//		int halfLen = (i) < (str.length() - i - 1) ? i : (str.length() - i - 1);
//		int len = halfLen * 2 + 1;
//		if (len >= maxLength) {
//			int left = i;
//			int right = i;
//			//expand from the center of the substring
//			while ((left >= 0 && right < str.length()) && str[left] == str[right]) {
//				--left;
//				++right;
//			}
//			++left;
//			--right;
//			if ((right - left + 1) > maxLength) {
//				maxLength = right - left + 1;
//				maxI = left;
//				maxJ = right;
//			}
//		}
//
//		//even length
//		if ((i + 1) < str.length() && str[i] == str[i + 1]) {
//			int left = i;
//			int right = i + 1;
//			int halfLen = (left + 1) < (str.length() - right) ? (left + 1) : (str.length() - right);
//			int length = halfLen * 2;
//			if (length > maxLength) {
//				while ((left >= 0 && right < str.length())
//					&& str[left] == str[right]) {
//					--left;
//					++right;
//				}
//				++left;
//				--right;
//				if ((right - left + 1) > maxLength) {
//					maxLength = right - left + 1;
//					maxI = left;
//					maxJ = right;
//				}
//			}
//		}
//	}
//	return str.substr(maxI, maxLength);
//}
//
//std::string Solution::SolutionD(std::string str) {
//	if (str.length() < 2)
//		return str;
//	int len = str.length();
//	int maxIndex = 0;
//	int maxLen = 1;
//	for (int start = 0; len - start > maxLen / 2;) {
//		int left, right;
//		left = right = start;
//		while (right < len - 1 && str[right] == str[right + 1])
//			++right;
//		start = right + 1;
//		while (left > 0 && right < len && str[left - 1] == str[right + 1]) {
//			--left;
//			++right;
//		}
//		if (right - left + 1 > maxLen) {
//			maxLen = right - left + 1;
//			maxIndex = left;
//		}
//	}
//	return str.substr(maxIndex, maxLen);
//}
//
////The approach using the dynamic programming.
////Note that the dependency relation when using DP is important.
//std::string Solution::SolutionE(std::string str) {
//	bool d[1000][1000];
//	int maxlen = 0;
//	int max_i = 0;
//	for (int j = 0; j < str.length(); ++j) {
//		for (int i = j; i >= 0; --i) {
//			d[i][j] = false;
//			d[i][j] = str[i] == str[j] && (j - i + 1 < 3 || d[i + 1][j - 1]);
//			if (d[i][j] && j - i + 1 > maxlen) {
//				maxlen = j - i + 1;
//				max_i = i;
//			}
//		}
//	}
//	return str.substr(max_i, maxlen);
//}
//
//std::string Solution::SolutionF(std::string str)
//{
//	if (str.length() < 2)
//		return str;
//	int maxLen = 0;
//	int maxIndex = 0;
//	for (int i = 0; i < str.length(); ++i) {
//		if (isPalindrome(str, i - maxLen - 1, i)) {
//			maxIndex = i - 1 - maxLen;
//			maxLen += 2;
//		}
//		else if (isPalindrome(str, i - maxLen, i)) {
//			maxIndex = i - maxLen;
//			maxLen += 1;
//		}
//	}
//	return str.substr(maxIndex, maxLen);
//}
//
//bool Solution::isPalindrome(std::string str,int begin,int end)
//{
//	if (begin < 0)
//		return false;
//	while (begin < end) {
//		if (str[begin++] != str[end--])
//			return false;
//	}
//	return true;
//}
//
//
////This approach is an implementation of Manacher's Algorithm.
//std::string  Solution::manacherSolution(const std::string & str) const 
//{
//	std::string preStr = "$#";
//
//	//Preprocess the input string
//	for (auto i : str) {
//		preStr.push_back(i);
//		preStr.push_back('#');
//	}
//
//	int center = 0;
//	int right = 0;
//	int ansInd = 0;
//	int maxLen= 0;
//	std::vector<int> arr(preStr.length(), 1);
//	//Find the longest palidromic substring
//	for (size_t i = 1; i < preStr.length(); ++i) {
//		arr[i] = right > i ? 
//			((right - i) > arr[2 * center - i] ? arr[2* center - i] : (right- i)) : 1;
//
//		while (preStr[i + arr[i]] == preStr[i - arr[i]]) {
//			++arr[i];
//		}
//
//		if (right < i + arr[i]) {
//			center = i;
//			right = i + arr[i];
//		}
//
//		if (maxLen < arr[i]) {
//			maxLen = arr[i];
//			ansInd = (i - arr[i])/2;
//		}
//	}
//	
//	return str.substr(ansInd, maxLen - 1);
//}