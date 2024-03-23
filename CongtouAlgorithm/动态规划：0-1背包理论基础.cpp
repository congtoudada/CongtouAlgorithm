////背包最大重量为4。
////物品为：
////重量	价值
////物品0	1	15
////物品1	3	20
////物品2	4	30
////问背包能背的物品最大价值是多少？
//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	int prop_count = 3;
//	int bag_weight = 4;
//	vector<int> weight = { 1, 3, 4 };
//	vector<int> value = { 15, 20 ,30 };
//	std::vector<vector<int>> dp(prop_count, vector<int>(bag_weight+1, 0));
//	//初始化dp
//	for (int i = 0; i < prop_count; i++)  //第一列
//	{
//		dp[i][0] = 0;
//	}
//	for (int i = 0; i <= bag_weight; i++)  //第一行
//	{
//		if (i >= weight[0])
//			dp[0][i] = value[0];
//	}
//	//遍历（逐行遍历：先物品，再背包，顺序可颠倒）
//	for (int i = 1; i < prop_count; i++)
//	{
//		for (int j = 1; j <= bag_weight; j++)
//		{
//			if (j - weight[i] >= 0)
//				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
//			else
//				dp[i][j] = dp[i - 1][j];
//		}
//	}
//	cout << "print dp: " << endl;
//	for (int i = 0; i < prop_count; i++)
//	{
//		for (int j = 0; j <= bag_weight; j++)
//		{
//			cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}
//
//	cout << "max value: " << dp[prop_count - 1][bag_weight] << endl;
//	return 0;
//}
