#include <vector>

class Solution {
public:
	std::vector<std::vector<int>> generateMatrix(int n) {
		std::vector<std::vector<int>> result(n, std::vector<int>(n));
		int startX = 0, startY = 0, offset = 1; //循环不变量
		int count = 1;
		for (int times = 0; times < n / 2; times++)
		{
			int i = startX;
			int j = startY;
			for (j = startY ; j < n - offset; j++)
			{
				result[i][j] = count++;
			}
			for (i = startX; i < n - offset; i++)
			{
				result[i][j] = count++;
			}
			for ( ; j > startY; j--)
			{
				result[i][j] = count++;
			}
			for ( ; i > startX; i--)
			{
				result[i][j] = count++;
			}
			startX++;
			startY++;
			offset++;
		}
		if (n % 2 == 1)
		{
			result[n / 2][n / 2] = count;
		}
		return result;
    }
};
