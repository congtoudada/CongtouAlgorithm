#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> result;
    string path;
    unordered_map<int, string> lettermap = {
		{2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"}
    };
    vector<string> letterCombinations(string digits) {
        if (digits == "") return vector<string>();
	    backtracking(digits, 0);
        return result;
    }

    void backtracking(const string& digits, int index)
    {
	    if (path.size() == digits.size())
	    {
            result.push_back(path);
            return;
	    }
        int key = digits[index] - '0';
        string s = lettermap[key];
        for (int i = 0; i < s.size(); i++)
        {
            path.push_back(s[i]);
            backtracking(digits, index + 1);
            path.pop_back();
        }
    }
};