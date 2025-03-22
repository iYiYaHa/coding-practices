class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        if(matrix == null || matrix.length == 0 || matrix[0].length == 0) 
            return false;
        int row = 0, col = matrix[0].length-1;
        while(row < matrix.length && col >=0){
            if(matrix[row][col] == target)
                return true;
            else if(matrix[row][col] > target)
                col -= 1;
            else
                row += 1;
        }
        return false;
    }
}