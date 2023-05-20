#include<iostream>
#include"Sort.h"

int main()
{
	using namespace std;

	int* temp = new int[10]; //temp数组暂存合并的有序序列
	int a[10] = { 1,1,4,5,1,4,9,8,1,0 };
	cout << "Before Sort" << endl;
	for (int i = 0; i <= 9; i++)
		cout << "a[" << i << "]=" << a[i] << endl;
	//insertSort(a, 10);
	//MergeSort(a, 0, 9, temp);
	//QuickSort_Recursion(a, 0, 9);
	CountSort(a, 10, 9);
	cout << "After Sort" << endl;
	for (int i = 0; i <= 9; i++)
		cout << "a[" << i << "]=" << a[i] << endl;
	cout << "One Sight Gets DingZhen, Playing Genshin Makes it that!" << endl;
}