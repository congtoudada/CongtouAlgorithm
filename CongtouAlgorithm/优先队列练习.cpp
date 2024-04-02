//#include <iostream>
//#include <queue>
//#include <string>
//using namespace std;
//
//// 比较函数，用于定义优先级  
//struct CompareByGreater {
//	bool operator()(const int& a, const int& b) {
//		return a > b; // 注意：这里我们返回 a > b，因为我们想要一个最小堆  
//	}
//};
//
//int main()
//{
//	priority_queue<int, vector<int>, CompareByGreater> pq;
//	pq.push(5);
//	pq.push(3);
//	pq.push(4);
//	pq.push(1);
//	pq.push(2);
//
//	cout << pq.top() << endl;
//	pq.pop();
//	cout << pq.top() << endl;
//}