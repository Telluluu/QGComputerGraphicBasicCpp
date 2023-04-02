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
	int InitStack() //��ջ�ĳ�ʼ��
	{
		m_top = nullptr;
		return 1;
	}

	int Push(const T& data)  //��ջ
	{
		StackNode<T>* pt = new StackNode<T>;
		pt->data = data;
		pt->next = m_top;
		m_top = pt;
		return 1;
	}

	int Push(T& data)  //��ջ
	{
		StackNode<T>* pt = new StackNode<T>;
		pt->data = data;
		pt->next = m_top;
		m_top = pt;
		return 1;
	}

	int Pop() //��ջ
	{
		if (m_top == nullptr)
		{
			std::cout << "��ջ" << std::endl;
			return 0;
		}
		StackNode<T>* pt = m_top;
		m_top = m_top->next;
		delete pt;
		return 1;
	}

	T GetStackTop()//ȡջ��Ԫ�ص����ݣ����ı�ջ
	{
		if (m_top != nullptr)
			return m_top->data;
		return 0;
	}

	int StackTravel()//����ջ
	{
		if (m_top == nullptr)
		{
			std::cout << "��ջ" << std::endl;
			return 0;
		}
		StackNode<T>* pt = m_top;
		std::cout << "��ջ����" << std::endl;
		while (pt != nullptr)
		{
			std::cout << " " << pt->data << " " << std::endl;
			pt = pt->next;
		}
		std::cout << "��������" << std::endl;
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