class Solution {
    public int movingCount(int m, int n, int k) {
        if(m <= 0 || n <= 0 || k < 0)
            return 0;
        boolean[][] visited = new boolean[m][n];
        return helper(m, n, 0, 0, k, visited);
    }

    private int helper(int m, int n, int row, int col, int k, boolean[][] visited){
        if(row < 0 || col < 0 || row >= m || col >= n)
            return 0;
        if(isAllowed(row, col, k) && !visited[row][col]){
            visited[row][col] = true;
            return 1 + helper(m, n, row+1, col, k, visited) + helper(m, n, row-1, col, k, visited)
                     + helper(m, n, row, col+1, k, visited) + helper(m, n, row, col-1, k, visited);
        }
        return 0;
    }

    private boolean isAllowed(int row, int col, int k){
        int rowSum = getDigitsSum(row);
        int colSum = getDigitsSum(col);
        return rowSum + colSum <= k;
    }

    private int getDigitsSum(int num){
        int sum = 0;
        while(num > 0){
            sum += num%10;
            num /= 10;
        }
        return sum;
    }
}