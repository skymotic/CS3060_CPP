/*
 * main.cpp
 *
 *  Created on: Nov 20, 2022
 *      Author: Luke O'Brien
 *
 *  Program Description:
 *  The following program is answering questions 21.1 in the Book
 *  It has a class that is able to create an instance of a binary tree that can
 *  Hold any type by using Templates
 *
 *  The Binary Tree is Simple, as it is just to show a point.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <iomanip>

using namespace std;

// A class to house the structure holding the data types
// with all the functions to edit it
template <typename T>
class BinaryTree
{
private:
	//Where most of the data is held
	struct node
	{
		T data;
		struct node* left;
		struct node* right;
	};

	// Referenced parent nod
	struct node* root;

public:
	void add(T x)
	{
		add(&(this->root), x);
	}
	void add(struct node** x, T y)
	{
		if(*x == NULL)
		{
			struct node* temp = new struct node;
			temp->data = y;
			temp->left = NULL;
			temp->right = NULL;
			*x = temp;
		}
		else
		{
			if(y > (*x)->data) { add(&(*x)->right,y); }
			else { add(&(*x)->left, y); }
		}
	}

	//Prints Binary Tree in Order
	void print() { print(root); }
	void print(struct node* x)
	{
		if(x != NULL)
		{
			print(x->left);
			cout << (x->data) << " ";
			print(x->right);
		}
	}
	BinaryTree() { root = NULL; }
};

//Simple main to test Binary Tree
int main()
{
	BinaryTree<double> myTree;
	srand(time(NULL));

	for(int x=0; x<20; x++){
		myTree.add((double)rand() / 10000.0);
	}
	myTree.add(10.11343);
	myTree.print();
	cout << endl << endl;

	BinaryTree<int> myTreeTwo;
	for(int x=0; x<20; x++){
		myTreeTwo.add(rand()%100);
	}
	myTreeTwo.print();
}
