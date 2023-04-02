#pragma once
#include <iterator>
#include<iostream>

using namespace std;

//���Կ�����������ʹ�ø�����һ��
//�������ڵ�ɾ���������
//#define FLL_ITERATOR_FEATURE ///��ѡ	[������]

#ifdef FLL_ITERATOR_FEATURE
//�������Ҫ���ڲ�����Ƴ�ʱ "����ʽ��" ����ǰһ���ڵ㣬ֻʹ�õ�ǰ�ڵ㼴��
//������õ��ø�������
#define FLL_OPTERATE_ON_THIS_FEATURE ///��ѡ [ֱ�Ӳ���]
#endif

template<class T>
class LNode
{
public:
	T data;
	LNode<T>* next;
	LNode<T>()                  //���캯��
	{
		data = 0;
		next = nullptr;
	}
	LNode<T>(int i)
	{
		data = i;
		next = nullptr;
	}
};

template<class T>
class ForwardLinkedList
{
private:
	LNode<T>* head = nullptr;
	int len = 0;
	//...
public:
#ifdef FLL_ITERATOR_FEATURE
	class iterator
	{
	private:
		//...
	public:
		using iterator_concept = std::forward_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = T;
		using pointer = T*;
		using reference = T&;
		reference operator*() const;
		pointer operator->() const;
		iterator& operator++();
		iterator operator++(int);
		bool operator==(const iterator& other) const;
		bool operator!=(const iterator& other) const;
		reference operator[](difference_type  i) const;
		auto operator<=>(const iterator&) const = default;
	};

	iterator begin();
	iterator end();
#endif
public:
	ForwardLinkedList();
	~ForwardLinkedList();

	T& operator[](int i);

#ifdef FLL_ITERATOR_FEATURE
#ifdef FLL_OPTERATE_ON_THIS_FEATURE
	//default insert to the end of the list
	void Insert(const T& val, const iterator& iter = nullptr);
	void Erase(const iterator& iter);
#else
	//default insert to the end of the list
	void Insert(const T& val, const iterator& prev_iter = nullptr);
	void Erase(const iterator& prev_iter);
#endif
#else
	//default insert to the end of the list
	void Insert(const T& val, T* prev_node = nullptr);
	//default insert to the head of the list
	void Erase(T* prev_node = nullptr);
#endif

	T& Front();
	T& Back();
	void PushFront(const T& val);
	void PushBack(const T& val);
	void PopFront();
	void PopBack();

	size_t Count();
	bool Empty();

	void Clear();
	void Reverse();

	void Insert(int i, int pos);
	void Erase(int pos);
	void Print(void);
	LNode<T>* MidFinder(void);
	//... other methods
};

template<class T>
void ForwardLinkedList<T>::Print()
{
	if (head == nullptr)
	{
		cout << "Creat a LinkedList at first!" << endl;
		return;
	}
	else if (head->next == nullptr)
	{
		cout << "Insert the first Node please" << endl;
		return;
	}
	else
	{
		LNode<T>* pt = head;
		pt = pt->next;
		while (pt != nullptr)
		{
			cout << "This Node`s data is:" << pt->data << endl;
			pt = pt->next;
		}
		return;
	}
}

template<class T>
ForwardLinkedList<T>::ForwardLinkedList()
{
	head = new LNode<T>();
	head->data = 0;
}

template<class T>
ForwardLinkedList<T>::~ForwardLinkedList()
{
	Clear();
	//if (head == nullptr)
	//{
	//	return;
	//}
	//LNode<T>* pt1 = head;   //ǰָ��
	//LNode<T>* pt2 = pt1;   //��ָ��
	//if (pt1->next != nullptr)
	//{
	//	pt2 = pt1;
	//	pt1 = pt1->next;   
	//	delete(pt2);       //ɾ��ǰһ�����
	//}
	//delete(pt1);         //ɾ��ĩβ���
}

//template<class T>
//T& ForwardLinkedList<T>::operator[](int i)
//{
//	if (i < 0)
//	{
//		cout << "������һ��������" << endl;
//		return;
//	}
//	else if (i > size)
//	{
//		cout << "����û����ô��" << endl;
//		return;
//	}
//	else
//	{
//		LNode<T>* pt = head;
//		for (int temp = 0; temp <= i; temp++)
//		{
//			pt = pt->next;
//		}
//		return T& pt->data;
//	}
//}

template<class T>
void ForwardLinkedList<T>::Insert(int i, int pos)
{
	if (pos <= 0)                       //���벻����
	{
		cout << "Please input a number more  than zero" << endl;
		return;
	}
	else if (pos > len + 1)
	{
		cout << "input too big" << endl;
		return;
	}
	else
	{
		LNode<T>* pt = head;
		while (pos > 1)
		{
			pt = pt->next;   //�ҵ�ǰһ�����
			pos--;
		}
		LNode<T>* newNode = new LNode<T>(i);     //�����½��
		newNode->next = pt->next;                        //�����½��
		pt->next = newNode;
	}
	len++;      //�����ȼ�������1һ
}

template<class T>
void ForwardLinkedList<T>::Erase(int pos)
{
	if (pos <= 0)
	{
		cout << "Please input a number which is bigger than zero~" << endl;
		return;
	}
	else if (pos > len)
		cout << "number input too long!" << endl;
	else
	{
		LNode<T>* pt1 = head;   //�ҵ�ɾ�����
		LNode<T>* pt2 = pt1;   //�����ҵ�Ҫɾ������ǰһ�����
		while (pt1 != nullptr)
		{
			if (pos > 1)
			{
				pt1 = pt1->next;   //����pt1����ɾ�����ǰһ�����
				pos--;
			}
			else break;
		}
		pt2 = pt1;         //��pt2����ɾ�����ǰһ�����
		pt1 = pt1->next;   //pt1����Ҫɾ���Ľ��
		pt2->next = pt1->next;
		delete(pt1);
		cout << "delete successfully" << endl;
		len--;       //�����ȼ�������һ
	}
}

//template<class T>
//T& Front()
//{
//
//}
//
//template<class T>
//T& Back()
//{
//
//}

template<class T>
void ForwardLinkedList<T>::PushFront(const T& val)  //ͷ�壬����data��ֵval
{
	Insert(val, 1);      //ͷ��
}

template<class T>
void ForwardLinkedList<T>::PushBack(const T& val)  //β�壬����data��ֵval
{
	Insert(val, (int)Count() + 1);           //����Count�����������������һʵ��β��
}

template<class T>
void ForwardLinkedList<T>::PopFront()  //ɾ����һ�����
{
	Erase(1);
}

template<class T>
void ForwardLinkedList<T>::PopBack()  //ɾ�����һ�����
{
	Erase(Count());
}

template<class T>
size_t ForwardLinkedList<T>::Count()
{
	len = 0;                      //��ʼ����������len
	LNode<T>* pt = head;
	while (pt->next != nullptr)
	{
		len++;                     //�������������
		pt = pt->next;
	}
	return len;
}

template<class T>
bool ForwardLinkedList<T>::Empty()
{
	if (head->next == nullptr)      //ͷ����next(��һ�����)Ϊ��������Ϊ��
	{
		cout << "The LinkedList is empty" << endl;
		return 0;
	}
	else                           //����Ϊ��
	{
		cout << "The LinkedList isn't empty" << endl;
		return 1;
	}
}

template<class T>
void ForwardLinkedList<T>::Clear()
{
	if (head == nullptr || head->next == nullptr)
	{
		return;
	}
	LNode<T>* pt1 = head->next;   //ǰָ��
	head->next = nullptr;
	LNode<T>* pt2 = pt1;   //��ָ��
	while (pt2 != nullptr)
	{
		pt1 = pt1->next;
		delete(pt2);       //ɾ��ǰһ�����
		pt2 = pt1;
	}
	delete(pt1);         //ɾ��ĩβ���
	cout << "Clear successfully" << endl;
}

template<class T>
LNode<T>* ForwardLinkedList<T>::MidFinder()
{
	if (Empty() == 0)
	{
		return nullptr;
	}
	LNode<T>* pt1 = head;     //��ָ��
	LNode<T>* pt2 = pt1;      //��ָ��
	while (pt1->next != nullptr)
	{
		pt1 = pt1->next;
		pt2 = pt2->next;
		if (pt1->next != nullptr)
			pt1 = pt1->next;
		else break;
	}
	return pt2;
}