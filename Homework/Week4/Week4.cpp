#include<iostream>
#include"BST.h"

int main()
{
	using namespace std;
	BinarySortTree<int> bst;
	bst.BST_init();
	cout << "initialize suscessfully" << endl;

	bst.BST_insert(5);
	bst.BST_insert(3);
	bst.BST_insert(4);
	bst.BST_insert(6);
	bst.BST_insert(8);
	bst.BST_insert(7);
	bst.BST_insert(2);
	bst.BST_insert(9);

	//bst.BST_insert(5);
	//bst.BST_insert(3);
	//bst.BST_insert(7);
	//bst.BST_insert(2);
	//bst.BST_insert(4);
	//bst.BST_insert(6);
	//bst.BST_insert(8);
	//bst.BST_insert(9);
	cout << "insert suscessfully" << endl;

	bst.BST_preorderR(bst.root);
	cout << endl;

	if (bst.BST_search(0))
		cout << "0 exists" << endl;
	else cout << "0 doesn't exist" << endl;
	if (bst.BST_search(7) && bst.BST_search(6))
		cout << "6 and 7 exist" << endl;
	else cout << "6 and 7 doesn't exist" << endl;

}