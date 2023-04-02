#pragma once
#include<iostream>
#include<string>
#include"LinkStack.h"
#include<algorithm>

template<class T>
class Caculator
{
private:
	char* priorities[] =
	{
		//       +-*/()
		/* + */ ">><<<>",
		/* - */ ">><<<>",
		/* * */ ">>>><>",
		/* / */ ">>>><>",
		/* ( */ "<<<<<=",
		/* ) */ "XXXXXX",
	};//��������ȼ�

	int getNum(char c)
	{
		switch (c)
		{
		case '+':return 0;
		case '-':return 1;
		case '*':return 2;
		case '/':return 3;
		case '(':return 4;
		case ')':return 5;
		}
	}

	string Convert(string s)
	{
		using std::string

			string suffix_expression = "";//��ź�׺���ʽ
		Stack<char> op; //����������ջ
		op.InitStack();


		if (isdigit(s[temp]))
			suffix_expression += s[temp];//���������ʽ��temp���ַ������֣�������׺���ʽ
		else
		{
			switch (s[temp])
			{
			case '(':
				op.Push(s[temp]);
				break;
			case ')':
				while (!op.IsEmpty() && op.GetStackTop() != '(')
				{
					suffix_expression += op.GetStackTop();//���������������
					op.Pop();
				}
				op.Pop();//����������
				break;
			default:
				//�����'('����ջ���������'('�����ȼ�����ջ������ջ
				if (op.GetStackTop() == '(' || (op.GetStackTop() != '(' && priorities[getNum(op.GetStackTop())][getNum(s[temp])] == '<'))
				{
					op.Push(s[temp]);
				}
				else //�����ȼ�С��ջ��
				{
					while (priorities[getNum(op.GetStackTop())][getNum(s[temp])] == '>')
					{
						suffix_expression += op.GetStackTop();
						op.Pop();
					}
					op.Push(s[temp]);
				}
				break;
			}
		}
	}
};
