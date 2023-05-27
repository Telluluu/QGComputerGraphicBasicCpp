#include<iostream>
#include"Sort.h"
#include<Windows.h>
#include"Timer.h"
#include<vector>
#include"dataCreator.h"

void test_data_10k()
{
	clock_t start = clock(); //系统时间
	std::vector<int> data_10k;
	CreatDataof_10k(data_10k);
	int* a = new int[10000];

	std::cout << "--------------------------------------------------------------------------------------" << std::endl;
	std::cout << "10k data:" << std::endl;
	{
		int* temp_10k = new int[10000]; //temp数组暂存合并的有序序列
		std::cout << std::endl;

		std::cout << "InsertSort:" << std::endl;
		memcpy(a, &data_10k[0], 10000 * sizeof(int));
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
}

void test_data_50k()
{
	clock_t start = clock(); //系统时间
	std::vector<int> data_50k;
	CreatDataof_50k(data_50k);
	int* b = new int[50000];

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
}

void test_data_200k()
{
	clock_t start = clock(); //系统时间
	std::vector<int> data_200k;
	CreatDataof_200k(data_200k);
	int* c = new int[200000];

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
}

void test_data_100k_100()
{
	clock_t start = clock(); //系统时间
	std::vector<std::vector<int> > data_100k_100;
	int(*d)[100] = new int[100000][100];

	std::cout << "--------------------------------------------------------------------------------------" << std::endl;
	std::cout << "(number)100k*(size)100 data:" << std::endl;
	{
		std::cout << "test data initializing..." << std::endl;
		CreatDataof_100k_100(data_100k_100);
		int* temp_100 = new int[100]; //temp数组暂存合并的有序序列
		std::cout << std::endl;

		std::cout << "InsertSort:" << std::endl;
		for(int i=0;i<100000;i++)
			std::copy(data_100k_100[i].begin(), data_100k_100[i].end(), d[i]);
		Time_Start(start);
		for(int i=0;i<100000;i++)
			InsertSort(d[i], 100);
		Time_Consuming(start);
		std::cout << std::endl;

		std::cout << "MergeSort:" << std::endl;
		for (int i = 0; i < 100000; i++)
			std::copy(data_100k_100[i].begin(), data_100k_100[i].end(), d[i]);
		Time_Start(start);
		for(int i=0;i<100000;i++)
			MergeSort(d[i], 0, 99, temp_100);
		Time_Consuming(start);
		std::cout << std::endl;

		std::cout << "QuickSort_Recursion:" << std::endl;
		for (int i = 0; i < 100000; i++)
			std::copy(data_100k_100[i].begin(), data_100k_100[i].end(), d[i]);
		Time_Start(start);
		for (int i = 0; i < 100000; i++)
			QuickSort_Recursion(d[i], 0, 99);
		Time_Consuming(start);
		std::cout << std::endl;

		std::cout << "CountSort:" << std::endl;
		for (int i = 0; i < 100000; i++)
			std::copy(data_100k_100[i].begin(), data_100k_100[i].end(), d[i]);
		Time_Start(start);
		for (int i = 0; i < 100000; i++)
			CountSort(d[i], 100, 9999);
		Time_Consuming(start);
		std::cout << std::endl;

		std::cout << "RadixCountSort:" << std::endl;
		for (int i = 0; i < 100000; i++)
			std::copy(data_100k_100[i].begin(), data_100k_100[i].end(), d[i]);
		Time_Start(start);
		for (int i = 0; i < 100000; i++)
			RadixCountSort(d[i], 100);
		Time_Consuming(start);
		std::cout << std::endl;

		delete[] temp_100;
		delete[] d;
	}
	std::cout << "--------------------------------------------------------------------------------------" << std::endl;
}

void Control();

void Menu()
{
	std::cout <<
		"1:10k amounts of data test " << std::endl <<
		"2:50k amounts of data test " << std::endl <<
		"3:200k amounts of data test " << std::endl <<
		"4:100k of 100 amounts of data test " << std::endl <<
		"5:exit" << std::endl;
	std::cout << "please input command:";
	Control();
}

void Control()
{
	int command;
	while(1)
	{
		std::cin >> command;
		switch (command)
		{
		case 1:test_data_10k();
			Menu();
			break;
		case 2:test_data_50k();
			Menu();
			break;
		case 3:test_data_200k();
			Menu();
			break;
		case 4:test_data_100k_100();
			Menu();
			break;
		case 5:exit(1);
			break;
		default:std::cout << "wrong command, please input again" << std::endl;
			std::cin.clear();
			std::cin.ignore(2048, '\n');
			std::cout << "--------------------------------------------------------------------------------------" << std::endl;
			Menu();
			break;
		}
	}
}

int main()
{




	std::string name = "data.txt";


	CreatRandomData(name, 10000);
	Menu();
	Control();

	return 0;
}