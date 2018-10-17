////Problem : All Possible Full Binary Trees
////
////Problem Description:
////  A full binary tree is a binary tree where each node has exactly 0 or 2 children.
////  
////  Return a list of all possible full binary trees with N nodes.Each element of the answer is the root node of one possible tree.
////  
////  Each node of each tree in the answer must have node.val = 0.
////  
////  You may return the final list of trees in any order. 
////  
////  Example1:
////  Input: 7
////  Output: [[0, 0, 0, null, null, 0, 0, null, null, 0, 0], [0, 0, 0, null, null, 0, 0, 0, 0], 
////  [0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, null, null, null, null, 0, 0], [0, 0, 0, 0, 0, null, null, 0, 0]]
////  Explanation :
////
////  Note:
//// 
////  1. 1 <= N <= 20
//
//
//#include <iostream>
//#include <vector>
//#include <string>
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     TreeNode *left;
// *     TreeNode *right;
// *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// * };
// */
//
//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//	
//};
//
//class Solution {
//public:
//	std::vector<TreeNode*> allPossibleFBT(int N) {
//		std::vector<TreeNode*> res;
//		allPossibleFBTSet(res, N);
//		return res;
//	}
//private:
//	void allPossibleFBTSet(std::vector<TreeNode*> &res, int N) {
//		if (N % 2 == 0)
//			return;
//		for (int i = 1; i <= N; ++i) {
//
//		}
//	}
//};
//int main() {
//	std::cin.get();
//	return 0;
//}