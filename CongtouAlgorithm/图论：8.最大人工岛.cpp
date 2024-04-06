#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int dir[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} }; // 四个方向
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, unordered_map<int, int>& gridNum, int x, int y, int mark)
    {
        if (visited[x][y] || grid[x][y] == 0) return;
        visited[x][y] = true;
        grid[x][y] = mark;
        gridNum[mark]++;
        for (int i = 0; i < 4; i++)
        {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
                continue;
            dfs(grid, visited, gridNum, nextx, nexty, mark);
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        unordered_map<int, int> gridNum; //key: 编号 value: 面积
        gridNum[0] = 0;
        int mark = 2; //mark从2开始
        bool isAllGrid = true; //可能全陆地
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (isAllGrid && grid[i][j] == 0) isAllGrid = false;
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    gridNum[mark] = 0;
                    dfs(grid, visited, gridNum, i, j, mark);
                    mark++;
                }
            }
        }

        if (isAllGrid) return m * n;
        //尝试修改，计算最大面积
        int result = 0;
        unordered_set<int> vistedGrid; //标记每次修改已访问过的岛屿
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                {
                    int curArea = 1;
                    vistedGrid.clear();
                    for (int k = 0; k < 4; k++)
                    {
                        int nextx = i + dir[k][0];
                        int nexty = j + dir[k][1];
                        if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m)
                            continue;
                        if (vistedGrid.count(grid[nextx][nexty]) == 1) continue;
                        curArea += gridNum[grid[nextx][nexty]];
                        vistedGrid.insert(grid[nextx][nexty]);
                    }
                    result = max(result, curArea);
                }
            }
        }
        return result;
    }
};

//int main()
//{
//    vector<vector<int>> grid = { {1, 0}, {0, 1} };
//    Solution solution;
//    solution.largestIsland(grid);
//    return 0;
//}