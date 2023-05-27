#include<iostream>
#include"Sort.h"
#include<Windows.h>
#include"Timer.h"
#include<vector>
#include"dataCreator.h"

void test_data_10k()
{

}

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

	std::cout << "--------------------------------------------------------------------------------------" << std::endl;
	std::cout << "10k data:" << std::endl;
	{
		int* temp_10k = new int[10000]; //temp数组暂存合并的有序序列
		std::cout << std::endl;

		std::cout << "InsertSort:" << std::endl;
		memcpy(a, &data_10k[0], 10000*sizeof(int));
		Time_Start(start);
		InsertSort(a, 10000);
		Time_Consuming(start);
		std::cout << std::endl;

		std::cout << "MergeSort:" << std::endl;
		memcpy(a, &data_10k[0], 10000 * sizeof(int));
		Time_Start(start);
		MergeSort(a, 0, 9999, temp_10k);
		Time_Consuming(start);
		std::cout << std::endl;

		std::cout << "QuickSort_Recursion:" << std::endl;
		memcpy(a, &data_10k[0], 10000 * sizeof(int));
		Time_Start(start);
		QuickSort_Recursion(a, 0, 9999);
		Time_Consuming(start);
		std::cout << std::endl;

		std::cout << "CountSort:" << std::endl;
		memcpy(a, &data_10k[0], 10000 * sizeof(int));
		Time_Start(start);
		CountSort(a, 10000, 9999);
		Time_Consuming(start);
		std::cout << std::endl;

		std::cout << "RadixCountSort:" << std::endl;
		memcpy(a, &data_10k[0], 10000 * sizeof(int));
		Time_Start(start);
		RadixCountSort(a, 10000);
		Time_Consuming(start);
		std::cout << std::endl;

		delete[] temp_10k;
		delete[] a;
	}
	std::cout << "--------------------------------------------------------------------------------------" << std::endl;


	std::cout << "--------------------------------------------------------------------------------------" << std::endl;
	std::cout << "50k data:" << std::endl;
	{
		int* temp_50k = new int[50000]; //temp数组暂存合并的有序序列
		std::cout << std::endl;

		std::cout << "InsertSort:" << std::endl;
		memcpy(b, &data_50k[0], 50000 * sizeof(int));
		Time_Start(start);
		InsertSort(b, 50000);
		Time_Consuming(start);
		std::cout << std::endl;

		std::cout << "MergeSort:" << std::endl;
		memcpy(b, &data_50k[0], 50000 * sizeof(int));
		Time_Start(start);
		MergeSort(b, 0, 49999, temp_50k);
		Time_Consuming(start);
		std::cout << std::endl;

		std::cout << "QuickSort_Recursion:" << std::endl;
		memcpy(b, &data_50k[0], 50000 * sizeof(int));
		Time_Start(start);
		QuickSort_Recursion(b, 0, 49999);
		Time_Consuming(start);
		std::cout << std::endl;

		std::cout << "CountSort:" << std::endl;
		memcpy(b, &data_50k[0], 50000 * sizeof(int));
		Time_Start(start);
		CountSort(b, 50000, 9999);
		Time_Consuming(start);
		std::cout << std::endl;

		std::cout << "RadixCountSort:" << std::endl;
		memcpy(b, &data_50k[0], 50000 * sizeof(int));
		Time_Start(start);
		RadixCountSort(b, 50000);
		Time_Consuming(start);
		std::cout << std::endl;

		delete[] temp_50k;
		delete[] b;
	}
	std::cout << "--------------------------------------------------------------------------------------" << std::endl;


	std::cout << "--------------------------------------------------------------------------------------" << std::endl;
	std::cout << "200k data:" << std::endl;
	{
		int* temp_200k = new int[200000]; //temp数组暂存合并的有序序列
		std::cout << std::endl;

		std::cout << "InsertSort:" << std::endl;
		memcpy(c, &data_200k[0], 200000 * sizeof(int));
		Time_Start(start);
		InsertSort(c, 200000);
		Time_Consuming(start);
		std::cout << std::endl;

		std::cout << "MergeSort:" << std::endl;
		memcpy(c, &data_200k[0], 200000 * sizeof(int));
		Time_Start(start);
		MergeSort(c, 0, 199999, temp_200k);
		Time_Consuming(start);
		std::cout << std::endl;

		std::cout << "QuickSort_Recursion:" << std::endl;
		memcpy(c, &data_200k[0], 200000 * sizeof(int));
		Time_Start(start);
		QuickSort_Recursion(c, 0, 199999);
		Time_Consuming(start);
		std::cout << std::endl;

		std::cout << "CountSort:" << std::endl;
		memcpy(c, &data_200k[0], 200000 * sizeof(int));
		Time_Start(start);
		CountSort(c, 200000, 9999);
		Time_Consuming(start);
		std::cout << std::endl;

		std::cout << "RadixCountSort:" << std::endl;
		memcpy(c, &data_200k[0], 200000 * sizeof(int));
		Time_Start(start);
		RadixCountSort(c, 200000);
		Time_Consuming(start);
		std::cout << std::endl;

		delete[] temp_200k;
		delete[] c;
	}
	std::cout << "--------------------------------------------------------------------------------------" << std::endl;

	return 0;
}