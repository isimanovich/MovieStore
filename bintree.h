// ----------------------------------------------- bintree.h --------------------------------------------------------
// Name: Ihar Simanovich
// Course: CSS343 A
// Creation Date: 10/17/2016
// Last Modification: 10/22/2016
// ------------------------------------------------------------------------------------------------------------------
// Purpose: is to create a binary search tree class called BinTree.
// ------------------------------------------------------------------------------------------------------------------
// Notes:
// - remove function is not required.
// - duplicate elements are not being inserted in the BinTree.
// ------------------------------------------------------------------------------------------------------------------
#ifndef BINTREE_H_
#define BINTREE_H_

#include <iostream>
#include "movie.h"

using namespace std;

class BinTree {

	//friends functions with access to private fields
	//overload of input/output operators to print complex number by the format
	friend ostream &operator<<(ostream& ouT, const BinTree&);

public:
												//constructors and destructor
	BinTree();
	BinTree(const BinTree&);
	~BinTree();

	void printData()const;								//prints all movies in the tree
	bool retrieve(Movie &, Movie* &);		//retrieves requested object from the tree
	BinTree& operator=(const BinTree& );				//assignment operator
	bool isEmpty() const;								//checks if tree is empty
	void makeEmpty();									//makes tree empty
	bool insert(Movie*);								//insert data into tree
//	void displaySideways() const;						//displays tree sideways

private:
	struct Node {
		Movie* data;
		Node* left;										// left subtree pointer
		Node* right;									// right subtree pointer
	};
	Node* root = NULL;									// root of the tree

	void inOrder(ostream&, Node*)const;					//output operator helper function
	void printDataHelper(Node*)const;

	//first Movie here must be constant, fix it
	bool retrieveHelper(Movie&, Movie* &, Node*&);//retrieve helper function
	void traverseToCopy(const Node*);					//operator = helper function
	void makeEmpty(Node*&);								//makeEmpty helper function
	bool insert(Movie*, Node*&);						//insert helper function
//	void sideways(Node*, int) const;					//displaySideways helper function
};

#endif /* BINTREE_H_ */
