#include<iostream>
#include"LinkStack.h"
#include"Queue.h"
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
		{
			if (order > 0 && order <= 4)
				break;
			else cout << "输入错误，请重新输入" << endl;
		}
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
	case 1:
		//链栈测试std::cout << "链栈测试" << std::endl;
	{
		Stack<int> test_stack;
		while (1)
		{
			std::cout << "1.链栈初始化  2.入栈  3.出栈 4.提取栈顶元素 5.遍历栈 6.退出" << std::endl;
			std::cout << "请输入指令" << std::endl;
			std::cin >> order;
			switch (order)
			{
			case 1:
			{
				test_stack.InitStack();
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
						test_stack.Push(data);
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
				if (!test_stack.IsEmpty())
				{
					test_stack.Pop();
					std::cout << "出栈成功" << std::endl;
				}
				else std::cout << "空栈" << std::endl;
				break;
			}
			case 4:
			{
				int top_data = test_stack.GetStackTop();
				if (!test_stack.IsEmpty())
					std::cout << "已提取栈顶元素" << std::endl;
				else
					std::cout << "空栈" << std::endl;
				break;
			}
			case 5:
			{
				test_stack.StackTravel();
				break;
			}
			case 6:exit(0);
			default:
				std::cout << "输入错误，请重新输入" << std::endl;
				break;
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
		//链栈测试std::cout << "队列测试" << std::endl;
		Queue<int> test_queue;
		while (1)
		{
			std::cout << "1.入列  2.出列  3.获取队首元素 4.删除队列 5.获取队列长度  6.获取第任意个队列结点数据 7.历遍队列 8.退出" << std::endl;
			std::cout << "请输入指令" << std::endl;
			std::cin >> order;
			switch (order)
			{
			case 1:
			{
				int i = 0;
				std::cout << "请输入要插入的数值" << std::endl;
				while (1)
				{

					std::cin >> i;
					if (std::cin.good())
						break;
					else
					{
						std::cout << "输入错误，请重新输入" << std::endl;
						std::cin.clear();
						std::cin.ignore(2048, '\n');
					}
				}
				test_queue.PushQueue(i);
				std::cout << "入列成功" << std::endl;
				break;
			}
			case 2:
			{
				test_queue.PopQueue();
				if (!test_queue.IsEmpty())
					std::cout << "出列成功" << std::endl;
				break;
			}
			case 3:
			{
				test_queue.GetFront();
				break;
			}
			case 4:
			{
				test_queue.Delete();
				break;
			}
			case 5:
			{
				std::cout << "队列长度为:" << test_queue.GetSize() << std::endl;
				break;
			}
			case 6:
			{

				int i = 0;
				std::cout << "请输入要获取的序号" << std::endl;
				while (1)
				{

					std::cin >> i;
					if (std::cin.good())
						break;
					else
					{
						std::cout << "输入错误，请重新输入" << std::endl;
						std::cin.clear();
						std::cin.ignore(2048, '\n');
					}
				}
				if (!test_queue.GetData(i))
				{
					std::cout << "队列没有那么长或输入小于1" << std::endl;
					std::cout << "当前队列长度为:" << test_queue.GetSize() << std::endl;
					break;
				}
				printf("第%d个队列结点元素为:%d\n", i, test_queue.GetData(i));
				break;
			}
			case 7:
			{
				test_queue.Travel();
				break;
			}
			case 8:exit(0);
			default:				
				std::cout << "输入错误，请重新输入" << std::endl; 
				break;
			};
		}
	}
	default:break;
	}
}