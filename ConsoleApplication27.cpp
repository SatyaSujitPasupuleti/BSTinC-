// ConsoleApplication27.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class chunk {
public:
	int value;
	chunk *left;
	chunk *right;

	//give our building blocks a default look and feel
	chunk() {
		value = 0;
		left = NULL;
		right = NULL;
	}
};
class BST{

//insert, delete (case1,2,3) in order , pre-order , post order

	chunk *root;
	BST()
	{
		root = NULL;

	}
	void insert(chunk *tree, chunk *node)
	{
		if (root = NULL)
		{
			root = new chunk;
			root->value = node->value;
			root->left = NULL;
			root->right = NULL;
			return;
		}
		if (tree->value == node->value)
		{
			return; //element already in tree
		}
		if (tree->value > node->value)
		{
			if (tree->left != NULL)
				insert(tree->left, node);
			else
			{
				tree->left = node;
				(tree->left)->left = NULL;
				(tree->left)->right = NULL;
				return;
			}
		}


		else
		{
			if (tree->right != NULL)
			{
				insert(tree->right, node);
			}
			else
			{
				tree->right = node;
				(tree->right)->left = NULL;
				tree->right->right = NULL;
				return;
			}

		}
	}
	void preorder(chunk *ptr)
	{
		if (root==NULL)
		{
			return;
		}
		if (ptr!=NULL)
		{
			preorder(ptr->left);
			preorder(ptr->right);
			cout << ptr->value << " ";
		}
	}
	void inorder(chunk *ptr)
	{
		if (root = NULL)
		{
			return;
		}
		if (ptr != NULL)
		{
			inorder(ptr->left);
			inorder(ptr -> left);
			cout << ptr->value << " ";
		}
	}
	void postorder(chunk *ptr)
	{
		if (root == NULL)
		{
			cout << "Tree empty" << endl;
			return;
		}
		if (ptr != NULL)
		{
			postorder(ptr->left);
			postorder(ptr -> right);
			cout << ptr->value << " ";
		}
	}
	void search(int value, chunk **par, chunk **loc)
	{
		chunk *ptr, *ptrsave; 
		if (root == NULL)
		{
			*loc = NULL;
			*par = NULL;
			return;
		}
		if (value == root->value)
		{
			*loc = root;
			*par = NULL;
			return;
		}
		if (value < root->value)
			ptr = root->left;
		else
			ptr = root->right;
		ptrsave = root;
		while (ptr != NULL)
		{
			if (value = ptr->value)
			{
				*loc = ptr;
				*par = ptrsave;
				return;
			}
			ptrsave = ptr;
			if (value < ptr->value)
			{
				ptr = ptr->left;
			}
			else
				ptr = ptr->right;
		}
		*loc = NULL;
		*par = ptrsave;

	}
	void delNodeBST(int value, chunk *start)
	{
		chunk *location; 
		if (root == NULL)
		{
			return;
		}
		search(value, &start, &location);
		if (location == NULL)
		{
			return;
		}
		if (location->left == NULL && location->right == NULL)
		{
			caseA(start, location);
		}
		if (location->left != NULL&&location->right == NULL)
		{
			caseB(start, location);
		}
		if (location->left == NULL &&location->right != NULL)
		{
			caseB(start, location);
		}
		if (location->left != NULL&& location->right != NULL)
		{
			caseC(start, location);
		}
		free(location);
	}
	void caseA(chunk *val, chunk *loc)
	{
		if (val == NULL)
		{
			root = NULL;
		}
		else
		{
			if (loc == val->left)
			{
				val->left = NULL;
			}
			else
				val->right = NULL;
		}
	}
	void caseB(chunk *val, chunk *loc)
	{
		chunk *child; 
		if (loc->left != NULL)
		{
			child = loc->left;
		}
		else
			child = loc->right;
		if (val == NULL)
		{
			root = child;
		}
		else
		{
			if (loc == val->left)
			{
				val->left = child;
			}
			else
				val->right = child;
		}
	}
	void caseC(chunk *val, chunk *loc)
	{
		chunk *ptr, *ptrnew, *a, *b; 
		ptrnew = loc;
		ptr = loc->right;
		while (ptr->left != NULL)
		{
			ptrnew = ptr;
			ptr = ptr->left;
		}
		a = ptr;
		b = ptrnew;
		if (a->left == NULL&&a->right == NULL)
		{
			caseA(b, a);
		}
		else
			caseB(b, a);
		if (val == NULL)
		{
			root = a;
		}
		else
		{
			if (loc = val->left)
			{
				val->left = a;
			}
			else
			{
				val->right = a;
			}
		}
		a->left = loc->left;
		a->right = loc->right;
	}

};
int main()
{
	int choice, a;
	chunk *newChunk;
	BST b;
	while (true)
	{
		cout << "Binary Search Tree , press keyboard to begin" << endl;
		cout << "1. Insert Element" << endl;
		cout << "2.delete element" << endl;
		cout << "3. Inorder Traversal" << endl;
		cout << "4 PostOrder Traversal" << endl;
		cout << "5 PreOrder Traversal" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			newChunk = new chunk;
			cout << "enter number " << endl;
				cin >> newChunk->value;
				b.insert(root, newChunk);
		case 2: 
			if (root == NULL)
			{
				cout << "tree is empty" << endl;
			}
			cout << "enter number to be deleted" << endl;
				cin >> a;
			b.delNodeBST(a, *root);
			break;
		case 3:
			b.inorder(*root);
			break;
		case 4:
			b.postorder(*root);
			break;
		case 5:
			b.preorder(*root);
			break;
		default:
			exit(1);
			
		}
	}


}
