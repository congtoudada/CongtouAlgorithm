#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int result = 0;
        int index = s.size() - 1;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        for (int i = g.size()-1; i >= 0; i--)
        {
	        if(index >= 0 && s[index] >= g[i])
	        {
                result++;
                index--;
	        }
        }
        return result;
    }
};