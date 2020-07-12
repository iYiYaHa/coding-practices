//#include<iostream>
//#include<string>
//#include<sstream>
//
//class Solution {
//
//public:
//
//	int myAtoi(std::string str) {
//		if (str.empty())
//			return 0;
//		int ans = 0;
//		int sign = 1;
//		size_t i = 0;
//
//		for (; i < str.length() && isspace(str[i]); ++i)
//			;
//		if (i == str.length())
//			return 0;
//		//Decide the sign
//		if (str[i] == '-') {
//			sign = -1;
//			i += 1;
//		}
//		else if (str[i] == '+') {
//			sign = 1;
//			i += 1;
//		}
//		else {
//			sign = 1;
//		}
//
//
//		for (; i < str.length(); ++i) {
//			int num = 0;
//			int prev = ans;
//			if (str[i] >= '0' && str[i] <= '9') {
//				num = str[i] - '0';
//			}
//			else {
//				break;
//			}
//			ans = ans * 10 + num;
//			if (prev != ans / 10)
//				return sign == 1 ? INT_MAX : INT_MIN;
//		}
//
//		return sign == 1 ? ans : -ans;
//	}
//
//	int myAtoiComplex(std::string str) {
//		if (str.empty())
//			return 0;
//		int ans = 0;
//		int sign = 1;
//		size_t i = 0;
//		i = str.find_first_not_of(" ");
//		if (i == str.npos)
//			return 0;
//
//		//Decide the sign
//		if (str[i] == '-' || str[i] == '+') {
//			if (str[i] == '-')
//				sign = -1;
//			i += 1;
//		}
//
//		for (; i < str.length() && isdigit(str[i]); ++i) {
//			if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10)) {
//				return sign == 1 ? INT_MAX : INT_MIN;
//			}
//			ans = ans * 10 + (str[i] - '0');
//		}
//		return sign == 1 ? ans : -ans;
//	}
//};
//
//int main()
//{
//	Solution solution;
//	std::string str;
//	const std::string input = "0 123 -1 -123 0x1 0xa 0xab -0x1 -0xa -0xab 01 02 03 07 071 -01 -02 -03 -07 -071 2147483648 2147483649 2147483647 -2147483648 -2147483649 -2147483647";
//	std::istringstream isstrm;
//	isstrm.str(input);
//	while (isstrm >> str) {
//		std::cout << "input:" << str << " ";
//		std::cout << solution.myAtoi(str) << std::endl;
//	}
//
//	return 0;
//}