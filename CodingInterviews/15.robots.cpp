#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if(rows<=0 || cols<=0)
            return 0;
        vector<vector<bool>> visited(rows, vector<bool>(cols,false));
        int cnt = helper(threshold, rows, cols, 0, 0, visited);
        return cnt;
    }
private:

    int helper(int threshold, int rows, int cols, int i, int j, vector<vector<bool> > &visited){
        if(i<0 || i>=rows || j<0 || j>=cols)
            return 0;
        if(checkRowNCol(threshold, i, j) && !visited[i][j]){
            visited[i][j] = true;
            return 1+helper(threshold,rows,cols,i+1,j,visited)
                    +helper(threshold,rows,cols,i-1,j,visited)
                    +helper(threshold,rows,cols,i,j+1,visited)
                    +helper(threshold,rows,cols,i,j-1,visited);
        }
        return 0;
    }
    
    bool checkRowNCol(int threshold, int row, int col){
        if(sumDigits(row)+sumDigits(col) <= threshold)
            return true;
        else
            return false;
    }

    int sumDigits(int row){
        int sum = 0;
        while(row){
            sum += row%10;
            row /= 10;
        }
        return sum;
    }
};

int main(){
    Solution s;
    cout<<s.movingCount(1,0,0)<<endl;
}