#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> printMatrix(vector<vector<int>> matrix)
    {
        vector<int> ans;

        int rows = matrix.size();
        if (rows <= 0)
            return ans;

        int cols = matrix[0].size();
        if (cols <= 0)
            return ans;

        for (int start = 0; 2 * start < rows && 2 * start < cols; ++start) // 2*a<b 而不是 a<b/2
        {
            vector<int> circle = printCircle(matrix, rows, cols, start);
            ans.insert(ans.end(), circle.begin(), circle.end());
        }
        return ans;
    }

private:
    vector<int> printCircle(const vector<vector<int>> &matrix, int rows, int cols, int start)
    {
        vector<int> ans;
        int endX = rows - 1 - start;
        int endY = cols - 1 - start;

        //top left -> top right
        for (int col = start; col <= endY; ++col)
        {
            ans.push_back(matrix[start][col]);
        }

        if (start < endX)
        {
            //top right -> bottom right
            for (int row = start + 1; row <= endX; ++row)
            {
                ans.push_back(matrix[row][endY]);
            }
        }

        if (start < endX)
        {
            //bottom right -> bottom left
            for (int col = endY - 1; col >= start; --col)
            {
                ans.push_back(matrix[endX][col]);
            }
        }
        if (start < endY)
        {
            //bottom left -> top left
            for (int row = endX - 1; row > start; --row)
            {
                ans.push_back(matrix[row][start]);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    // vector<vector<int>> matrix = {{1}, {2}, {3}, {4}};
    // vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8}};
    // vector<vector<int>> matrix = {{1}};
    // vector<vector<int>> matrix = {{1, 2, 3, 4}};
    // vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    vector<vector<int>> matrix = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    vector<int> res = s.printMatrix(matrix);
    for (int num : res)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}