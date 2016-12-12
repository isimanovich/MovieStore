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
#include "NodeData.h"
#include "comedy.h"

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
	bool retrieve(const NodeData &, NodeData* &);		//retrieves requested object from the tree
	BinTree& operator=(const BinTree& );				//assignment operator
	bool operator==(const BinTree&) const;				//comparison operators
	bool operator!=(const BinTree&) const;
	int getHeight (const NodeData &) const;				//returns height of requested node
	void bstreeToArray(NodeData* []);					//moves data from tree to array
	void arrayToBSTree(NodeData* []);					//moves data from array to tree
	bool isEmpty() const;								//checks if tree is empty
	void makeEmpty();									//makes tree empty
	bool insert(NodeData*);								//insert data into tree
	void displaySideways() const;						//displays tree sideways

private:
	struct Node {
		NodeData* data;									// pointer to data object
		Movie* Data;
		Node* left;										// left subtree pointer
		Node* right;									// right subtree pointer
	};
	Node* root = NULL;									// root of the tree

	void inOrder(ostream&, Node*)const;					//output operator helper function
	bool retrieveHelper(const NodeData&, NodeData* &, Node*&);//retrieve helper function
	void traverseToCopy(const Node*);					//operator = helper function
	bool comparison(Node*, Node*) const;				//operator == helper function
	bool findNode(const NodeData&, Node*, Node* &)const;//getHeight helper function
	int heightHelper(int, Node* &)const;				//getHeight helper function
	void toArray(NodeData* [], Node*&, int*&);			//bstreeToArray helper function
	void toTree(NodeData* [], int, int);				//arrayToBSTree helper function
	void makeEmpty(Node*&);								//makeEmpty helper function
	bool insert(NodeData*, Node*&);						//insert helper function
	void sideways(Node*, int) const;					//displaySideways helper function
};

#endif /* BINTREE_H_ */
