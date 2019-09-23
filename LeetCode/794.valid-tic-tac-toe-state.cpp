/*
 * @lc app=leetcode id=794 lang=cpp
 *
 * [794] Valid Tic-Tac-Toe State
 */
class Solution
{
public:
    bool validTicTacToe(vector<string> &board)
    {
        int N = board.size();
        vector<int> rows(N, 0), cols(N, 0);
        int xCnt = 0, oCnt = 0;
        int leftDiag = 0, rightDiag = 0;

        // Count number of x and o for each row and column.
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (board[i][j] == 'X')
                {
                    rows[i] += 1;
                    cols[j] += 1;
                    xCnt += 1;
                }
                else if (board[i][j] == 'O')
                {
                    rows[i] += -1;
                    cols[j] += -1;
                    oCnt += 1;
                }
            }
        }

        // Count x and o for both diagnoals
        for (int i = 0; i < N; ++i)
        {
            if (board[i][i] == 'X')
                leftDiag += 1;
            else if (board[i][i] == 'O')
                leftDiag -= 1;

            if (board[N - 1 - i][i] == 'X')
                rightDiag += 1;
            else if (board[N - 1 - i][i] == 'O')
                rightDiag -= 1;
        }

        // Judge winning state
        bool xWin = false, oWin = false;
        for (int i = 0; i < N; ++i)
        {
            xWin |= (rows[i] == N);
            xWin |= (cols[i] == N);
            oWin |= (rows[i] == -N);
            oWin |= (cols[i] == -N);
        }
        xWin |= ((leftDiag == N) || (rightDiag == N));
        oWin |= ((leftDiag == -N) || (rightDiag == -N));

        // Judge validation
        bool valid = true;
        if (!xWin && !oWin)
        {
            if (!(xCnt == oCnt) && !(xCnt == oCnt + 1))
            {
                valid = false;
            }
        }
        else if (xWin && oWin)
            valid = false;
        else if (xWin)
        {
            if (!(xCnt == oCnt + 1))
                valid = false;
        }
        else
        {
            if (!(xCnt == oCnt))
                valid = false;
        }
        return valid;
    }
};
