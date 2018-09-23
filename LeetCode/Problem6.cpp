//#include<iostream>
//#include<string>
//
//class Solution {
//public:
//	std::string convert(std::string s, int numRows);
//};
//
//int main()
//{
//	std::string str;
//	int rows = 0;
//	Solution solution;
//	while (std::cin >> str)
//	{
//		std::cin >> rows;
//		std::cout << solution.convert(str, rows) << std::endl;
//	}
//
//	return 0;
//}
//
////I'm so smart!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
////std::string Solution::convert(std::string s, int numRows)
////{
////	if (numRows == 1)
////		return s;
////	std::string ans;
////	for (size_t i = 0; i < numRows && i < s.length(); ++i) {
////		int index = i;
////		ans += s[index];
////		while (index < s.length()) {
////			int formerStep = 2 * numRows - 2 * i - 2;
////			int latterStep = 2 * i;
////			//Former column
////			index += formerStep;
////			if (index >= s.length())
////				break;
////			if (index != prevIndex)
////				ans += s[index];
////			prevIndex = index;
////
////			//Latter column
////			index += latterStep;
////			if (index >= s.length())
////				break; zz
////				if (index != prevIndex)
////					ans += s[index];
////			prevIndex = index;
////		}
////	}
////
////	return ans;
////}
//
////Optimized One
//std::string Solution::convert(std::string s, int numRows)
//{
//	if (numRows == 1)
//		return s;
//	std::string ans;
//	for (size_t i = 0; i < numRows && i < s.length(); ++i) {
//		int index = i;
//		ans += s.at(index);
//		while (index < s.length()) {
//			int formerStep = 2 * numRows - 2 * i - 2;
//			int latterStep = 2 * i;
//			//Former column
//			index += formerStep;
//			if (index >= s.length())
//				break;
//			if (formerStep != 0)
//				ans += s.at(index);
//
//			//Latter column
//			index += latterStep;
//			if (index >= s.length())
//				break;
//			if (latterStep != 0)
//				ans += s.at(index);
//		}
//	}
//
//	return ans;
//}
