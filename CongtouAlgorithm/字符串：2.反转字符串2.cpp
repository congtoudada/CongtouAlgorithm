#include <string>
using namespace std;

class Solution {
public:
    void reverseString(string& s, int left, int right) {
        right -= 1;
        while (left < right)
        {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            ++left;
            --right;
        }
    }

	string reverseStr(string s, int k) {
		for (int i = 0; i < s.size(); i+=2*k)
		{
			if (i + k <= s.size()) //数量够k个
			{
                reverseString(s, i, i + k); //左闭右开
			}
            else //数量不够k个
            {
                reverseString(s, i, s.size());
            }
		}
        return s;
    }
};
