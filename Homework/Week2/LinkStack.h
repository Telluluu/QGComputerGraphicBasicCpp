#pragma once
#include <iostream>

template<class T>
struct StackNode
{
	T data;
	StackNode<T>* next;
	StackNode<T>() {};
	StackNode<T>(const T& i)
	{
		StackNode* pt = new StackNode;
		pt->data = i;
		pt->next = nullptr;
	}
};

template<class T>
class Stack
{
private:
	StackNode<T>* m_top = nullptr;

public:
	int InitStack() //链栈的初始化
	{
		m_top = nullptr;
		return 1;
	}

	int Push(const T& data)  //入栈
	{
		StackNode<T>* pt = new StackNode<T>;
		pt->data = data;
		pt->next = m_top;
		m_top = pt;
		return 1;
	}

	int Push(T& data)  //入栈
	{
		StackNode<T>* pt = new StackNode<T>;
		pt->data = data;
		pt->next = m_top;
		m_top = pt;
		return 1;
	}

	int Pop() //出栈
	{
		if (m_top == nullptr)
		{
			std::cout << "空栈" << std::endl;
			return 0;
		}
		StackNode<T>* pt = m_top;
		m_top = m_top->next;
		delete pt;
		return 1;
	}

	T GetStackTop()//取栈顶元素的数据，不改变栈
	{
		if (m_top != nullptr)
			return m_top->data;
		return 0;
	}

	int StackTravel()//遍历栈
	{
		if (m_top == nullptr)
		{
			std::cout << "空栈" << std::endl;
			return 0;
		}
		StackNode<T>* pt = m_top;
		std::cout << "↓栈顶↓" << std::endl;
		while (pt != nullptr)
		{
			std::cout << " " << pt->data << " " << std::endl;
			pt = pt->next;
		}
		std::cout << "遍历结束" << std::endl;
		return 1;
	}
	bool IsEmpty()
	{
		if (m_top == nullptr)
			return 1;
		else
			return 0;
	}
};