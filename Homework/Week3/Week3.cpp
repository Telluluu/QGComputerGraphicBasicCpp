#include<iostream>
#include"Sort.h"
#include<Windows.h>
#include"Timer.h"
int main()
{
	clock_t start = clock(); //系统时间

	int* temp = new int[10]; //temp数组暂存合并的有序序列
	int a[10] = { 1,1,4,5,1,4,9,8,1,0 };
	PrintBeforeSort(a, 10);
	Time_Start(start);
	//insertSort(a, 10);
	//MergeSort(a, 0, 9, temp);
	//QuickSort_Recursion(a, 0, 9);
	//CountSort(a, 10, 9);
	RadixCountSort(a, 10);
	Time_Consuming(start);
	PrintAfterSort(a, 10);
	std::cout << "One Sight Gets DingZhen, Playing Genshin Makes it that!" << std::endl;

	int b[10] = { 1,1,0,2,0,1,0,1,2,2 };
	PrintBeforeSort(b, 10);
	Time_Start(start);
	ColorSort(b, 10);
	Time_Consuming(start);
	PrintAfterSort(b, 10);


	return 0;
}