#pragma once
#ifndef _BST_H
#define _BST_H

#include<iostream>

template<class T>
class Node
{
public:
	Node();
	Node(T value);
public:
	T value;
	Node<T>* left;
	Node<T>* right;
};

template<class T>
Node<T>::Node()
	:left(nullptr), right(nullptr)
{}

template<class T>
Node<T>::Node(T val)
	:left(nullptr),right(nullptr)
{
	this->value = val;
}



template<class T>
class BinarySortTree
{
public:
	Node<T>* root;

public:
	BinarySortTree<T>();

	int BST_init(BinarySortTree* & bst);

	int BST_insert(BinarySortTree* & bst, const T& val);

	int BST_delete(BinarySortTree* & bst, const T& val);

	int BST_search(BinarySortTree* & bst, const T& val);

	int BST_preorderI(BinarySortTree* & bst, void (*visit)(Node<T>&));

	int BST_preorderR(BinarySortTree* & bst, void (*visit)(Node<T>&));

	int BST_inorderI(BinarySortTree* & bst, void (*visit)(Node<T>&));

	int BST_inorderR(BinarySortTree* & bst, void (*visit)(Node<T>&));

	int BST_postorderI(BinarySortTree* & bst, void (*visit)(Node<T>&));

	int BST_postorderR(BinarySortTree* & bst, void (*visit)(Node<T>&));

	int BST_levelOrder(BinarySortTree* & bst, void (*visit)(Node<T>&));

	Node<T>* findMin(Node<T>* bNode)const;
};

/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
template<class T>
int BinarySortTree<T>::BST_init(BinarySortTree* & bst)
{
	bst->root = new Node<T>;
	return 1;
}

/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
template<class T>
int BinarySortTree<T>::BST_insert(BinarySortTree* & bst,const T& val)
{
	using namespace std;

	Node<T>* ptr = bst->root;
	if (ptr == nullptr)
	{
		cout << "need to be initialized" << endl;
		return 0;
	}
	while (ptr->left != nullptr || ptr->right != nullptr)
	{
		if (val == ptr->value)
		{
			cout << "this data has already existed" << endl;
			return 1;
		}
		else if (val < ptr->value)
		{
			if (ptr->left != nullptr)
			{
					ptr = ptr->left;
			}
			else
			{
				Node<T>* newNode = new Node<T>(val);
				ptr->left = newNode;
				ptr = ptr->left;
			}
		}
		else if (val > ptr->value)
		{
			if (ptr->right != nullptr)
			{
					ptr = ptr->right;
			}
			else
			{
				Node<T>* newNode = new Node<T>(val);
				ptr->right = newNode;
				ptr = ptr->right;
			}
		}
	}
	return 1;
}

template<class T>
Node<T>* BinarySortTree<T>::findMin(Node<T>* bNode) const {
	if (bNode != nullptr) {
		while (bNode->left !=nullptr) {
			bNode = bNode->left;
		}
	}

	return bNode;
}

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
template<class T>
int BinarySortTree<T>::BST_delete(BinarySortTree* &bst, const T& val)
{
	using namespace std;
	int exist = 0;
	Node<T>* ptr = bst->root;
	Node<T>* temp = ptr;
	if (ptr == nullptr)
	{
		cout << "need to be initialized" << endl;
		return 0;
	}
	else
	{
		while (ptr -> left != nullptr || ptr->right != nullptr)
		{
			if (val == ptr->value)
			{
				exist = 1;
				break;
			}
			else if (val < ptr->value)
			{
				if (val == ptr->left->value)
					temp = ptr;
				ptr = ptr->left;
			}
			else if (val > ptr->value)
			{
				if (val == ptr->right->value)
					temp = ptr;
				ptr = ptr->right;
			}
		}
		if (exist == 0)
		{
			cout << "the element doesn't exist" << endl;
			return 0;
		}
		else
		{
			if (temp->left == ptr)
			{
				if (ptr->left == nullptr && ptr->right == nullptr)
				{
					delete ptr;
					temp->left = nullptr;
				}
				else if (ptr->left != nullptr && ptr->right == nullptr)
				{
					temp->left = ptr->left;
					delete ptr;
				}
				else if (ptr->right != nullptr && ptr->left == nullptr)
				{
					temp->left = ptr->right;
					delete ptr;
				}
				else if (ptr->left != nullptr && ptr->right != nullptr)
				{
					Node<T>* oldNode = findMin(ptr);
					int temp_val = oldNode->value;
					BST_delete(bst, temp_val);
					ptr->value = temp_val;
				}
			}
			else if (ptr->right == ptr)
			{
				if (ptr->left == nullptr && ptr->right == nullptr)
				{
					delete ptr;
					temp->right = nullptr;
				}
				else if (ptr->left != nullptr && ptr->right == nullptr)
				{
					temp->right = ptr->left;
					delete ptr;
				}
				else if (ptr->right != nullptr && ptr->left == nullptr)
				{
					temp->right = ptr->right;
					delete ptr;
				}
				else if (ptr->left != nullptr && ptr->right != nullptr)
				{
					Node<T>* oldNode = findMin(ptr);
					int temp_val = oldNode->value;
					BST_delete(bst, temp_val);
					ptr->value = temp_val;
				}
			}
		}
	}
	return 1;
}

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
template<class T>
int BinarySortTree<T>::BST_search(BinarySortTree* &bst,const T& val);

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
template<class T>
int BinarySortTree<T>::BST_preorderI(BinarySortTree* &bst, void (*visit)(Node<T>&));

/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
template<class T>
int BinarySortTree<T>::BST_preorderR(BinarySortTree* &bst, void (*visit)(Node<T>&));

/**
 * BST inorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
template<class T>
int BinarySortTree<T>::BST_inorderI(BinarySortTree* &bst, void (*visit)(Node<T>&));

/**
 * BST inorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
template<class T>
int BinarySortTree<T>::BST_inorderR(BinarySortTree* &bst, void (*visit)(Node<T>&));

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
template<class T>
int BinarySortTree<T>::BST_postorderI(BinarySortTree* &bst, void (*visit)(Node<T>&));

/**
 * BST postorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
template<class T>
int BinarySortTree<T>::BST_postorderR(BinarySortTree* &bst, void (*visit)(Node<T>&));

/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
template<class T>
int BinarySortTree<T>::BST_levelOrder(BinarySortTree* &bst , void (*visit)(Node<T>&));
#endif // !_BST_H
