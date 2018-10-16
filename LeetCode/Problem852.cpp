////Problem : Peak Index in a Mountain Array
////
////Problem Description:
////  
////  Let's call an array A a mountain if the following properties hold:
////  
////  A.length >= 3
////  There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i - 1] < A[i] > A[i + 1] > ... > A[A.length - 1]
////  Given an array that is definitely a mountain, return any i such that A[0] < A[1] < ... A[i - 1] < A[i] > A[i + 1] > ... > A[A.length - 1].
////  
////  Example 1:
////  Input: [0,1,0]
////  Output: 1
////  Example 1:
////  Input: [0,2,1,0]
////  Output: 1
////  
////  Note :
////  1. 3 <= A.length <= 10000
////  2. 0 <= A[i] <= 10 ^ 6
////  3. A is a mountain, as defined above.
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <cassert>
//#include <algorithm>
//
//class Solution {
//public:
//	int peakIndexInMountainArray(std::vector<int>& A) {
//		int peakIndex = 0;
//		int max = 0;
//		for (int i = 0; i < A.size(); ++i) {
//			if (A[i] > max) {
//				peakIndex = i;
//				max = A[i];
//			}
//		}
//		return peakIndex;
//	}
//};
//
//int main() {
//	std::vector<std::vector<int>> testCase = { {0,2,1,0 } };
//	std::vector<int> testAns = { 1 };
//	for (int i = 0; i < testCase.size(); ++i) {
//		bool res = Solution().peakIndexInMountainArray(testCase[i]) == testAns[i];
//		if (res) {
//			std::cout << "Test case " << i << " passed.\n";
//		}
//		else {
//			std::cout << "Test case " << i << " failed.\n";
//		}
//	}
//	std::cin.get();
//	return 0;
//}