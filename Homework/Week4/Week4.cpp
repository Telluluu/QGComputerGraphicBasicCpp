#include<iostream>
#include"BST.h"

void Menu()
{
	std::cout << "--------------------------------------------------------------------------------------" << std::endl;
	std::cout <<
		"1:Initialize the BinarySortTree " << std::endl <<
		"2:Insert a Data " << std::endl <<
		"3:Delete a Data " << std::endl <<
		"4:Search a Data " << std::endl <<
		"5:Preorder Traversal " << std::endl <<
		"6:Inorder Traversal " << std::endl <<
		"7:Postorder Traversal " << std::endl <<
		"8:Level Order Traversal: " << std::endl<<
		"0:exit" << std::endl;
	std::cout << "--------------------------------------------------------------------------------------" << std::endl;
	std::cout << "please input command:";

}

int main()
{
	BinarySortTree<int> bst;

	int data;
	char command;
	Menu();
	while (1)
	{
		std::cin >> command;
		if (std::cin.good())
			switch (command)
			{
			case '1':
				if (bst.BST_init())
					std::cout << "BinarySortTree Initlized Sucessfully" << std::endl;
				else std::cout << "BinarySortTree Initlization failed" << std::endl;
				std::cout << std::endl << std::endl << std::endl;
				Menu();
				break;

			case '2':
				std::cout << "Please Input the Data You Want to Insert" << std::endl;
				std::cin >> data;
				if (std::cin.good())
				{
					bst.BST_insert(data);
					std::cout << std::endl << std::endl << std::endl;
					Menu();
					break;
				}
				else
				{
					std::cout << "wrong data, please input number" << std::endl;
					std::cin.clear();
					std::cin.ignore(2048, '\n');
					std::cout << "--------------------------------------------------------------------------------------" << std::endl;
					std::cout << std::endl << std::endl << std::endl;
					Menu();
					break;
				}

			case '3':
				std::cout << "Please Input the Data You Want to Delete" << std::endl;
				std::cin >> data;
				if (std::cin.good())
				{
					bst.BST_delete(data);
					std::cout << std::endl << std::endl << std::endl;
					Menu();
					break;
				}
				else
				{
					std::cout << "wrong data, please input number" << std::endl;
					std::cin.clear();
					std::cin.ignore(2048, '\n');
					std::cout << "--------------------------------------------------------------------------------------" << std::endl;
					std::cout << std::endl << std::endl << std::endl;
					Menu();
					break;
				}

			case '4':
				std::cout << "Please Input the Data You Want to Search" << std::endl;
				std::cin >> data;
				if (std::cin.good())
				{
					bst.BST_search(data);
					std::cout << std::endl << std::endl << std::endl;
					Menu();
					break;
				}
				else
				{
					std::cout << "wrong data, please input number" << std::endl;
					std::cin.clear();
					std::cin.ignore(2048, '\n');
					std::cout << "--------------------------------------------------------------------------------------" << std::endl;
					std::cout << std::endl << std::endl << std::endl;
					Menu();
					break;
				}

			case '5':
				std::cout << "Preorder Traversal Without Recursion:" << std::endl;
				bst.BST_preorderI();
				std::cout << "Preorder Traversal With Recursion:" << std::endl;
				bst.BST_preorderR(bst.root);
				std::cout << "--------------------------------------------------------------------------------------" << std::endl;
				std::cout << std::endl << std::endl << std::endl;
				Menu();
				break;

			case '6':
				std::cout << "Inorder Traversal Without Recursion:" << std::endl;
				bst.BST_inorderI();
				std::cout << "Inorder Traversal With Recursion:" << std::endl;
				bst.BST_inorderR(bst.root);
				std::cout << "--------------------------------------------------------------------------------------" << std::endl;
				std::cout << std::endl << std::endl << std::endl;
				Menu();
				break;

			case '7':
				std::cout << "Postorder Traversal Without Recursion:" << std::endl;
				bst.BST_postorderI();
				std::cout << "Postorder Traversal With Recursion:" << std::endl;
				bst.BST_postorderR(bst.root);
				std::cout << "--------------------------------------------------------------------------------------" << std::endl;
				std::cout << std::endl << std::endl << std::endl;
				Menu();
				break;

			case '8':
				std::cout << "Level Order Traversal:" << std::endl;
				bst.BST_levelOrder();
				std::cout << "--------------------------------------------------------------------------------------" << std::endl;
				std::cout << std::endl << std::endl << std::endl;
				Menu();
				break;

			case '0': exit(0);

			default:
				std::cout << "wrong command, please input again" << std::endl;
				std::cin.clear();
				std::cin.ignore(2048, '\n');
				std::cout << "--------------------------------------------------------------------------------------" << std::endl;
				std::cout << std::endl << std::endl << std::endl;
				Menu();
				break;
			}
		else
		{
			std::cout << "wrong command, please input again" << std::endl;
			std::cin.clear();
			std::cin.ignore(2048, '\n');
			std::cout << "--------------------------------------------------------------------------------------" << std::endl;
			std::cout << std::endl << std::endl << std::endl;
			Menu();
		}
	}

	return 0;
}