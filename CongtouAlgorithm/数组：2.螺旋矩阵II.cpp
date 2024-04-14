#include "Cong.h"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        int cnt = (n + 1) / 2;
        int num = 1;
        for (int i = 0; i < cnt; i++)
        {
	        //上
            for (int col1 = i; col1 < n - i - 1; col1++)
            {
                result[i][col1] = num;
                num++;
            }
            //右
            for (int row1 = i; row1 < n - i - 1; row1++)
            {
                result[row1][n - i - 1] = num;
                num++;
            }
            //下
            for (int col2 = n - i - 1; col2 > i;  col2--)
            {
                result[n - i - 1][col2] = num;
                num++;
            }
            //左
            for (int row2 = n - i - 1; row2 > i; row2--)
            {
                result[row2][i] = num;
                num++;
            }
        }
        if (n % 2 == 1) result[n/2][n/2] = n * n;
        return result;
    }
};

//int main()
//{
//    Solution solution;
//    solution.generateMatrix(3);
//    return 0;
//}