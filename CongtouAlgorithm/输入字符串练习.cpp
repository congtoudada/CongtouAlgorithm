//#include <iostream>
//#include <sstream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	cin.ignore();
//	vector<vector<string>> output;
//	while(n--)
//	{
//		string input;
//		getline(cin, input);
//		istringstream iss(input);
//		vector<string> v;
//		string word;
//		while(iss >> word)
//		{
//			v.push_back(word);
//		}
//
//		output.push_back(v);
//	}
//	for (int i = 0; i < output.size(); i++)
//	{
//		for (int j = 0; j < output[i].size(); j++)
//		{
//			cout << output[i][j] << "-";
//		}
//		cout << endl;
//	}
//	return 0;
//}