#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int count = 0;
    int dir[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} }; // 四个方向
    void dfs(vector<vector<char>>& grid, int x, int y)
    {
        grid[x][y] = 'A'; //变成'A'
        for (int i = 0; i < 4; i++)
        {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            // 超过边界
            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;
            // 符合条件，继续遍历
            if (grid[nextx][nexty] == 'O')
            {
                dfs(grid, nextx, nexty);
            }
        }
    }

    void solve(vector<vector<char>>& board)
    {
        int n = board.size();
        int m = board[0].size();
        int result = 0;
        // 遍历最左侧与左右侧节点
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][m - 1] == 'O') dfs(board, i, m - 1);
        }
        //遍历最上侧与最下侧节点
        for (int i = 0; i < m; i++)
        {
            if (board[0][i] == 'O') dfs(board, 0, i);
            if (board[n - 1][i] == 'O') dfs(board, n - 1, i);
        }
        //遍历整张图
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'A') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};