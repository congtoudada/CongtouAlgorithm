#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int hash[26] = { 0 };
        for (int i = 0; i < s.size(); i++)
        {
            hash[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++)
        {
            hash[t[i] - 'a']--;
        }
        for (int i = 0; i < sizeof(hash) / sizeof(int) ; i++)
        {
            if (hash[i] != 0) return false;
        }
        return true;
    }
};
