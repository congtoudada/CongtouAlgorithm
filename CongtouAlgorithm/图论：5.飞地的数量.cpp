#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int count = 0;
    int dir[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} }; // 四个方向
    void dfs(vector<vector<int>>& grid, int x, int y)
    {
        grid[x][y] = 0; //变成海洋
        for (int i = 0; i < 4; i++)
        {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            // 超过边界
            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;
            // 不符合条件，不继续遍历
            if (grid[nextx][nexty] == 0) continue;
            dfs(grid, nextx, nexty);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        int result = 0;
        // 遍历最左侧与左右侧节点
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1) dfs(grid, i, 0);
            if (grid[i][m - 1] == 1) dfs(grid, i, m - 1);
        }
        //遍历最上侧与最下侧节点
        for (int i = 0; i < m; i++)
        {
            if (grid[0][i] == 1) dfs(grid, 0, i);
            if (grid[n - 1][i] == 1) dfs(grid, n - 1, i);
        }
        //遍历整张图，统计岛屿数
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) result++;
            }
        }
        return result;
    }
};