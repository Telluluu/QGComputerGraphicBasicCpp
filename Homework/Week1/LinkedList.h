#pragma once
#include <iterator>
#include<iostream>

using namespace std;

//可以考虑让这个类的使用更优雅一点
//不想折腾的删除这个定义
//#define LL_ITERATOR_FEATURE ///可选 [迭代器]

template<class T>
class D_LNode
{
public:
	D_LNode<T>* prev;          //前驱指针
	T data;                  //变量
	D_LNode<T>* next;         //后继指针
	D_LNode<T>()                  //构造函数
	{
		prev = nullptr;
		data = 0;
		next = nullptr;
	}
	D_LNode<T>(int i)
	{
		prev = nullptr;
		data = i;
		next = nullptr;
	}
};

template<class T>
class LinkedList
{
private:
	D_LNode<T>* D_head = nullptr;
	int D_len = 0;
	//...
public:
#ifdef LL_ITERATOR_FEATURE
	class iterator
	{
	private:
		//...
	public:
		using iterator_concept = std::bidirectional_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = T;
		using pointer = T*;
		using reference = T&;
		reference operator*() const;
		pointer operator->() const;
		iterator& operator++();
		iterator operator++(int);
		iterator& operator--();
		iterator operator--(int);
		bool operator==(const iterator& other) const;
		bool operator!=(const iterator& other) const;
		reference operator[](difference_type  i) const;
		auto operator<=>(const iterator&) const = default;
	};

	iterator begin();
	iterator end();
	iterator rbegin();
	iterator rend();
#endif

public:
	LinkedList();
	~LinkedList();

	T& operator[](int i);
#ifdef LL_ITERATOR_FEATURE
	//default insert after iter
	void Insert(const T& val, const iterator& iter, bool insert_prev = false);
	iterator Erase(const iterator& iter);
#else
	//default insert after node
	void Insert(const T& val, T* node, bool insert_prev = false);
	T* Erase(T* node);
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

	void Print(void);
	void Insert(int i, int pos);
	void Erase(int pos);
	D_LNode<T>* MidFinder(void);
	//... other methods
};

template<class T>
LinkedList<T>::LinkedList()
{
	D_len = 0;     //结点计数符加一
	D_head = new D_LNode<T>;
	D_head->prev = nullptr;
	D_head->data = 0;
	D_head->next = nullptr;
}

template<class T>
LinkedList<T>::~LinkedList()
{
	Clear();
}
//
//template<class T>
//void LinkedList<T>::PushFront(const T& val)
//{
//	
//}
//
//template<class T>
//void LinkedList<T>::PushBack(const T& val)
//{
//
//}
//
//void PopFront();
//void PopBack();

template<class T>
size_t LinkedList<T>::Count()
{
	D_len = 0;                      //初始化结点计数符len
	D_LNode<T>* pt = D_head;
	if (D_head->next == nullptr)
		return 0;
	else
	{
		while (pt->next != nullptr)
		{
			pt = pt->next;
			D_len++;                     //计算链表结点个数
		}
	}
	return D_len;
}

template<class T>
bool LinkedList<T>::Empty()
{
	if (Count() == 0)
	{
		cout << "LinkedList is empty" << endl;
		return 0;
	}
	else
	{
		cout << "LinkedList isn't empty" << endl;
		return 1;
	}
}

template<class T>
void LinkedList<T>::Clear()
{
	if (D_head == nullptr)
	{
		cout << "Please create a LinkedList at first" << endl;
		return;
	}
	else if (D_head->next == nullptr)
	{
		cout << "This LinkedList is already Cleared" << endl;
		return;
	}
	D_LNode<T>* pt1 = D_head->next;   //前指针
	D_head->next = nullptr;
	D_LNode<T>* pt2 = pt1;   //后指针
	while (pt1 != nullptr)
	{
		pt1 = pt1->next;
		delete(pt2);       //删除前一个结点
		pt2 = pt1;
	}
	cout << "Clear successfully" << endl;
}

template<class T>
void LinkedList<T>::Insert(int i, int pos)   //pos为要插入结点的序号
{
	if (pos <= 0)                       //输入不合理
	{
		cout << "Please input a number more  than zero" << endl;
		return;
	}
	else if (pos > D_len + 1)
	{
		cout << "input too big" << endl;
		return;
	}
	else if (pos == 1)         //前插
	{
		D_LNode<T>* pt = new D_LNode<T>(i);  //新建一个结点
		pt->next = D_head->next;
		D_head->next = pt;
		pt->prev = D_head;
		if (pt->next != nullptr)
			pt->next->prev = pt;
	}
	else
	{
		D_LNode<T>* pt = D_head;
		while (pos > 1)
		{
			pt = pt->next;   //找到前一个结点
			pos--;
		}
		D_LNode<T>* newNode = new D_LNode<T>(i);     //创建新结点
		newNode->next = pt->next;                        //插入新结点
		pt->next = newNode;
		newNode->prev = pt;
		if (newNode->next != nullptr)
			newNode->next->prev = newNode;
	}
	D_len++;      //链表长度计数符加1一
}

template<class T>
void LinkedList<T>::Erase(int pos) //pos为要删除结点的序号
{
	if (pos <= 0)
	{
		cout << "Please input a number which is bigger than zero~" << endl;
		return;
	}
	else if (pos > D_len)
		cout << "number input too long!" << endl;
	else
	{
		D_LNode<T>* pt1 = D_head;   //找到删除结点
		D_LNode<T>* pt2 = pt1;   //用于找到要删除结点的前一个结点
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
		D_len--;       //链表长度计数符减一
		cout << "delete successfully" << endl;
	}
}

template<class T>
void LinkedList<T>::PushFront(const T& val)   //头插，并给D_data赋值val
{
	Insert(val, 1);
}

template<class T>
void LinkedList<T>::PushBack(const T& val)     //尾插，并给D_data赋值val
{
	Insert(val, (int)Count() + 1);
}

template<class T>
void LinkedList<T>::PopFront()      //删除第一个结点
{
	Erase(1);
}

template<class T>
void LinkedList<T>::PopBack()      //删除最后一个结点
{
	Erase(Count());
}

template<class T>
void LinkedList<T>::Print(void)
{
	if (D_head == nullptr)
	{
		cout << "Creat a LinkedList at first!" << endl;
		return;
	}
	else
	{
		D_LNode<T>* pt = D_head;
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
D_LNode<T>* LinkedList<T>::MidFinder(void)
{
	if (Empty() == 0)
	{
		return nullptr;
	}
	D_LNode<T>* pt1 = D_head;     //快指针
	D_LNode<T>* pt2 = pt1;      //慢指针
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