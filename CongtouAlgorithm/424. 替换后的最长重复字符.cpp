#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        //滑动窗口思想：该窗口只大不小
        int num[26];
        int left = 0, right = 0;
        int maxn = 0; //当前区间字母的最大出现次数
        int n = s.size();
        while(right < n)
        {
            int idx = s[right] - 'A';
            num[idx]++;
            maxn = max(num[idx], maxn);
            //right - left + 1：当前区间长度
            //maxn：当前区间内字母最大出现次数
            if (right - left + 1 - maxn > k) //没有合适的k可以用，滑动窗口
            {
                num[s[left] - 'A']--;
                left++;
            }
            right++;
        }
        return right - left;
    }
};
