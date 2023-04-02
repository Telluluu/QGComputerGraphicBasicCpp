#include "LinkedList.h"
#include "ForwardLinkedList.h"
#include <iostream>

using namespace std;

//������-3122004746

int main()
{
	cout << "Now test ForwardLinkedList" << endl;
	ForwardLinkedList<int> e;
	e.Print();           //��ӡ�����е�data,(����ͷ���)
	e.PushFront(3);      //�ֱ�ǰ��3��2��1
	e.PushFront(2);
	e.PushFront(1);
	e.PushBack(6);      //�ֱ�β��6��7��8
	e.PushBack(7);
	e.PushBack(8);
	e.Insert(4, 4);     //�м��ٲ���������㣬���ڵ�4��5���
	e.Insert(5, 5);
	e.Print();          //��ӡ��������
	e.Erase(3);         //ɾ�����������
	e.PopFront();      //ɾ����һ�����
	e.PopBack();         //ɾ�����һ�����
	e.Print();
	cout << e.MidFinder()->data << endl;     //�ҵ��м���(���е���empty������������Ƿ�Ϊ��),����ӡdata
	e.Clear();
	cout << "ForwardLinkedList test over" << endl;

	cout << endl;

	cout << "Now test LinkedList" << endl;
	LinkedList<int> d;
	d.Print();           //��ӡ�����е�data
	d.PushFront(3);      //�ֱ�ǰ��3��2��1
	d.PushFront(2);
	d.PushFront(1);
	d.PushBack(6);      //�ֱ�β��6��7��8
	d.PushBack(7);
	d.PushBack(8);
	d.Insert(4, 4);     //�м��ٲ���������㣬���ڵ�4��5���
	d.Insert(5, 5);
	d.Erase(2);
	d.PopFront();       //ɾ����һ�����
	d.PopBack();        //ɾ�����һ�����
	cout << endl;
	d.Print();          //��ӡ��������
	cout << d.MidFinder()->data << endl;     //�ҵ��м���(���е���empty������������Ƿ�Ϊ��),����ӡdata
	d.Clear();
	cout << "LinkedList test over" << endl;


}