#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<char, char> charMap = {
        {'(', ')'}, {'[', ']'}, {'{', '}'}
    };
    bool isValid(string s) {
        stack<char> charStack;
        if (s.size() % 2 == 1) return false;
        for (auto c : s)
        {
            if (charMap.find(c) != charMap.end()) charStack.push(charMap[c]);
            else
            {
                if (charStack.empty() || charStack.top() != c) return false;
                charStack.pop();
            }
        }
        return charStack.empty();
    }
};