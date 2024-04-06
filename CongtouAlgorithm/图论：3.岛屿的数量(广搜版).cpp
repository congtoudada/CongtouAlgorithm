#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int dir[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} }; // 四个方向
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y)
    {
        queue<pair<int, int>> que;
        que.push({ x, y });
        visited[x][y] = true;
        while (!que.empty())
        {
            pair<int, int> cur = que.front();
            que.pop();
            int curx = cur.first;
            int cury = cur.second;
            for (int i = 0; i < 4; i++) {
                int nextx = curx + dir[i][0];
                int nexty = cury + dir[i][1];
                if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;  // 越界了，直接跳过
                if (!visited[nextx][nexty] && grid[nextx][nexty] == '1') 
                {
                    que.push({ nextx, nexty });
                    visited[nextx][nexty] = true; // 只要加入队列立刻标记
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int result = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    result++;
                    bfs(grid, visited, i, j); //将与其连接的陆地都标上true
                }
            }
        }
        return result;
    }
};