#pragma once
#ifndef _TIMER_H
#define _TIMER_H

#include<iostream>
#include<Windows.h>
#include<time.h>

clock_t Time_Start(clock_t& start_time)
{
	start_time = clock();
	return start_time;
}

clock_t Time_Consuming(clock_t& start_time)
{
	clock_t diff = clock() - start_time;
	std::cout << "time consuming:" << diff << "ms" << std::endl;
	return diff;
}

void PrintBeforeSort(int* a, int size)
{
	using namespace std;
	std::cout << "Before Sort" << std::endl;
	for (int i = 0; i < size; i++)
		std::cout << "a[" << i << "]=" << a[i] << std::endl;
}

void PrintAfterSort(int* a,int size)
{
	using namespace std;
	std::cout << "After Sort" << std::endl;
	for (int i = 0; i < size; i++)
		std::cout << "a[" << i << "]=" << a[i] << std::endl;
}
#endif // !_TIMER_H