#include<iostream>
#include"LinkStack.h"
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
			break;
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
	case 1://��ջ����
		{
			std::cout << "��ջ����" << std::endl;
			Stack<int> S;
			while (1)
			{
				std::cout << "1.��ջ��ʼ��  2.��ջ  3.��ջ 4.��ȡջ��Ԫ�� 5.����ջ 6.�˳�" << std::endl;
				std::cout << "������ָ��" << std::endl;
				std::cin >> order;
				switch (order)
				{
				case 1:
				{
					S.InitStack();
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
							S.Push(data);
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
					if (!S.IsEmpty())
					{
						S.Pop();
						std::cout << "��ջ�ɹ�" << std::endl;
					}
					else std::cout << "��ջ" << std::endl;
					break;
				}
				case 4:
				{
					int top_data = S.GetStackTop();
					if (!S.IsEmpty())
						std::cout << "����ȡջ��Ԫ��" << std::endl;
					else
						std::cout << "��ջ" << std::endl;
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
	case 2://����������ʽ��ֵ�ĵļ�����
	{
		std::cout << "��û������" << std::endl;
		break;
	}
	case 3:
	{
		std::cout << "��û������" << std::endl;
		break;
	}
	default:break;
	}
}	