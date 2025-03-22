////Problem : Self Dividing Numbers
////
////Problem Description:
////  A self-dividing number is a number that is divisible by every digit it contains.
////  
////  For example, 128 is a self - dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
////  
////  Also, a self - dividing number is not allowed to contain the digit zero.
////  
////  Given a lower and upper number bound, output a list of every possible self dividing number, 
////  including the bounds if possible.
////
////  Example1:
////  Input: 
////  left = 1, right = 22
////  Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
////
////  Note:
////  1. The boundaries of each input argument are 1 <= left <= right <= 10000.
//
//
//#include<iostream>
//#include<vector>
//
//#define max(a,b) ((a)>(b)?(a):(b))
//
//class Solution {
//public:
//	std::vector<int> selfDividingNumbers(int left, int right) {
//		std::vector<int> res;
//		for (int i = left; i <= right; ++i) {
//			int num = i;
//			while (num != 0) {
//				int a = num - ((num / 10) * 10);//it's much efficient than num%10;     
//				if (a == 0 || i%a != 0)
//					break;
//				num = num / 10;
//			}
//			if (num == 0)
//				res.push_back(i);
//		}
//		return res;
//	}
//};
//
//int main() {
//	Solution solution;
//	std::vector<std::pair<int, int>> testCase = { {1,22} };
//	std::vector<std::vector<int>> testAns = { { 1,2,3,4,5,6,7,8,9,11,12,15,22} };
//	for (int i = 0; i < testCase.size(); ++i) {
//		if (solution.selfDividingNumbers(testCase[i].first, testCase[i].second) == testAns[i])
//			std::cout << "test case " << i << " passed.\n";
//		else
//			std::cout << "test case " << i << " failed.\n";
//	}
//	std::cin.get();
//	return 0;
//}