#include <vector>
using namespace std;

class Solution {
public:
    int dir[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} }; // 四个方向
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
		int n = grid.size();
		int m = grid[0].size();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (grid[i][j] == 1)
				{
					for (int k = 0; k < 4; k++)
					{
						int nextx = i + dir[k][0];
						int nexty = j + dir[k][1];
						if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m)
						{
							perimeter++;
							continue;
						}
						if (grid[nextx][nexty] == 0)
						{
							perimeter++;
						}
					}
				}
			}
		}
		return perimeter;
    }
};