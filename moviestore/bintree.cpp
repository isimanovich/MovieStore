// ----------------------------------------------- bintree.cpp ------------------------------------------------------
// Name: Ihar Simanovich
// Course: CSS343 A
// Creation Date: 10/17/2016
// Last Modification: 12/14/2016
// ------------------------------------------------------------------------------------------------------------------

#include "bintree.h"		//including BinTree class header file

// ----------------------------------------------- constructor ------------------------------------------------------
BinTree::BinTree() {
	root = NULL;
}

// ------------------------------------------------ destructor ------------------------------------------------------
BinTree::~BinTree() {
	//make empty, if object is not empty
	if (!isEmpty())
		makeEmpty();
}

// ------------------------------------------------ printData ------------------------------------------------------
void BinTree::printData() const {
	//calling private helper function to traverse the tree recursively
	printDataHelper(this->root);
}

// --------------------------------------------- printDataHelper ---------------------------------------------------
void BinTree::printDataHelper(Node* curr) const {
	//if pointer is not pointing at NULL, execute following
	if (curr != NULL) {
		printDataHelper(curr->left);	//recursive call to traverse to the left
		curr->data->display();		//add data to the ostream
		printDataHelper(curr->right);//recursive call to traverse to the right
	}
}

// -------------------------------------------------- retrieve ------------------------------------------------------
bool BinTree::retrieve(Movie & target, Movie* &result) {
	return retrieveHelper(target, result, root);
}

// ------------------------------------------ retrieveHelper function -----------------------------------------------
bool BinTree::retrieveHelper(Movie& target, Movie* &result, Node* &curr) {
	//if found object - put it in target and return true
	if (target == *curr->data) {
		result = curr->data;
		return true;
	} else if (target < *curr->data && curr->left != NULL)//left recursive call
		return retrieveHelper(target, result, curr->left);
	else if (curr->right != NULL)	//right recursive call
		return retrieveHelper(target, result, curr->right);
	return false;	//if object not found
}


// -------------------------------------------------- isEmpty ------------------------------------------------------
bool BinTree::isEmpty() const {
	return root == NULL;
}

// -------------------------------------------------- makeEmpty -----------------------------------------------------
void BinTree::makeEmpty() {
	//if tree empty, exit function
	if (isEmpty())
		return;
	//calling helper function
	makeEmpty(root);
}

// --------------------------------------------- makeEmpty helper ---------------------------------------------------
void BinTree::makeEmpty(Node* &curr) {
	//if pointer is not NULL execute following
	if (curr != NULL) {
		if (curr->left != NULL)		//go left, if left pointer is not NULL
			makeEmpty(curr->left);
		if (curr->right)
			makeEmpty(curr->right);	//go left, if left pointer is not NULL
		delete curr->data;			//delete data node
		delete curr;				//delete node
		curr = NULL;				//set current pointer to NULL
	}
}

// --------------------------------------------------- insert -------------------------------------------------------
bool BinTree::insert(Movie* data) {
	return insert(data, root);	//calling helper function
}

// ----------------------------------------------- insert helper ----------------------------------------------------
bool BinTree::insert(Movie* data, Node* &curr) {

	//if root == NULL, so insert and set result to true
	if (curr == NULL) {
		curr = new Node();
		curr->data = data;
		curr->left = NULL;
		curr->right = NULL;
		return true;
	}
	//if duplicate found, increment stock and destroy duplicate object
	if (*data == *curr->data) {
		curr->data->increaseStock(data->getAmountIn());
		delete data;
		data = NULL;
		return true;
	} else if (*data < *curr->data) {		//go to left recursively
		return insert(data, curr->left);
	} else {		//go to right recursively
		return insert(data, curr->right);
	}
	return false;	//if can't insert data because matching data in the tree
}
