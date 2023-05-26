#include<iostream>
#include"Sort.h"
#include<Windows.h>
#include"Timer.h"
#include<vector>
#include"dataCreator.h"

int main()
{
	clock_t start = clock(); //系统时间
	std::vector<int> data_10k;
	std::vector<int> data_50k;
	std::vector<int> data_200k;
	std::vector<std::vector<int>> data_100k_100;
	std::string name = "data.txt";


	CreatRandomData(name, 10000);
	CreatDataof_10k(data_10k);
	CreatDataof_50k(data_50k);
	CreatDataof_200k(data_200k);

	int* a = new int[10000];
	int* b = new int[50000];
	int* c = new int[200000];

	std::cout << "10k data:" << std::endl;
	{
		int* temp_10k = new int[10000]; //temp数组暂存合并的有序序列

		std::cout << "InsertSort:" << std::endl;
		memcpy(a, &data_10k[0], 10000);
		Time_Start(start);
		InsertSort(a, 10000);
		Time_Consuming(start);
		std::cout << std::endl;

		std::cout << "MergeSort:" << std::endl;
		memcpy(a, &data_10k[0], 10000);
		Time_Start(start);
		MergeSort(a, 0, 9999, temp_10k);
		Time_Consuming(start);
		std::cout << std::endl;

		std::cout << "QuickSort_Recursion:" << std::endl;
		memcpy(a, &data_10k[0], 10000);
		Time_Start(start);
		QuickSort_Recursion(a, 0, 9999);
		Time_Consuming(start);
		std::cout << std::endl;
	}




	return 0;
}