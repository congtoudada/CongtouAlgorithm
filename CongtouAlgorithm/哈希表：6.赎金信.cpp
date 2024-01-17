#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> umap;
        for (auto c : ransomNote)
        {
            umap[c]++;
        }
        for (auto c : magazine)
        {
            umap[c]--;
        }
        for (auto pair : umap)
        {
            if (pair.second > 0) return false;
        }
        return true;
    }
};
