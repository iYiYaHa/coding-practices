////Problem : All Paths From Source to Target
////
////Problem Description:
//// Given a directed, acyclic graph of N nodes.  Find all possible paths 
//// from node 0 to node N-1, and return them in any order.
////
//// The graph is given as follows : the nodes are 0, 1, ..., graph.length - 1.
//// graph[i] is a list of all nodes j for which the edge(i, j) exists.
////  
////  Example1:
////  Input : [[1, 2], [3], [3], []]
////  Output : [[0, 1, 3], [0, 2, 3]]
////  Explanation : The graph looks like this :
////  0--->1
////  |    |
////  v    v
////  2--->3
////  There are two paths : 0 -> 1 -> 3 and 0 -> 2 -> 3.
////
////  Note:
//// 
////  1. The number of nodes in the graph will be in the range [2, 15].
////  2. You can print different paths in any order, but you should keep the order of nodes inside one path.
//
//
//#include <iostream>
//#include <vector>
//#include <string>
//class Solution {
//private:
//	// Recursive
//	std::vector<std::vector<int>> pathBetweenNodes(std::vector<std::vector<int>> &graph, int src, int dst) {
//		if (src == dst)
//			return { { dst } };
//		std::vector<std::vector<int>> res;
//		for (int next : graph[src]) {
//			std::vector<std::vector<int>> paths = pathBetweenNodes(graph, next, dst);
//			if (paths.size() != 0) {
//				for (auto path : paths) {
//					path.insert(path.begin(), src);
//					res.push_back(path);
//				}
//			}
//		}
//		return res;
//	}
//public:
//	std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>>& graph) {
//		return pathBetweenNodes(graph, 0, graph.size() - 1);
//	}
//};
//int main() {
//	std::cin.get();
//	return 0;
//}