#pragma once
#include <iostream>

template<class T>
class QueueNode //���н��
{
public:
	T data;
	QueueNode<T>* next;
	QueueNode(T input_data, QueueNode<T>* pt = nullptr)  //���캯��
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
	Queue() //���캯������ʼ��������β���Ϊ��
	{
		_front = nullptr;
		_back = nullptr;
	}

	~Queue() //��������������Delete����
	{
		Delete();
	}

	bool PushQueue(T data) //����
	{
		if (_front == nullptr)
		{
			_front = _back = new QueueNode<T>(data);
			if (_front == nullptr)
			{
				std::cout << "����ʧ��" << std::endl;
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
				std::cout << "����ʧ��" << std::endl;
				return 0;
			}
		}
		return 1;
	}

	bool PopQueue() //����
	{
		if (IsEmpty())//������Ϊ��
		{
			std::cout << "����Ϊ�գ�����ʧ��" << std::endl;
			return 0;
		}
		else
		{
			QueueNode<T>* popnode = _front;
			_front = _front->next;
			std::cout << "Ҫ���еĶ���Ԫ��Ϊ:" << popnode->data << std::endl;
			delete(popnode);
			return 1;
		}
	}

	T GetFront()  //��ȡ����Ԫ��
	{
		if (IsEmpty())
		{
			std::cout << "����Ϊ�գ���ȡʧ��" << std::endl;
			return 0;
		}
		else
		{
			std::cout << "����Ԫ��Ϊ:" << _front->data << std::endl;
			return _front->data;
		}
	}

	bool IsEmpty() //�ж϶����Ƿ�Ϊ��
	{
		if (_front == nullptr) //����Ϊ�շ���1�����򷵻�0
			return 1;
		else return 0;
	}

	bool Delete() //ɾ������
	{
		if (IsEmpty())
		{
			std::cout << "����Ϊ�գ�ɾ��ʧ��" << std::endl;
			return 0;
		}
		else
		{
			while (_front != nullptr)
			{
				_back = _front;
				_front = _front->next;
				std::cout << "����ɾ�����н��Ԫ��Ϊ:" << _back->data << std::endl;
				delete(_back);
			}
			std::cout << "ɾ���ɹ�" << std::endl;
			return 1;
		}
	}

	int GetSize() //��ȡ���г���
	{
		if (IsEmpty())
		{
			std::cout << "����Ϊ��" << std::endl;
			return 0;
		}
		else
		{
			QueueNode<T>* pt = _front;
			int count = 0; //��������
			while (pt != nullptr)
			{
				count++;
				pt = pt->next;
			}
			return count;
		}
	}

	T GetData(int num) //��ȡ����������н������
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

	void Travel() //�������
	{
		if (IsEmpty())
		{
			std::cout << "����Ϊ�գ��޷�����" << std::endl;
			return;
		}
		QueueNode<T>* pt = _front;
		std::cout << "�����Ƕ��ס�" << std::endl;
		while (pt != nullptr)
		{
			std::cout << "�ö��н��Ԫ��Ϊ" << pt->data << std::endl;
			pt = pt->next;
		}
		std::cout << "�����Ƕ�β��" << std::endl;
		return;
	}
};