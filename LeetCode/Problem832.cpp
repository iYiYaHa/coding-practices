////Problem : Flipping an Image
////
////Problem Description:
////  
////  Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.
////  
////  To flip an image horizontally means that each row of the image is reversed.For example, flipping[1, 1, 0] horizontally results in[0, 1, 1].
////  
////  To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting[0, 1, 1] results in[1, 0, 0].
////  
////  Example1:
////  Input: [[1,1,0],[1,0,1],[0,0,0]]
////  Output: [[1, 0, 0], [0, 1, 0], [1, 1, 1]]
////  Explanation : First reverse each row : [[0, 1, 1], [1, 0, 1], [0, 0, 0]].
////  			  Then, invert the image : [[1, 0, 0], [0, 1, 0], [1, 1, 1]]
////  
////  Example2:
////  Input: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
////  Output : [[1, 1, 0, 0], [0, 1, 1, 0], [0, 0, 0, 1], [1, 0, 1, 0]]
////  Explanation : First reverse each row : [[0, 0, 1, 1], [1, 0, 0, 1], [1, 1, 1, 0], [0, 1, 0, 1]].
////				  Then invert the image : [[1, 1, 0, 0], [0, 1, 1, 0], [0, 0, 0, 1], [1, 0, 1, 0]]
////  
////  Note:
//// 
////  1. 1 <= A.length = A[0].length <= 20
////	2. 0 <= A[i][j] <= 1
//
//
//#include <vector>
//#include <iostream>
//
//class Solution {
//public:
//	std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& A) {
//		int colSize = A[0].size();
//		int mid = 0;
//		if (colSize % 2 == 0)
//			mid = colSize / 2 - 1;
//		else
//			mid = colSize / 2;
//		for (int i = 0; i < A.size(); ++i) {
//			for (int j = 0; j <= mid; ++j) {
//				int tmp = A[i][j] == 1 ? 0 : 1;
//				A[i][j] = A[i][A[i].size() - 1 - j] == 1 ? 0 : 1;
//				A[i][A[i].size() - 1 - j] = tmp;
//			}
//		}
//		return A;
//	}
//};
//
//int main() {
//	Solution solution;
//	std::vector<std::vector<std::vector<int>>> testCase = { {{1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0}},{{1,1,0 }, { 1,0,1 }, { 0,0,0 }} };
//	std::vector<std::vector<std::vector<int>>> testAns = { {{1, 1, 0, 0},{0, 1, 1, 0},{0, 0, 0, 1},{1, 0, 1, 0}},{{1, 0, 0 }, { 0, 1, 0 }, { 1, 1, 1 }} };
//	for (int i = 0; i < testCase.size();++i) {
//		if (solution.flipAndInvertImage(testCase[i]) == testAns[i]) {
//			std::cout << "Test case " << i << " passed.\n";
//		}
//		else {
//			std::cout << "Test case " << i << " failed.\n";
//		}
//	}
//	std::cin.get();
//	return 0;
//}