#pragma once
#ifndef _BST_H
#define _BST_H

#include<iostream>
#include<stack>
#include<queue>

template<class T>
class Node
{
public:
	Node();
	Node(T value);
	T print()const;
	T print(Node<T>* bNode)const;
	void print_child()const;
	void print_child(Node<T>* bNode)const;

public:
	//a mark used for postorder traversal without recursion
	int is_visited;


public:
	T value;
	Node<T>* left;
	Node<T>* right;
};

template<class T>
inline Node<T>::Node()
	:left(nullptr), right(nullptr),is_visited(0)
{}

template<class T>
inline Node<T>::Node(T val)
	:left(nullptr),right(nullptr),is_visited(0)
{
	this->value = val;
}

template<class T>
inline T Node<T>::print()const
{
	if (this != nullptr)
	{
		std::cout << this->value << " ";
		return this->value;
	}
	return 0;
}

template<class T>
inline T Node<T>::print(Node<T>* bNode)const
{
	if (bNode != nullptr)
	{
		std::cout << bNode->value << " ";
		return bNode->value;
	}
	return 0;
}

template<class T>
inline void Node<T>::print_child()const
{
	if (this != nullptr)
	{
		if (this->left != nullptr)
			print(this->left);
		if (this->right != nullptr)
			print(this->right);
	}
}

template<class T>
inline void Node<T>::print_child(Node<T>* bNode)const
{
	using namespace std;
	if (bNode != nullptr)
	{
		if (bNode->left != nullptr)
			print(bNode->left);
		if (bNode->right != nullptr)
			print(bNode->right);
	}
}

template<class T>
class BinarySortTree
{
public:
	Node<T>* root=nullptr;

private:
	int is_root = 0;

public:
	BinarySortTree<T>() {}

	~BinarySortTree<T>() { BST_destroy(root); }

	int BST_init();

	int BST_insert(const T& val);

	int BST_delete(const T& val);

	int BST_search(const T& val)const;

	int BST_preorderI()const;

	int BST_preorderR(Node<T>*& bNode)const;

	int BST_inorderI()const;

	int BST_inorderR(Node<T>*& bNode)const;

	int BST_postorderI()const;

	int BST_postorderR(Node<T>*& bNode)const;

	int BST_levelOrder()const;

	int BST_destroy(Node<T>*& ptr);

	Node<T>* findMin(Node<T>* bNode=nullptr)const;
};

/**
 * BST initialize
 * @param void
 * @return is complete
 */
template<class T>
inline int BinarySortTree<T>::BST_init()
{
	BST_destroy(root);
	root = new Node<T>;
	is_root = 1;
	return 1;
}

/**
 * BST destroy
 * @param void
 * @return is complete
 */
template<class T>
inline int BinarySortTree<T>::BST_destroy(Node<T>*& ptr)
{
	if (ptr == nullptr)
	{
		return 1;
	}
	BST_destroy(ptr->left);
	BST_destroy(ptr->right);
	ptr->left = nullptr;
	ptr->right = nullptr;
	root = nullptr;
	delete ptr;
}
/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
template<class T>
inline int BinarySortTree<T>::BST_insert(const T& val)
{
	using namespace std;
	Node<T>* ptr = root;
	if (this->is_root == 1)
	{
		root->value = val;
		is_root = 0;
		return 1;
	}
	if (ptr == nullptr)
	{
		cout << "need to be initialized" << endl;
		return 0;
	}
	while (1)
	{
		if (val == ptr->value)
		{
			cout <<"\""<<val<<"\"" << "has already existed" << endl;
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
				return 1;
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
				return 1;
			}
		}
	}
	return 1;
}

template<class T>
inline Node<T>* BinarySortTree<T>::findMin(Node<T>* bNode) const
{
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
inline int BinarySortTree<T>::BST_delete(const T& val)
{
	int exist = 0;
	Node<T>* ptr = root;
	Node<T>* temp = ptr;
	if (ptr == nullptr)
	{
		std::cout << "need to be initialized" << std::endl;
		return 0;
	}
	else
	{
		while (ptr != nullptr)
		{
			if (val == ptr->value)
			{
				exist = 1;
				break;
			}
			else if (val < ptr->value)
			{
				if (ptr->left != nullptr)
					if (val == ptr->left->value)
						temp = ptr;
				ptr = ptr->left;
			}
			else if (val > ptr->value)
			{
				if(ptr->right!=nullptr)
					if (val == ptr->right->value)
						temp = ptr;
				ptr = ptr->right;
			}
		}
		if (exist == 0)
		{
			std::cout << "the element doesn't exist" << std::endl;
			return 0;
		}
		else
		{
			if (ptr == root)
			{
				std::cout << "the root can't be deleted" << std::endl;
				return 0;
			}
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
					BST_delete(temp_val);
					ptr->value = temp_val;
				}
			}
			else if (temp->right == ptr)
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
					BST_delete(temp_val);
					ptr->value = temp_val;
				}
			}
		}
	}
	std::cout<<"Delete Successfully" << std::endl;
	return 1;
}

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
template<class T>
inline int BinarySortTree<T>::BST_search(const T& val)const
{
	Node<T>* ptr = root;
	if (root == nullptr)
	{
		std::cout << "the tree is empty" << std::endl;
	}
	else
	{
		while(ptr!=nullptr)
		{
			if (ptr->value == val)
			{
				std::cout << "\"" << val << "\" exists" << std::endl;
				return 1;
			}
			if ((val < ptr->value) && (ptr->left != nullptr))
			{
				ptr = ptr->left;
			}
			else if ((val > ptr->value) && (ptr->right != nullptr))
			{
				ptr = ptr->right;
			}
			else
			{
				std::cout << "\"" << val << "\" doesn't exist" << std::endl;
				return 0;
			}
		}
	}
}

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
template<class T>
inline int BinarySortTree<T>::BST_preorderI()const
{
	if (root == nullptr)
	{
		std::cout << "BinarySortTree is empty" << std::endl;
		return 0;
	}

	std::stack<Node<T>*> q;
	Node<T>* ptr = root;

	while (ptr != nullptr || q.empty() == false)
	{
		if (ptr != nullptr)
		{
			ptr->print();
			q.push(ptr);
			ptr = ptr->left;
		}
		else
		{
			ptr = q.top();
			q.pop();
			ptr = ptr->right;
		}
	}
	std::cout << std::endl;
	return 1;
}

/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param Node<T>*& bNode
 * @return is successful
 */
template<class T>
inline int BinarySortTree<T>::BST_preorderR(Node<T>*& bNode)const
{
	if (root == nullptr)
	{
		std::cout << "BinarySortTree is empty" << std::endl;
		return 0;
	}

	if (bNode != nullptr)
	{
		bNode->print();
		BST_preorderR(bNode->left);
		BST_preorderR(bNode->right);
	}
	return 1;
}

/**
 * BST inorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
template<class T>
inline int BinarySortTree<T>::BST_inorderI()const
{
	if (root == nullptr)
	{
		std::cout << "BinarySortTree is empty" << std::endl;
		return 0;
	}

	std::stack<Node<T>*> q;
	Node<T>* ptr = root;

	while (ptr != nullptr || q.empty() == false)
	{
		if (ptr != nullptr)
		{
			q.push(ptr);
			ptr = ptr->left;
		}
		else
		{
			ptr = q.top();
			q.pop();
			ptr->print();
			ptr = ptr->right;
		}
	}
	std::cout << std::endl;
	return 1;
}

/**
 * BST inorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param Node<T>*& bNode
 * @return is successful
 */
template<class T>
inline int BinarySortTree<T>::BST_inorderR(Node<T>*& bNode)const
{
	if (root == nullptr)
	{
		std::cout << "BinarySortTree is empty" << std::endl;
		return 0;
	}

	if (bNode != nullptr)
	{
		BST_inorderR(bNode->left);
		bNode->print();
		BST_inorderR(bNode->right);
	}
	return 1;
}

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
template<class T>
inline int BinarySortTree<T>::BST_postorderI()const
{
	if (root == nullptr)
	{
		std::cout << "BinarySortTree is empty" << std::endl;
		return 0;
	}

	std::stack<Node<T>*> s;
	Node<T>* ptr = root;
	Node<T>* q;
	Node<T>* t;

	while (ptr || s.empty() == false)
	{
		while (ptr != nullptr)
		{
			s.push(ptr);
			ptr->is_visited = 0;
			ptr = ptr->left;
		}
		if (s.empty() == false)
		{
			t = s.top();
			q = s.top();
			s.pop();
			if (t->is_visited == 0)
			{
				s.push(q);
				t->is_visited = 1;
				ptr = q->right;
			}
			else
			{
				t->print();
				ptr = nullptr;
			}
		}

	}
	std::cout << std::endl;
	return 1;
}

/**
 * BST postorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param Node<T>*& bNode
 * @return is successful
 */
template<class T>
inline int BinarySortTree<T>::BST_postorderR(Node<T>*& bNode)const
{
	if (root == nullptr)
	{
		std::cout << "BinarySortTree is empty" << std::endl;
		return 0;
	}

	if (bNode != nullptr)
	{
		BST_postorderR(bNode->left);
		BST_postorderR(bNode->right);
		bNode->print();
	}
	return 1;
}

/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
template<class T>
inline int BinarySortTree<T>::BST_levelOrder()const
{
	if (root == nullptr)
	{
		std::cout << "BinarySortTree is empty" << std::endl;
		return 0;
	}

	std::queue<Node<T>*> q;

	if (root != nullptr)
		q.push(root);

	while (q.empty() == false)
	{
		q.front()->print();
		if (q.front()->left != nullptr)
			q.push(q.front()->left);
		if (q.front()->right != nullptr)
			q.push(q.front()->right);
		q.pop();
	}
	std::cout << std::endl;
	return 1;
}
#endif // !_BST_H
