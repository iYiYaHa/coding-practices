////Problem : Projection Area of 3D Shapes
////
////Problem Description:
////  On a N * N grid, we place some 1 * 1 * 1 cubes that are axis-aligned with the x, y, and z axes.
////  
////  Each value v = grid[i][j] represents a tower of v cubes placed on top of grid cell(i, j).
////  
////  Now we view the projection of these cubes onto the xy, yz, and zx planes.
////  
////  A projection is like a shadow, that maps our 3 dimensional figure to a 2 dimensional plane.
////  
////  Here, we are viewing the "shadow" when looking at the cubes from the top, the front, and the side.
////  
////  Return the total area of all three projections.
////  
////  Example1:
////  Input: [[2]]
////  Output : 5
////  Example2:
////  Input: [[1,2],[3,4]]
////  Output: 17
////  Explanation :
////  Here are the three projections("shadows") of the shape made with each axis - aligned plane.
////  Example3:
////  Input: [[2,2,2],[2,1,2],[2,2,2]]
////  Output: 21
//
////  Note:
//// 
////  1. 1 <= grid.length = grid[0].length <= 50
////  2. 0 <= grid[i][j] <= 50
//
//
//#include<iostream>
//#include<vector>
//
//#define max(a,b) ((a)>(b)?(a):(b))
//
//class Solution {
//public:
//	int projectionArea(std::vector<std::vector<int>>& grid) {
//		int xy = 0, sum = 0;
//		std::vector<int> rowMax(grid.size(), 0);
//		std::vector<int> colMax(grid[0].size(), 0);
//		for (int i = 0; i < grid.size(); ++i) {
//			for (int j = 0; j < grid[i].size(); ++j) {
//				xy += grid[i][j] ? 1 : 0;
//				rowMax[i] = rowMax[i] > grid[i][j] ? rowMax[i] : grid[i][j];
//				colMax[j] = colMax[j] > grid[i][j] ? colMax[j] : grid[i][j];
//			}
//		}
//		for (auto i : rowMax)
//			sum += i;
//		for (auto i : colMax)
//			sum += i;
//		sum += xy;
//		return sum;
//	}
//};
//
//int main() {
//	Solution solution;
//	std::vector<std::vector<std::vector<int>>> testCase = { {{2, 2, 2},{2, 1, 2},{2, 2, 2}} };
//	std::vector<int> testAns = { 21 };
//	for (int i = 0; i < testCase.size(); ++i) {
//		bool result = solution.projectionArea(testCase[i]) == testAns[i];
//		if (result)
//			std::cout << "Test case " << i + 1 << " passed with solution A." << std::endl;
//		else
//			std::cout << "Test case " << i + 1 << " failed with solution A." << std::endl;
//	}
//	std::cin.get();
//	return 0;
//}