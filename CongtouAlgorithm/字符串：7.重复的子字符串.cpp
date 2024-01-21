#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    //next：发生不匹配时找前一个索引对应的next值的下标
	//a a b a a f
	//0 1 0 1 2 0
    void getNext(vector<int>& next, string& needle)
    {
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < needle.size(); i++)
        {
            while (j > 0 && needle[i] != needle[j]) //当前位置不匹配
            {
                j = next[j - 1];
            }
            if (needle[i] == needle[j]) j++;
            next[i] = j;
        }
    }

    bool repeatedSubstringPattern(string s) {
        vector<int> next(s.size());
        getNext(next, s);
        //最后一个元素找不到最长公共子串，则false
        if (next[s.size() - 1] == 0) return false;
        //找到最长公共子串，且恰好拼成s（原因详见文章或视频推导）
        int minRepeatLen = s.size() - next[s.size() - 1]; 
        if (s.size() % minRepeatLen == 0) return true;
        return false;
    }
};