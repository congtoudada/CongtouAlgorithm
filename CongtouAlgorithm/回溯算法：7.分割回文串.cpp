#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    vector<vector<string>> result;
    vector<string> path;
    bool isPalindrome(const string& s)
    {
	    for (int i = 0, j = s.size()-1; i < j ; i++, j--)
	    {
            if (s[i] != s[j]) return false;
	    }
        return true;
    }

    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return result;
    }

    //aab
    //012
    //  | | |  ( 切线 )
    //  012
    void backtracking(const string& s, int startIdx)
    {
	    if (startIdx == s.size())
	    {
            result.push_back(path);
            return;
	    }
        for (int i = startIdx; i < s.size(); i++)
        {
            string sub = s.substr(startIdx, i - startIdx + 1);
            if (!isPalindrome(sub))
            {
                continue;
            }
            path.push_back(sub);
            backtracking(s, i + 1);
            path.pop_back();
        }
    }
};

//int main()
//{
//    Solution solution;
//    solution.partition("aab");
//    return 0;
//}