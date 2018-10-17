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
//#include <stack>
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
//
//	//DFS using stack
//	std::vector<std::vector<int>> pathBetweenNodesDFS(std::vector<std::vector<int>> &graph, int src, int dst) {
//		std::stack<int> stack;
//		std::vector<std::vector<int>> res;
//		std::vector<int> path;
//		path.push_back(src);
//		stack.push(src);
//		for (int node : graph[src]) {
//			stack.push(node);
//		}
//		while (!stack.empty()) {
//			int currNode = stack.top();
//			if (currNode == path.back()) {
//				if (currNode == dst) {
//					res.push_back(path);
//				}
//				path.pop_back();
//				stack.pop();
//				continue;
//			}
//			path.push_back(currNode);
//			for (int node : graph[currNode]) {
//				stack.push(node);
//			}
//		}
//		return res;
//	}
//
//	//DFS recursive
//	std::vector<std::vector<int>> pathBetweenNodesRecursive(std::vector<std::vector<int>> &graph, int src, int dst) {
//		std::vector<int> path;
//		std::vector<std::vector<int>> paths;
//		dfs(graph, paths, path, src, dst);
//		return paths;
//	}
//
//	void dfs(std::vector<std::vector<int>> &graph, 
//							std::vector<std::vector<int>> &paths,std::vector<int> &path, int src, int dst) {
//		path.push_back(src);
//		if (src == dst) {
//			paths.push_back(path);
//		}
//		else {
//			for (int node : graph[src]) {
//				dfs(graph, paths, path, node, dst);
//			}
//		}
//		path.pop_back();
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