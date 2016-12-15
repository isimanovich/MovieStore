// ----------------------------------------------- bintree.h --------------------------------------------------------
// Name: Ihar Simanovich
// Course: CSS343 A
// Creation Date: 10/17/2016
// Last Modification: 10/22/2016
// ------------------------------------------------------------------------------------------------------------------
#ifndef BINTREE_H_
#define BINTREE_H_

#include <iostream>
#include "movie.h"

using namespace std;

class BinTree {

public:
												//constructors and destructor
	BinTree();
	~BinTree();

	void printData()const;								//prints all movies in the tree
	bool retrieve(Movie &, Movie* &);		//retrieves requested object from the tree
	bool isEmpty() const;								//checks if tree is empty
	void makeEmpty();									//makes tree empty
	bool insert(Movie*);								//insert data into tree

private:
	struct Node {
		Movie* data;
		Node* left;										// left subtree pointer
		Node* right;									// right subtree pointer
	};
	Node* root = NULL;									// root of the tree

	void printDataHelper(Node*)const;
	bool retrieveHelper(Movie&, Movie* &, Node*&);//retrieve helper function
	void makeEmpty(Node*&);								//makeEmpty helper function
	bool insert(Movie*, Node*&);						//insert helper function
};

#endif /* BINTREE_H_ */
