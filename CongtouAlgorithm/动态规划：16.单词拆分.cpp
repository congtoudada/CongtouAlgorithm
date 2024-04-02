#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false); //长度为i的字符串，能否被字典组成
        dp[0] = true;

        for (int i = 1; i <= s.size(); i++)
        {
	        for (int j = 0; j < wordDict.size(); j++)
	        {
                string tmp = wordDict[j];
                int tSize = tmp.size();
                if (i - tSize >= 0)
                {
                    if (dp[i - tSize] == true && s.substr(i - tSize, tmp.size()) == tmp)
                    {
                        dp[i] = true;
                    }
                }
	        }
            //for (int k = 0; k <= s.size(); k++)
            //{
            //    cout << dp[k] << " ";
            //}
            //cout << endl;
        }
        return dp[s.size()];
    }
};

//int main()
//{
//    Solution solution;
//    vector<string> data = { "leet", "code" };
//    solution.wordBreak("leetcode", data);
//    return 0;
//}