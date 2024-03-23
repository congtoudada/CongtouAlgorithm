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
//	//std::vector<vector<int>> dp(prop_count, vector<int>(bag_weight + 1, 0));
//	std::vector<int> dp(bag_weight + 1, 0);
//	//初始化dp（全部初始化为0）
//	
//	//遍历：顺序遍历物品，再倒序遍历背包
//	//如果颠倒顺序，那每个重量就只能取一个最适合的物品，肯定不符合要求
//	for (int i = 0; i < prop_count; i++) 
//	{
//		for (int j = bag_weight; j > 0; j--)
//		{
//			if (j - weight[i] >= 0)
//				dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
//		}
//		cout << "print dp: ";
//		for (int j = 0; j <= bag_weight; j++)
//		{
//			cout << dp[j] << " ";
//		}
//		cout << endl;
//	}
//	cout << "max value: " << dp[bag_weight] << endl;
//
//	return 0;
//}
