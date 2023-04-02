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
	};//运算符优先级

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

			string suffix_expression = "";//存放后缀表达式
		Stack<char> op; //存放运算符的栈
		op.InitStack();


		if (isdigit(s[temp]))
			suffix_expression += s[temp];//如果输入表达式第temp个字符是数字，则存入后缀表达式
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
					suffix_expression += op.GetStackTop();//存入括弧内运算符
					op.Pop();
				}
				op.Pop();//弹出右括弧
				break;
			default:
				//如果是'('则入栈，如果不是'('且优先级大于栈顶则入栈
				if (op.GetStackTop() == '(' || (op.GetStackTop() != '(' && priorities[getNum(op.GetStackTop())][getNum(s[temp])] == '<'))
				{
					op.Push(s[temp]);
				}
				else //若优先级小于栈顶
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
