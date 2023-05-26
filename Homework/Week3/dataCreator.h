#pragma once
#ifndef _DATACREATOR_H
#define _DATACREATOR_H


#include"dataCreator.h"
#include<fstream>
#include<iostream>
#include <cstdlib> 
#include <ctime>
#include<vector>
#include<string>
#include<random>
#define random(a, b) (rand() % (b - a) + a)

/**
 *  @name        : void CreatRandomData(std::string data_name,int size)
 *  @description : 创建随机数据
 *  @param       : void
 */
void CreatRandomData(std::string& data_name, const int& size)
{
	using namespace std;
	fstream stream;
	stream.open(data_name,ios::out);
	// 判断文件是否打开成功
	if (!stream.is_open()) {
		cout << "文件打开失败！" << endl;
		system("pause");
		exit(-1);
	}
	srand((int)time(0)); // 产生随机种子
	for (int i = 0; i < size; i++)
	{
		stream << random(1, 10000) << " ";
	}
	stream << "\n";
	stream.close();
}

/**
 *  @name        : void CreatDataof_10k(std::vector<T> data)
 *  @description : 创建10000条随机int型数据
 *  @param       : void
 */
template<class T>
void CreatDataof_10k(std::vector<T>& data)
{
	using namespace std;
	std::string name = "data_10k.txt";
	CreatRandomData(name, 10000);
	ifstream inFile;
	inFile.open(name, ios::in);
	// 判断文件是否打开成功
	if (!inFile.is_open()) {
		cout << "文件打开失败！" << endl;
		system("pause");
		exit(-1);
	}
	int temp = 0;
	while (1) 
	{
		// 从文件中读取第一个数据，并将其打印出来
		inFile >> temp;
		data.push_back(temp);
		if (inFile.eof()) 
		{
			break;
		}
	}
}

/**
 *  @name        : void CreatDataof_50k(vector<T> data)
 *  @description : 创建50000条随机int型数据
 *  @param       : void
 */
template<class T>
void CreatDataof_50k(std::vector<T>& data)
{
	using namespace std;
	std::string name = "data_50k.txt";
	CreatRandomData(name, 50000);
	ifstream inFile;
	inFile.open(name, ios::in);
	// 判断文件是否打开成功
	if (!inFile.is_open()) 
	{
		cout << "文件打开失败！" << endl;
		system("pause");
		exit(-1);
	}
	int temp = 0;
	while (1)
	{
		// 从文件中读取第一个数据，并将其打印出来
		inFile >> temp;
		data.push_back(temp);
		if (inFile.eof()) 
		{
			break;
		}
	}
}

/**
 *  @name        : void CreatDataof_200k(vector<T> data)
 *  @description : 创建200000条随机int型数据
 *  @param       : void
 */
template<class T>
void CreatDataof_200k(std::vector<T>& data)
{
	using namespace std;
	std::string name = "data_200k.txt";
	CreatRandomData(name, 200000);
	ifstream inFile;
	inFile.open(name, ios::in);
	// 判断文件是否打开成功
	if (!inFile.is_open()) 
	{
		cout << "文件打开失败！" << endl;
		system("pause");
		exit(-1);
	}
	int temp = 0;
	while (1)
	{
		// 从文件中读取第一个数据，并将其打印出来
		inFile >> temp;
		data.push_back(temp);
		if (inFile.eof()) 
		{
			break;
		}
	}
}



/**
 *  @name        : void CreatDataof_100(vector<T> data)
 *  @description : 创建100k条各包含100个随机int型数据的数组
 *  @param       : void
 */
template<class T>
void CreatDataof_100k_100(std::vector<T>& data);



template<class T>
void datatest(std::vector<T>& data)
{
	using namespace std;
	std::string name = "test.txt";
	CreatRandomData(name, 20);
	ifstream inFile;
	inFile.open(name, ios::in);
	// 判断文件是否打开成功
	if (!inFile.is_open()) 
	{
		cout << "文件打开失败！" << endl;
		system("pause");
		exit(-1);
	}
	int temp = 0;
	while (1)
	{
		// 从文件中读取第一个数据，并将其打印出来
		inFile >> temp;
		data.push_back(temp);
		if (inFile.eof()) 
		{
			break;
		}
	}
}
#endif // !_DATACREATOR_H
