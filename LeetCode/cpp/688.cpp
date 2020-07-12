//#include<iostream>
//#include <vector>
//
//class SolutionA
//{
//public:
//	const std::vector<std::pair<int, int>> MOVES = { {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {-1, 2}, {1, 2}, {-1, -2}, {1, -2} };
//	double knightProbability(int N, int K, int r, int c)
//	{
//		if (r >= N || r < 0 || c >= N || c < 0)
//			return 0;
//		std::vector<std::vector<double>> A = std::vector<std::vector<double>>(N, std::vector<double>(N, 0));
//		A[r][c] = 1;
//		for (int step = 0; step < K; ++step)
//		{
//			std::vector<std::vector<double>> B = std::vector<std::vector<double>>(N, std::vector<double>(N, 0));
//			for (int i = 0; i < N; ++i)
//			{
//				for (int j = 0; j < N; ++j)
//				{
//					if (A[i][j] == 0) continue;
//					for (auto move : MOVES)
//					{
//						int row_pos = i + move.first;
//						int col_pos = j + move.second;
//						if (row_pos < N && row_pos >= 0 && col_pos >= 0 && col_pos < N)
//							B[row_pos][col_pos] += A[i][j] * 0.125;
//					}
//				}
//			}
//			std::swap(A, B);
//		}
//		double res = 0;
//		for (auto a : A)
//		{
//			for (auto b : a)
//			{
//				res += b;
//			}
//		}
//		return res;
//	}
//};
//class SolutionB
//{
//public:
//	const std::vector<std::pair<int, int>> MOVES = { {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {-1, 2}, {1, 2}, {-1, -2}, {1, -2} };
//	double knightProbability(int N, int K, int r, int c)
//	{
//		if (r >= N || r < 0 || c >= N || c < 0)
//			return 0;
//		std::vector<std::vector<double>> A = std::vector<std::vector<double>>(N, std::vector<double>(N, 0));
//		std::vector<std::vector<double>> B = std::vector<std::vector<double>>(N, std::vector<double>(N, 0));
//		A[r][c] = 1;
//		for (int step = 0; step < K; ++step)
//		{
//			for (int i = 0; i < N; ++i)
//			{
//				for (int j = 0; j < N; ++j)
//				{
//					B[i][j] = 0;
//					for (auto move : MOVES)
//					{
//						int row_pos = i + move.first;
//						int col_pos = j + move.second;
//						if (row_pos < N && row_pos >= 0 && col_pos >= 0 && col_pos < N)
//							B[i][j] += A[row_pos][col_pos] * 0.125;
//					}
//				}
//			}
//			std::swap(A, B);
//		}
//		double res = 0;
//		for (auto a : A)
//		{
//			for (auto b : a)
//			{
//				res += b;
//			}
//		}
//		return res;
//	}
//};
//
//class SolutionC
//{
//public:
//	const std::vector<std::pair<int, int>> MOVES = { {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {-1, 2}, {1, 2}, {-1, -2}, {1, -2} };
//	double knightProbability(int N, int K, int r, int c)
//	{
//		std::vector<std::vector<std::vector<double>>> mem(N, std::vector<std::vector<double>>(N, std::vector<double>(K + 1, -1)));
//		return helper(N, K, r, c, mem);
//	}
//private:
//	double helper(int N, int K, int r, int c, std::vector<std::vector<std::vector<double>>> &mem) {
//		if (r >= N || r < 0 || c >= N || c < 0)
//			return 0;
//		if (mem[r][c][K] != -1)
//			return mem[r][c][K];
//		if (K == 0)
//			return 1;
//		double prob = 0;
//		for (auto move : MOVES)
//			prob += 0.125 * helper(N, K - 1, r + move.first, c + move.second, mem);
//		return mem[r][c][K] = prob;
//	}
//};
//
//int main() {
//	std::vector<int> testCaseN = { 1,2,3,4 };
//	std::vector<int> testCaseK = { 1,2,3,4,5 };
//	std::vector<std::pair<int, int>> testCaseStart = { {0,0},{1,2} };
//	for (int n : testCaseN) {
//		for (int K : testCaseK) {
//			for (std::pair<int, int> start : testCaseStart) {
//				double resA = SolutionA().knightProbability(n, K, start.first, start.second);
//				double resB = SolutionB().knightProbability(n, K, start.first, start.second);
//				double resC = SolutionC().knightProbability(n, K, start.first, start.second);
//				if (resA == resB && resB == resC)
//					std::cout << "Test case " << n << " " << K << " " << start.first << " " << start.second <<" passed."<< std::endl;
//				else
//					std::cout << "Test case " << n << " " << K << " " << start.first << " " << start.second <<" failed."<< std::endl;
//
//			}
//		}
//	}
//	return 0;
//}