#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> result;
    vector<string> chessboard;

    vector<vector<string>> solveNQueens(int n) {
        for (int i = 0; i < n; i++)
        {
            string chess = "";
	        for (int j = 0; j < n; j++)
	        {
                chess += ".";
	        }
            chessboard.push_back(chess);
        }
        backtracking(n, 0);
        return result;
    }

    bool isValid(int row, int column, int n)
    {
	    for (int i = 0; i < n; i++)
	    {
            //检查列方向是否有Q
            if (chessboard[i][column] == 'Q')
                return false;
            //检查行方向是否有Q (逐行回溯，天然包含行方向不相等)
            //if (chessboard[row][i] == 'Q')
            //    return false;
            //检查45度角
            int lastRow = row - i;
            if (lastRow >= 0)
            {
                int lastColumn = column - i;
                if (lastColumn >= 0 && chessboard[lastRow][lastColumn] == 'Q')
                    return false;
                lastColumn = column + i;
                if (lastColumn < n && chessboard[lastRow][lastColumn] == 'Q')
                    return false;
            }
	    }
        return true;
    }

    //n:规模
    //row:当前行
    void backtracking(int n, int row)
    {
	    if (row == n)
	    {
            result.push_back(chessboard);
            return;
	    }
        for (int i = 0; i < n; i++)
        {
	        if (isValid(row, i, n))
	        {
                chessboard[row][i] = 'Q';
                backtracking(n, row+1);
                chessboard[row][i] = '.';
	        }
        }
    }
};