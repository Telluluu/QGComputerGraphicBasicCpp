#include<iostream>
#include"LinkStack.h"
#include"Queue.h"
#include<stdio.h>
#include<algorithm>
#include<string>

int main()
{
	//��order���洢����ָ��
	int order = 0;
	//�ж������Ƿ�Ϸ�
	while (1)
	{
		using namespace std;
		cout << "������ָ��" << endl;
		cout << "1.������ջ  2.�������������  3.���Զ���  4.�˳�" << endl;
		cin >> order;
		if (std::cin.good())
		{
			if (order > 0 && order <= 4)
				break;
			else cout << "�����������������" << endl;
		}
		else
		{
			cout << "�����������������" << endl;
			cin.clear();
			cin.ignore(2048, '\n');
		}
	}
	if (order == 4)
		exit(0);
	//����ָ��ѡ����
	switch (order)
	{
	case 1:
		//��ջ����std::cout << "��ջ����" << std::endl;
	{
		Stack<int> test_stack;
		while (1)
		{
			std::cout << "1.��ջ��ʼ��  2.��ջ  3.��ջ 4.��ȡջ��Ԫ�� 5.����ջ 6.�˳�" << std::endl;
			std::cout << "������ָ��" << std::endl;
			std::cin >> order;
			switch (order)
			{
			case 1:
			{
				test_stack.InitStack();
				std::cout << "��ջ��ʼ���ɹ�" << std::endl;
				break;
			}
			case 2:
			{
				int data = 0;
				while (1)
				{
					std::cout << "������Ҫ��ջ��Ԫ��" << std::endl;
					std::cin >> data;
					if (std::cin.good())
					{
						test_stack.Push(data);
						break;
					}
					else
					{
						std::cout << "�����������������" << std::endl;
						std::cin.clear();
						std::cin.ignore(2048, '\n');
					}
				}
				std::cout << "��ջ�ɹ�" << std::endl;
				break;
			}
			case 3:
			{
				if (!test_stack.IsEmpty())
				{
					test_stack.Pop();
					std::cout << "��ջ�ɹ�" << std::endl;
				}
				else std::cout << "��ջ" << std::endl;
				break;
			}
			case 4:
			{
				int top_data = test_stack.GetStackTop();
				if (!test_stack.IsEmpty())
					std::cout << "����ȡջ��Ԫ��" << std::endl;
				else
					std::cout << "��ջ" << std::endl;
				break;
			}
			case 5:
			{
				test_stack.StackTravel();
				break;
			}
			case 6:exit(0);
			default:
				std::cout << "�����������������" << std::endl;
				break;
			};
		}
	}
	case 2://����������ʽ��ֵ�ĵļ�����
	{
		std::cout << "��û������" << std::endl;
		break;
	}
	case 3:
	{
		//��ջ����std::cout << "���в���" << std::endl;
		Queue<int> test_queue;
		while (1)
		{
			std::cout << "1.����  2.����  3.��ȡ����Ԫ�� 4.ɾ������ 5.��ȡ���г���  6.��ȡ����������н������ 7.������� 8.�˳�" << std::endl;
			std::cout << "������ָ��" << std::endl;
			std::cin >> order;
			switch (order)
			{
			case 1:
			{
				int i = 0;
				std::cout << "������Ҫ�������ֵ" << std::endl;
				while (1)
				{

					std::cin >> i;
					if (std::cin.good())
						break;
					else
					{
						std::cout << "�����������������" << std::endl;
						std::cin.clear();
						std::cin.ignore(2048, '\n');
					}
				}
				test_queue.PushQueue(i);
				std::cout << "���гɹ�" << std::endl;
				break;
			}
			case 2:
			{
				test_queue.PopQueue();
				if (!test_queue.IsEmpty())
					std::cout << "���гɹ�" << std::endl;
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
				std::cout << "���г���Ϊ:" << test_queue.GetSize() << std::endl;
				break;
			}
			case 6:
			{

				int i = 0;
				std::cout << "������Ҫ��ȡ�����" << std::endl;
				while (1)
				{

					std::cin >> i;
					if (std::cin.good())
						break;
					else
					{
						std::cout << "�����������������" << std::endl;
						std::cin.clear();
						std::cin.ignore(2048, '\n');
					}
				}
				if (!test_queue.GetData(i))
				{
					std::cout << "����û����ô��������С��1" << std::endl;
					std::cout << "��ǰ���г���Ϊ:" << test_queue.GetSize() << std::endl;
					break;
				}
				printf("��%d�����н��Ԫ��Ϊ:%d\n", i, test_queue.GetData(i));
				break;
			}
			case 7:
			{
				test_queue.Travel();
				break;
			}
			case 8:exit(0);
			default:				
				std::cout << "�����������������" << std::endl; 
				break;
			};
		}
	}
	default:break;
	}
}