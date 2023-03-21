#include "LinkedList.h"
#include "ForwardLinkedList.h"
#include <iostream>

using namespace std;

//刘曦烨-3122004746

int main()
{
	cout << "Now test ForwardLinkedList" << endl;
	ForwardLinkedList<int> e;
	e.Print();           //打印链表中的data,(跳过头结点)
	e.PushFront(3);      //分别前插3，2，1
	e.PushFront(2);
	e.PushFront(1);
	e.PushBack(6);      //分别尾插6，7，8
	e.PushBack(7);
	e.PushBack(8);
	e.Insert(4, 4);     //中间再插入两个结点，插在第4，5结点
	e.Insert(5, 5);
	e.Print();          //打印链表内容
	e.Erase(3);
	e.Erase(1);
	e.Erase((int)e.Count());
	e.Print();
	cout << e.MidFinder()->data << endl;     //找到中间结点(其中调用empty函数检查链表是否为空),并打印data
	e.Clear();
	cout << "ForwardLinkedList test over" << endl;

	cout << endl;

	cout << "Now test LinkedList" << endl;
	LinkedList<int> d;
	d.Print();           //打印链表中的data
	d.PushFront(3);      //分别前插3，2，1
	d.PushFront(2);
	d.PushFront(1);
	d.PushBack(6);      //分别尾插6，7，8
	d.PushBack(7);
	d.PushBack(8);
	d.Insert(4, 4);     //中间再插入两个结点，插在第4，5结点
	d.Insert(5, 5);
	cout << endl;
	d.Print();          //打印链表内容
	cout << d.MidFinder()->data << endl;     //找到中间结点(其中调用empty函数检查链表是否为空),并打印data
	d.Clear();
	cout << "LinkedList test over" << endl;


}
