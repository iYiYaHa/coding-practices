////Problem : Hamming Distance
////
////Problem Description:
////  The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
////  
////  Given two integers x and y, calculate the Hamming distance.
////  
////  Example:
////  Input: x = 1, y = 4
////  
////  Output: 2
////  
////  Explanation :
////  1   (0 0 0 1)
////  4   (0 1 0 0)
////        ¡ü   ¡ü
////  
////  The above arrows point to positions where the corresponding bits are different.
////  
////  Note:
//// 
////  1.0 ¡Ü x, y < 2^31.
//
//#include <vector>
//#include <iostream>
//
//class Solution {
//public:
//	int hammingDistance(int x, int y) {
//		int tmp = x ^ y;
//		int count = 0;
//		while (tmp != 0) {
//			count += tmp & 1;
//			tmp >>= 1;
//		}
//		return count;
//	}
//};
//
//int main() {
//	Solution solution;
//	std::vector<std::pair<int, int>> testCase = { {1,4},{2,5},{4,5},{7,0} };
//	std::vector<int> testAns = { 2,3,1,3 };
//	for (int i = 0; i < testCase.size();++i) {
//		if (solution.hammingDistance(testCase[i].first,testCase[i].second) == testAns[i]) {
//			std::cout << "Test case " << i << " passed.\n";
//		}
//		else {
//			std::cout << "Test case " << i << " failed.\n";
//		}
//	}
//	std::cin.get();
//	return 0;
//}