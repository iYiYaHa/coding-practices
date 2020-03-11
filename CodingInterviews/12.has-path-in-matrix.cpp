#include<iostream>

using namespace std;

class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(matrix==nullptr||str==nullptr||rows<=0||cols<=0) return false;
        
        bool *visited = new bool[rows*cols];
        memset(visited, false, rows*cols);
        
        for(int i = 0;i<rows;++i){
            for(int j = 0;j<cols;++j){
                if(helper(matrix, rows, cols, str, i, j, visited)){
                    delete []visited;
                    return true;
                }
            }
        }
        delete []visited;
        return false;
    }
private:
    bool helper(char* matrix, int rows, int cols, char* str, int i, int j, bool* visited)
    {
        if(*str == '\0') return true;
        if(i<0||i>=rows||j<0||j>=cols) return false;
        if(matrix[i*cols+j] == *str && !visited[i*cols+j]){
            visited[i*cols+j] = true;
            if (helper(matrix, rows, cols, str+1, i + 1, j, visited) || helper(matrix, rows, cols, str+1, i - 1, j, visited) ||
                helper(matrix, rows, cols, str+1, i, j-1, visited) || helper(matrix, rows, cols, str+1, i, j+1, visited))
                return true;
            visited[i*cols+j] = false;
        }
        return false;
    }
};

int main(){
    Solution s;
    char* matrix = "ABCESFCSADEE";
    //ABCD
    //SFCS
    //ADEE
    char* str="ABCCED";
    if(s.hasPath(matrix,3,4,str)){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }

}