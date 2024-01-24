#include <string>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string result;
        for (auto c : s)
        {
            if (result.empty() || result.back() != c)
                result.push_back(c);
            else result.pop_back();
        }
        return result;
    }
};