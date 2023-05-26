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
 *  @description : �����������
 *  @param       : void
 */
void CreatRandomData(std::string& data_name, const int& size)
{
	using namespace std;
	fstream stream;
	stream.open(data_name,ios::out);
	// �ж��ļ��Ƿ�򿪳ɹ�
	if (!stream.is_open()) {
		cout << "�ļ���ʧ�ܣ�" << endl;
		system("pause");
		exit(-1);
	}
	srand((int)time(0)); // �����������
	for (int i = 0; i < size; i++)
	{
		stream << random(1, 10000) << " ";
	}
	stream << "\n";
	stream.close();
}

/**
 *  @name        : void CreatDataof_10k(std::vector<T> data)
 *  @description : ����10000�����int������
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
	// �ж��ļ��Ƿ�򿪳ɹ�
	if (!inFile.is_open()) {
		cout << "�ļ���ʧ�ܣ�" << endl;
		system("pause");
		exit(-1);
	}
	int temp = 0;
	while (1) 
	{
		// ���ļ��ж�ȡ��һ�����ݣ��������ӡ����
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
 *  @description : ����50000�����int������
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
	// �ж��ļ��Ƿ�򿪳ɹ�
	if (!inFile.is_open()) 
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		system("pause");
		exit(-1);
	}
	int temp = 0;
	while (1)
	{
		// ���ļ��ж�ȡ��һ�����ݣ��������ӡ����
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
 *  @description : ����200000�����int������
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
	// �ж��ļ��Ƿ�򿪳ɹ�
	if (!inFile.is_open()) 
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		system("pause");
		exit(-1);
	}
	int temp = 0;
	while (1)
	{
		// ���ļ��ж�ȡ��һ�����ݣ��������ӡ����
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
 *  @description : ����100k��������100�����int�����ݵ�����
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
	// �ж��ļ��Ƿ�򿪳ɹ�
	if (!inFile.is_open()) 
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		system("pause");
		exit(-1);
	}
	int temp = 0;
	while (1)
	{
		// ���ļ��ж�ȡ��һ�����ݣ��������ӡ����
		inFile >> temp;
		data.push_back(temp);
		if (inFile.eof()) 
		{
			break;
		}
	}
}
#endif // !_DATACREATOR_H
