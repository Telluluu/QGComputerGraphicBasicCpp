#pragma once
#include <iterator>
#include<iostream>

using namespace std;

//可以考虑让这个类的使用更优雅一点
//不想折腾的删除这个定义
//#define FLL_ITERATOR_FEATURE ///可选	[迭代器]

#ifdef FLL_ITERATOR_FEATURE
//这个特性要求在插入和移除时 "在形式上" 无需前一个节点，只使用当前节点即可
//这可以让调用更加优雅
#define FLL_OPTERATE_ON_THIS_FEATURE ///可选 [直接操作]
#endif

template<class T>
class LNode
{
public:
	T data;
	LNode<T>* next;
	LNode<T>()                  //构造函数
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
	//LNode<T>* pt1 = head;   //前指针
	//LNode<T>* pt2 = pt1;   //后指针
	//if (pt1->next != nullptr)
	//{
	//	pt2 = pt1;
	//	pt1 = pt1->next;   
	//	delete(pt2);       //删除前一个结点
	//}
	//delete(pt1);         //删除末尾结点
}

//template<class T>
//T& ForwardLinkedList<T>::operator[](int i)
//{
//	if (i < 0)
//	{
//		cout << "请输入一个正整数" << endl;
//		return;
//	}
//	else if (i > size)
//	{
//		cout << "链表没有那么长" << endl;
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
	if (pos <= 0)                       //输入不合理
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
			pt = pt->next;   //找到前一个结点
			pos--;
		}
		LNode<T>* newNode = new LNode<T>(i);     //创建新结点
		newNode->next = pt->next;                        //插入新结点
		pt->next = newNode;
	}
	len++;      //链表长度计数符加1一
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
		LNode<T>* pt1 = head;   //找到删除结点
		LNode<T>* pt2 = pt1;   //用于找到要删除结点的前一个结点
		while (pt1 != nullptr)
		{
			if (pos > 1)
			{
				pt1 = pt1->next;   //先让pt1到达删除结点前一个结点
				pos--;
			}
			else break;
		}
		pt2 = pt1;         //让pt2到达删除结点前一个结点
		pt1 = pt1->next;   //pt1到达要删除的结点
		pt2->next = pt1->next;
		delete(pt1);
		cout << "delete successfully" << endl;
		len--;       //链表长度计数符减一
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
void ForwardLinkedList<T>::PushFront(const T& val)  //头插，并给data赋值val
{
	Insert(val, 1);      //头插
}

template<class T>
void ForwardLinkedList<T>::PushBack(const T& val)  //尾插，并给data赋值val
{
	Insert(val, (int)Count() + 1);           //调用Count函数计算结点个数，加一实现尾插
}

template<class T>
void ForwardLinkedList<T>::PopFront()  //删除第一个结点
{
	Erase(1);
}

template<class T>
void ForwardLinkedList<T>::PopBack()  //删除最后一个结点
{
	Erase(Count());
}

template<class T>
size_t ForwardLinkedList<T>::Count()
{
	len = 0;                      //初始化结点计数符len
	LNode<T>* pt = head;
	while (pt->next != nullptr)
	{
		len++;                     //计算链表结点个数
		pt = pt->next;
	}
	return len;
}

template<class T>
bool ForwardLinkedList<T>::Empty()
{
	if (head->next == nullptr)      //头结点的next(第一个结点)为空则链表为空
	{
		cout << "The LinkedList is empty" << endl;
		return 0;
	}
	else                           //否则不为空
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
	LNode<T>* pt1 = head->next;   //前指针
	head->next = nullptr;
	LNode<T>* pt2 = pt1;   //后指针
	while (pt2 != nullptr)
	{
		pt1 = pt1->next;
		delete(pt2);       //删除前一个结点
		pt2 = pt1;
	}
	delete(pt1);         //删除末尾结点
	cout << "Clear successfully" << endl;
}

template<class T>
LNode<T>* ForwardLinkedList<T>::MidFinder()
{
	if (Empty() == 0)
	{
		return nullptr;
	}
	LNode<T>* pt1 = head;     //快指针
	LNode<T>* pt2 = pt1;      //慢指针
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