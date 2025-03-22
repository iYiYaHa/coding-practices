////Problem : Maximum Binary Tree
////
////Problem Description:
////	Given an integer array with no duplicates.A maximum tree building on this array is defined as follow :
////		1. The root is the maximum number in the array.
////		2. The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
////		3. The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
////	Construct the maximum tree by the given array and output the root node of this tree.
////
////  Example1:
////	Input : [3, 2, 1, 6, 0, 5]
////	Output : return the tree root node representing the following tree :
////
////			 6
////			/ \
////			3  5
////			\  /
////			2 0
////			 \
////			 1
////
////  Note:
////	The size of the given array will be in the range[1, 1000].
//
//
//#include<iostream>
//#include<vector>
//
////*
//// * Definition for a binary tree node.
//// * struct TreeNode {
//// *     int val;
//// *     TreeNode *left;
//// *     TreeNode *right;
//// *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//// * };
//
//
//class Solution {
//	struct TreeNode {
//		int val;
//		TreeNode *left;
//		TreeNode *right;
//		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//	};
//public:
//	TreeNode* constructMaximumBinaryTree(std::vector<int>& nums) {
//		return constructSubMaxTree(nums, 0, nums.size() - 1);
//	}
//
//	TreeNode* constructSubMaxTree(const std::vector<int> &nums, int i, int j) {
//		if (i > j) {
//			return nullptr;
//		}
//		int maxInd = i, max = nums[i];
//		for (int k = i; k <= j; ++k) {
//			if (nums[k] > max) {
//				max = nums[k];
//				maxInd = k;
//			}
//		}
//		TreeNode *root = new TreeNode(nums[maxInd]);
//		root->left = constructSubMaxTree(nums, i, maxInd - 1);
//		root->right = constructSubMaxTree(nums, maxInd + 1, j);
//		return root;
//	}
//};
//
//int main()
//{
//	Solution solution;
//	std::vector < std::vector<int>> testCase = { {3,2,1,6,0,5 }};
//	//std::vector<int> testAns = { 4, 12, 4, 1, 2, 4 };
//	//for (int i = 0; i < testCase.size(); ++i) {
//	//	if (solution.rob(testCase[i]) == testAns[i]) {
//	//		std::cout << "Test case " << i + 1 << " passed.\n";
//	//	}
//	//	else {
//	//		std::cout << "Test case " << i + 1 << " failed.\n";
//	//	}
//	//}
//	std::cin.get();
//	return 0;
//}