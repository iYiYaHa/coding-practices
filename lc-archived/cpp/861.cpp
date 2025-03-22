////Problem : Score After Flipping Matrix
////
////Problem Description:
////  We have a two dimensional matrix A where each value is 0 or 1.
////  
////  A move consists of choosing any row or column, and toggling each 
////  value in that row or column: changing all 0s to 1s, and all 1s to 0s.
////  
////  After making any number of moves, every row of this matrix is 
////  interpreted as a binary number, and the score of the matrix is the 
////  sum of these numbers.
////  
////  Return the highest possible score.
////  
////  Example 1:
////  Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
////  Output: 39
////  Explanation :
////  Toggled to[[1, 1, 1, 1], [1, 0, 0, 1], [1, 1, 1, 1]].
////		0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
////  
////  Note :
////  1. 1 <= A.length <= 20
////  2. 1 <= A[0].length <= 20
////  3. A[i][j] is 0 or 1.
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <cassert>
//#include <algorithm>
//
//class Solution {
//public:
//	int matrixScore(std::vector<std::vector<int>>& A) {
//		int sizeRow = A.size();
//		int sizeCol = A[0].size();
//
//		for (int i = 0; i<sizeRow; ++i) {
//			if (A[i][0] == 0) {
//				for (int j = 0; j<sizeCol; ++j)
//					A[i][j] = A[i][j] == 0 ? 1 : 0;
//			}
//		}
//		for (int j = 0; j<sizeCol; ++j) {
//			int countZero = 0;
//			int countOne = 0;
//			for (int i = 0; i<sizeRow; ++i) {
//				if (A[i][j] == 1)
//					++countOne;
//				else
//					++countZero;
//			}
//			if (countOne<countZero) {
//				for (int i = 0; i<sizeRow; ++i)
//					A[i][j] = A[i][j] == 0 ? 1 : 0;
//			}
//		}
//		int sum = 0;
//		for (int i = 0; i<sizeRow; ++i) {
//			int num = 0;
//			for (int j = 0; j<sizeCol; ++j) {
//				num <<= 1;
//				num |= A[i][j];
//				//std::cout << A[i][j] << " ";
//			}
//			//std::cout << std::endl;
//			sum += num;
//		}
//		return sum;
//	}
//};
//
//int main() {
//	std::vector<std::vector<std::vector<int>>> testCase = { 
//		{
//			{0,0,1,1},
//			{1,0,1,0},
//			{1,1,0,0}
//		} 
//	};
//	std::vector<int> testAns = { 39 };
//	for (int i = 0; i < testCase.size(); ++i) {
//		bool res = Solution().matrixScore(testCase[i]) == testAns[i];
//		if (res) {
//			std::cout << "Test case "<<i<<" passed.\n";
//		}
//		else {
//			std::cout << "Test case "<<i<<" failed.\n";
//		}
//	}
//	std::cin.get();
//	return 0;
//}