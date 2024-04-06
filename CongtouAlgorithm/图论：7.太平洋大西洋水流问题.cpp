#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int dir[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} }; // 四个方向
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int x, int y)
    {
        if (ocean[x][y]) return; //已经被标记过的不再访问
        ocean[x][y] = true;
        for (int i = 0; i < 4; i++)
        {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx < 0 || nextx >= heights.size() || nexty < 0 || nexty >= heights[0].size())
                continue;
            if (heights[nextx][nexty] >= heights[x][y])
            {
                dfs(heights, ocean, nextx, nexty);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        vector<vector<int>> result;

        for (int i = 0; i < n; i++)
        {
            dfs(heights, pacific, i, 0);     //太平洋左
            dfs(heights, atlantic, i, m - 1); //大西洋右
        }
        for (int i = 0; i < m; i++)
        {
            dfs(heights, pacific, 0, i); //太平洋上
            dfs(heights, atlantic, n - 1, i); //大西洋下
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                {
                    result.push_back({ i, j });
                }
            }
        }
        return result;
    }
};