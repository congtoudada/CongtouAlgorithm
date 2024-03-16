#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> result;
    vector<string> path;
    vector<string> restoreIpAddresses(string s) {
        backtracking(s, 0);
        return result;
    }

    bool isValid(const string& s)
    {
	    //1.非0开头
        if (s[0] - '0' == 0 && s.size() > 1) return false;
        if (stoi(s) < 0 || stoi(s) > 255) return false;
        return true;
    }

    //0000 -> 0.0.0.0
    //
    void backtracking(const string& s, int startIdx)
    {
	    if (path.size() == 3)
	    {
            if (s.size() - 1 - startIdx > 3) return;
            string last = s.substr(startIdx);
            if (isValid(last))
            {
                string ret = "";
                for (int i = 0; i < 3; i++)
                {
                    ret += path[i];
                    ret += ".";
                }
                ret += last;
                result.push_back(ret);
            }
	    }
        for (int i = startIdx; i < s.size(); i++)
        {
            if (i - startIdx > 2) break;
            string ret = s.substr(startIdx, i - startIdx + 1);
            if (!isValid(ret))
            {
                continue;
            }
            path.push_back(ret);
            backtracking(s, i + 1);
            path.pop_back();
        }
    }
};
