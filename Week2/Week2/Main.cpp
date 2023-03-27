#include<iostream>
#include"LinkStack.h"
#include<stdio.h>
#include<algorithm>
#include<string>

int main()
{
	//用order来存储输入指令
	int order = 0;
	//判断输入是否合法
	while (1)
	{
		using namespace std;
		cout << "请输入指令" << endl;
		cout << "1.测试链栈  2.四则运算计算器  3.测试队列  4.退出" << endl;
		cin >> order;
		if (std::cin.good())
			break;
		else
		{
			cout << "输入错误，请重新输入" << endl;
			cin.clear();
			cin.ignore(2048, '\n');
		}
	}
	if (order == 4)
		exit(0);
	//根据指令选择功能
	switch (order)
	{
	case 1://链栈测试
		{
			std::cout << "链栈测试" << std::endl;
			Stack<int> S;
			while (1)
			{
				std::cout << "1.链栈初始化  2.入栈  3.出栈 4.提取栈顶元素 5.遍历栈 6.退出" << std::endl;
				std::cout << "请输入指令" << std::endl;
				std::cin >> order;
				switch (order)
				{
				case 1:
				{
					S.InitStack();
					std::cout << "链栈初始化成功" << std::endl;
					break;
				}
				case 2:
				{
					int data = 0;
					while (1)
					{
						std::cout << "请输入要入栈的元素" << std::endl;
						std::cin >> data;
						if (std::cin.good())
						{
							S.Push(data);
							break;
						}
						else
						{
							std::cout << "输入错误，请重新输入" << std::endl;
							std::cin.clear();
							std::cin.ignore(2048, '\n');
						}
					}
					std::cout << "入栈成功" << std::endl;
					break;
				}
				case 3:
				{
					if (!S.IsEmpty())
					{
						S.Pop();
						std::cout << "出栈成功" << std::endl;
					}
					else std::cout << "空栈" << std::endl;
					break;
				}
				case 4:
				{
					int top_data = S.GetStackTop();
					if (!S.IsEmpty())
						std::cout << "已提取栈顶元素" << std::endl;
					else
						std::cout << "空栈" << std::endl;
					break;
				}
				case 5:
				{
					S.StackTravel();
					break;
				}
				case 6:exit(0);
				default:break;
				};
			}
		}
	case 2://四则运算表达式求值的的计算器
	{
		std::cout << "还没做好喵" << std::endl;
		break;
	}
	case 3:
	{
		std::cout << "还没做好喵" << std::endl;
		break;
	}
	default:break;
	}
}	