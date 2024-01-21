#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	void reverse(string& s, int start, int end) //左闭右闭
	{
		for (int i = start, j = end; i < j; i++, j--)
		{
			swap(s[i], s[j]);
		}
	}

	string reverseWords(string s) {
		//1.去掉多余的空格
		int slow = 0;
		for (int fast = 0; fast < s.size(); fast++)
		{
			if (s[fast] != ' ')
			{
				s[slow++] = s[fast];
			}
			else
			{
				if (slow != 0 && s[slow-1] != ' ')
				{
					s[slow++] = ' ';
				}
			}
		}
		if (s[slow-1] == ' ')
		{
			slow--;
		}
		s.resize(slow);
		//2.翻转整个字符串
		reverse(s, 0, s.size() - 1);
		//3.翻转局部字符串
		slow = 0;
		for (int fast = 0; fast < s.size(); fast++)
		{
			if (s[fast] == ' ')
			{
				reverse(s, slow, fast - 1);
				slow = fast + 1;
			}
		}
		reverse(s, slow, s.size() - 1); //翻转最后一个字符串
		return s;
    }
};


//int main()
//{
//	Solution solution;
//	cout << solution.reverseWords("  hello    world  C++  ");
//	cout << "end";
//	return 0;
//}