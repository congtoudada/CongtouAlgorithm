#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> result;
        int hash[27];
        //得到每个字符最远出现位置
        int preSum = -1;
        for (int i = 0; i < s.size(); i++)
        {
            hash[s[i] - 'a'] = i;
        }
        //遍历，依次取字母最远处的最大值，如果下标与最远处位置相同则记录
        int cur = -1;
        for (int i = 0; i < s.size(); i++)
        {
            cur = max(hash[s[i] - 'a'], cur);
            if (cur == i)
            {
                result.push_back(cur - preSum);
                preSum = cur;
            }
        }
        return result;
    }
};