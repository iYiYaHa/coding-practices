////Problem : Sort Array By Parity
////
////Problem Description:
//// Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.
//// 
//// You may return any answer array that satisfies this condition.
////  Example1:
////  Input: [3,1,2,4]
////  Output: [2, 4, 3, 1]
////  The outputs [4, 2, 3, 1], [2, 4, 1, 3], and[4, 2, 1, 3] would also be accepted.
//
////  Note:
//// 
////  1. 1 <= A.length <= 5000
////  2. 0 <= A[i] <= 5000
//
//
//#include<iostream>
//#include<vector>
//
//#define max(a,b) ((a)>(b)?(a):(b))
//
//class Solution {
//public:
//	std::vector<int> sortArrayByParityA(std::vector<int>& A) {
//		int head = 0, rear = A.size() - 1;
//		while (head < rear) {
//			while (A[head] % 2 == 0 && head < rear) ++head;
//			while (A[rear] % 2 != 0 && head < rear) --rear;
//			int tmp = A[head];
//			A[head] = A[rear];
//			A[rear] = tmp;
//		}
//		return A;
//	}
//	std::vector<int> sortArrayByParityB(std::vector<int>& A) {
//		for (int i = 0, k = 0; i < A.size(); ++i) {
//			if (A[i] % 2 == 0) {
//				std::swap(A[i], A[k]);
//				++k;
//			}
//		}
//		return A;
//	}
//};
//
//int main() {
//	Solution solution;
//	std::cin.get();
//	return 0;
//}