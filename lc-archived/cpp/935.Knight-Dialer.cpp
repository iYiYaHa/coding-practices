#include<vector>
#include<numeric>
class Solution {
	const std::vector<std::vector<int>> moves = {
										   {4,6},{6,8},{7,9},{4,8},
										   {3,9,0},{},{1,7,0},
										   {2,6},{1,3},{4,2},
	};
	const int MOD = 1e9 + 7;
public:
	int knightDialer(int N) {
		std::vector<std::vector<int>> dp(2, std::vector<int>(10, 1));

		for (int i = 2; i <= N; ++i)
			for (int j = 0; j <= 9; ++j)
				dp[i % 2][j] = std::accumulate(moves[j].begin(),
					moves[j].end(),
					0,
					[&](int a, int b) {
				return (a + dp[(i - 1) % 2][b]) % MOD;
			});
		return std::accumulate(dp[N % 2].begin(), dp[N % 2].end(), 0, [&](int a, int b) {return (a + b) % MOD; });

	}
};