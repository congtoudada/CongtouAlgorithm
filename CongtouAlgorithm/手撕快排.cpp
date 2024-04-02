//#include <iostream>
//
//int Partition(int arr[], int low, int high)
//{
//	//将low所处元素设为Pivot
//	int pivot = arr[low];
//	while(low < high)
//	{
//		while (low < high && arr[high] >= pivot) high--;
//		arr[low] = arr[high];
//		while (low < high && arr[low] <= pivot) low++;
//		arr[high] = arr[low];
//	}
//	arr[low] = pivot;
//	return low;
//}
//
//void QuickSortCore(int arr[], int low, int high)
//{
//	if (low < high)
//	{
//		//划分
//		int pivotIdx = Partition(arr, low, high);
//		QuickSortCore(arr, low, pivotIdx - 1);
//		QuickSortCore(arr, pivotIdx + 1, high);
//	}
//}
//
//
//void QuickSort(int arr[], int length)
//{
//	QuickSortCore(arr, 0, length-1); //左闭右闭
//}
//
//int main()
//{
//	int arr[] = { 5, 3, 2, 4, 1 };
//	QuickSort(arr, 5);
//	for (int i = 0; i < 5; i++)
//	{
//		std::cout << arr[i] << std::endl;
//	}
//}