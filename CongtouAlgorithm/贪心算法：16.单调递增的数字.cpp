#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int flag = -1;
        for (int i = s.size()-1; i >= 1; i--)
        {
	        if (s[i] < s[i-1]) //后一位 < 前一位（不满足单调递增）
	        {
                flag = i; //记录当前位置
                s[i - 1] = s[i - 1] - 1;
	        }
        }
        if (flag != -1)
        {
	        for (int i = flag; i < s.size(); i++)
	        {
                s[i] = '9';
	        }
        }
        return stoi(s);
    }
};