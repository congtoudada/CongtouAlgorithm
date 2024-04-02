#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1, INT_MAX - 1);
        dp[0] = 0;
        for (int i = 1; i <= sqrt(n); i++)
        {
	        for (int j = i*i; j <= n; j++)
	        {
                dp[j] = min(dp[j], dp[j - i*i] + 1);
	        }
			//for (int i = 0; i < dp.size(); i++)
			//{
			//    cout << dp[i] << "\t";
			//}
			//cout << endl;
        }
        return dp[n];
    }
};

//int main()
//{
//    Solution solution;
//    solution.numSquares(12);
//    return 0;
//}