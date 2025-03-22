
// ref: https://www.cnblogs.com/hxer/p/5185143.html
// ref: https://www.cnblogs.com/new-hand/p/7745437.html

import java.util.*;

public class Solution {
    public static int solve(int[] gems) {
        if (gems.length == 0) {
            return 0;
        }
        int n = gems.length;
        int[][] dp = new int[n][n];
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; ++j) {
                dp[i][j] = j - i + 1;
                for (int k = i; k <= j; ++k) // remove with gems[k]
                {
                    if (gems[i] == gems[k]) {
                        int left = (i == k || i + 1 == k) ? 1 : dp[i + 1][k - 1];
                        int right = k + 1 <= j ? dp[k + 1][j] : 0;
                        dp[i][j] = Math.min(dp[i][j], left + right);
                    }
                }
            }
        }
        return dp[0][n - 1];
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] gems = new int[n];
        for (int i = 0; i < n; ++i) {
            gems[i] = scanner.nextInt();
        }
        System.out.println(Solution.solve(gems));
    }
}