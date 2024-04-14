#include "Cong.h"

class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);

        stack<string> st;
        string word;
        while (iss >> word)
        {
            st.push(word);
        }

        string result;
        while(!st.empty())
        {
            result.append(st.top());
            st.pop();
            if (!st.empty()) result.append(" ");
        }
        return result;
    }
};