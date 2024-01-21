#include<iostream>
using namespace std;
int main1() {
    string s;
    while (cin >> s) {
        int count = 0; // 统计数字的个数
        int old_size = s.size();
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9') count++;
        }
        s.resize(old_size + count * 5);
        int new_size = s.size();
        for (int i = new_size  - 1, j = old_size - 1; i >= 0 && j >= 0; i--, j--)
        {
	        if (s[j] >= '0' && s[j] <= '9')
	        {
                s[i] = 'r';
                s[i - 1] = 'e';
                s[i - 2] = 'b';
                s[i - 3] = 'm';
                s[i - 4] = 'u';
                s[i - 5] = 'n';
                i -= 5;
	        }
            else
            {
                s[i] = s[j];
            }
        }
        cout << s << endl;
    }
    return 0;
}