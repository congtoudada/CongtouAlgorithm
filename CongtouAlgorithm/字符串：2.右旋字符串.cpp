#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string s;
	cin.ignore();
	cin >> s;
	int len = s.size();
	string result;
	for (int i = len - n; i < len; i++)
	{
		result.push_back(s[i]);
	}
	for (int i = len - n; i < len; i++)
	{
		s.pop_back();
	}
	cout << result.append(s) << endl;
	return 0;
}

