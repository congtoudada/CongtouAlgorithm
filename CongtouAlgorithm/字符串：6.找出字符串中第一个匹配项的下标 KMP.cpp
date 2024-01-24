#include <iostream>
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

    int strStr(string haystack, string needle) {
        if (needle.size() > haystack.size()) return -1;
        vector<int> next(needle.size());
        getNext(next, needle);
        int result = -1;
        int j = 0;
        for(int i = 0; i < haystack.size(); i++)
        {
	        if (haystack[i] == needle[j])
	        {
                j++;
                if (j == needle.size())
                {
                    result = i - j + 1;
                    break;
                }
	        }
            else
            {
                if (j > 0)
                {
                    j = next[j - 1];
                    i--;
                }
            }
        }
        return  result;
    }
};

//int main()
//{
//    string subString = "ababab";
//    vector<int> next(subString.size());
//    Solution solution;
//    solution.getNext(next, subString);
//    for (auto val : next)
//        cout << val;
//    return 0;
//}