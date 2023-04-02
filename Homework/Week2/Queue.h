#pragma once
#include <iostream>

template<class T>
class QueueNode //队列结点
{
public:
	T data;
	QueueNode<T>* next;
	QueueNode(T input_data, QueueNode<T>* pt = nullptr)  //构造函数
	{
		data = input_data;
		next = pt;
	}
};

template<class T>
class Queue
{
private:
	QueueNode<T>* _front;
	QueueNode<T>* _back;

public:
	Queue() //构造函数，初始化队列首尾结点为空
	{
		_front = nullptr;
		_back = nullptr;
	}

	~Queue() //析构函数，调用Delete函数
	{
		Delete();
	}

	bool PushQueue(T data) //入列
	{
		if (_front == nullptr)
		{
			_front = _back = new QueueNode<T>(data);
			if (_front == nullptr)
			{
				std::cout << "创建失败" << std::endl;
				return 0;
			}
		}
		else
		{
			QueueNode<T>* newNode = new QueueNode<T>(data);
			_back->next = newNode;
			_back = newNode;

			if (_back == nullptr)
			{
				std::cout << "创建失败" << std::endl;
				return 0;
			}
		}
		return 1;
	}

	bool PopQueue() //出列
	{
		if (IsEmpty())//若队列为空
		{
			std::cout << "队列为空，出列失败" << std::endl;
			return 0;
		}
		else
		{
			QueueNode<T>* popnode = _front;
			_front = _front->next;
			std::cout << "要出列的队首元素为:" << popnode->data << std::endl;
			delete(popnode);
			return 1;
		}
	}

	T GetFront()  //获取队首元素
	{
		if (IsEmpty())
		{
			std::cout << "队列为空，获取失败" << std::endl;
			return 0;
		}
		else
		{
			std::cout << "队首元素为:" << _front->data << std::endl;
			return _front->data;
		}
	}

	bool IsEmpty() //判断队列是否为空
	{
		if (_front == nullptr) //队首为空返回1，否则返回0
			return 1;
		else return 0;
	}

	bool Delete() //删除队列
	{
		if (IsEmpty())
		{
			std::cout << "队列为空，删除失败" << std::endl;
			return 0;
		}
		else
		{
			while (_front != nullptr)
			{
				_back = _front;
				_front = _front->next;
				std::cout << "即将删除队列结点元素为:" << _back->data << std::endl;
				delete(_back);
			}
			std::cout << "删除成功" << std::endl;
			return 1;
		}
	}

	int GetSize() //获取队列长度
	{
		if (IsEmpty())
		{
			std::cout << "队列为空" << std::endl;
			return 0;
		}
		else
		{
			QueueNode<T>* pt = _front;
			int count = 0; //结点计数符
			while (pt != nullptr)
			{
				count++;
				pt = pt->next;
			}
			return count;
		}
	}

	T GetData(int num) //获取第任意个队列结点数据
	{
		if (num > GetSize() || num <= 0)
		{
			return 0;
		}
		else
		{
			int flag = 1;
			QueueNode<T>* pt = _front;
			while (1)
			{
				if (flag == num)
					break;
				flag++;
				pt = pt->next;
			}
			return pt->data;
		}
	}

	void Travel() //历遍队列
	{
		if (IsEmpty())
		{
			std::cout << "队列为空，无法遍历" << std::endl;
			return;
		}
		QueueNode<T>* pt = _front;
		std::cout << "↓这是队首↓" << std::endl;
		while (pt != nullptr)
		{
			std::cout << "该队列结点元素为" << pt->data << std::endl;
			pt = pt->next;
		}
		std::cout << "↑这是队尾↑" << std::endl;
		return;
	}
};