#include <vector>
using namespace std;

class Solution {
public:
    int dir[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} }; // 四个方向
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y)
    {
        int ret = 1; //已经判断合法性
        for (int i = 0; i < 4; i++)
        {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
                continue;
            if (!visited[nextx][nexty] && grid[nextx][nexty] == 1)
            {
                visited[nextx][nexty] = true;
                ret += dfs(grid, visited, nextx, nexty);
            }
        }
        return ret;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        int result = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    visited[i][j] = true;
                    int count = dfs(grid, visited, i, j);
                    result = max(result, count);
                }
            }
        }
        return result;
    }
};
