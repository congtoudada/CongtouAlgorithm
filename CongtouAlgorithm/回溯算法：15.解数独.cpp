#include <vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(0,board);
    }

    bool isValid(int row, int column, char c, vector<vector<char>>& board)
    {
        //固定列，遍历行
        for (int i = 0; i < board.size(); i++)
        {
            if (board[i][column] == c) return false;
        }
        //固定行，遍历列
        for (int i = 0; i < board[0].size(); i++)
        {
            if (board[row][i] == c) return false;
        }
        //九宫格内判断
        int startRow = row / 3 * 3;
        int startColumn = column / 3 * 3;
        for (int i = 0; i < 3; i++)
        {
	        for (int j = 0; j < 3; j++)
	        {
                if (board[startRow + i][startColumn + j] == c) return false;
	        }
        }
        return true;
    }


    bool backtracking(int startRow, vector<vector<char>>& board)
    {
        //从当前行起始处找下一个点比从0开始更快一些
	    for (int i = startRow; i < board.size(); i++)
	    {
            //遍历每一个棋盘位置
            for (int j = 0; j < board[0].size(); j++)
            {
	            //找到空的位置
                if (board[i][j] == '.')
                {
	                //依次尝试1-9填入
                    for (char c = '1'; c <= '9'; c++)
                    {
	                    if (isValid(i, j, c, board))
	                    {
                            board[i][j] = c;
                            //递归返回true
                            if (backtracking(i, board))
                                return true;
                            //回溯
                            board[i][j] = '.';
	                    }
                    }
                    //空位均不满足返回false
                    return false;
                }
            }
	    }
        //如果最后一个棋子也返回true，说明成功，返回true
        return true;
    }
};