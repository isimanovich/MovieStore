// ----------------------------------------------- bintree.cpp ------------------------------------------------------
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

#include "bintree.h"		//including BinTree class header file

// ----------------------------------------------- constructor ------------------------------------------------------
// Description: Creates empty BinTree with its root pointing to NULL
// ------------------------------------------------------------------------------------------------------------------
BinTree::BinTree() {
	root = NULL;
}

// --------------------------------------------- copy constructor ---------------------------------------------------
// Description: Creates deep copy of passed in object by calling assignment operator
// Parameter is another BinTree object that must not be modified
// ------------------------------------------------------------------------------------------------------------------
BinTree::BinTree(const BinTree& original) {
	*this = original;
}

// ------------------------------------------------ destructor ------------------------------------------------------
BinTree::~BinTree() {
	//make empty, if object is not empty
	if (!isEmpty())
		makeEmpty();
}

// -------------------------------------------- output operator -----------------------------------------------------
// Description: Output operator outputs BinTree data using inorder traversal
// Parameters are ostream and BinTree(must not be modified) objects
// Friend function
//
// Note:
// - Movie class is responsible for displaying its own data
// ------------------------------------------------------------------------------------------------------------------
ostream &operator<<(ostream& out, const BinTree& tree) {
	//calling private helper function to traverse the tree recursively
	tree.inOrder(out, tree.root);
//	out << endl;		//add end of line to the output
	return out;			//return ostream object
}

// ------------------------------------------ inOrder helper function -----------------------------------------------
// Description: Recursively traverses the BinTree object and adds data to ostream object
// Parameters are ostream and Node pointer objects
// Private function
// ------------------------------------------------------------------------------------------------------------------
void BinTree::inOrder(ostream& out, Node* curr) const {
	//if pointer is not pointing at NULL, execute following
	if (curr != NULL) {
		inOrder(out, curr->left);		//recursive call to traverse to the left
		out << curr->data->getTitle() << endl;		//add data to the ostream
		inOrder(out, curr->right);	//recursive call to traverse to the right
	}
}

// -------------------------------------------------- retrieve ------------------------------------------------------
// Description: function to get the Movie* of a given object in the tree (via pass-by-reference
// parameter) and to report whether the object is found (tree or false).
// Parameters are Movie and Movie pointer objects target and result
// Returning boolean to show whether retrieval was successful
// Note: The 2nd parameter in the function signature may initially be garbage. Then if the object is found, it
// will point to the actual object in the tree.
// ------------------------------------------------------------------------------------------------------------------
bool BinTree::retrieve(Movie & target, Movie* &result) {
	return retrieveHelper(target, result, root);
}

// ------------------------------------------ retrieveHelper function -----------------------------------------------
// Description: Recursively traverses the BinTree object in order to find target Movie object
// Parameters are Movie, Movie pointer and Node pointer objects
// Private function
// ------------------------------------------------------------------------------------------------------------------
bool BinTree::retrieveHelper(Movie& target, Movie* &result, Node* &curr) {
	//if found object - put it in target and return true
	if (target == *curr->data) {
		result = curr->data;
		return true;
	} else if (target < *curr->data && curr->left != NULL)//left recursive call
		return retrieveHelper(target, result, curr->left);
	else	//right recursive call
		return retrieveHelper(target, result, curr->right);
	return false;	//if object not found
}

// ------------------------------------------------ = operator ------------------------------------------------------
// Description: Operator that assigns one BinTree object to another
// Parameter is BinTree object(must not modify)
// ------------------------------------------------------------------------------------------------------------------
BinTree& BinTree::operator =(const BinTree& rhs) {
	//if rhs and lhs same object, return lhs
	if (this->root == rhs.root) {
		return *this;
	}
	//if lhs is not empty, make it to be empty
	if (!isEmpty()) {
		makeEmpty();
		root = NULL;
	}
	//if rhs is not empty, copy data from it
	if (rhs.root != NULL) {
		//calling helper function to traverse rhs tree
		traverseToCopy(rhs.root);
	}
	return *this;	//returning result
}

// ------------------------------------- traverseToCopy helper function ---------------------------------------------
// Description: Recursively traverses the BinTree object and inserts rhs' data into lhs tree
// Parameter Node pointer
// Private function
// ------------------------------------------------------------------------------------------------------------------
void BinTree::traverseToCopy(const Node* rhs) {
	//if pointer is not pointing at NULL, execute following
	if (rhs != NULL) {
		Movie* ndata = new Movie(*rhs->data);//creating new Movie object with value from rhs tree
		insert(ndata);					//inserting Movie object in lhs tree
		traverseToCopy(rhs->left);					//traverse to left
		traverseToCopy(rhs->right);					//traverse to right
	}
}

// -------------------------------------------------- isEmpty ------------------------------------------------------
// Description: function that checks whether tree is empty or not
// Returns boolean
// ------------------------------------------------------------------------------------------------------------------
bool BinTree::isEmpty() const {
	return root == NULL;
}

// -------------------------------------------------- makeEmpty -----------------------------------------------------
// Description: Function to make BinTree empty
// ------------------------------------------------------------------------------------------------------------------
void BinTree::makeEmpty() {
	//if tree empty, exit function
	if (isEmpty())
		return;
	//calling helper function
	makeEmpty(root);
}

// --------------------------------------------- toTree function ----------------------------------------------------
// Description: Recursively traverses the BinTree and deletes nodes
// Parameters are pointer to the tree
// Private function
// ------------------------------------------------------------------------------------------------------------------
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

// ------------------------------------------------ arrayToBSTree ---------------------------------------------------
// Description: Function that inserts given object into the tree
// Parameter is pointer to Movie object
// Returns boolean whether insert was successful
// Note: matching data is being discarded
// ------------------------------------------------------------------------------------------------------------------
bool BinTree::insert(Movie* data) {
	return insert(data, root);	//calling helper function
}

// --------------------------------------------- insert function ----------------------------------------------------
// Description: Recursively traverses the BinTree in order to insert data
// Parameters are pointer to the tree
// Private function
// ------------------------------------------------------------------------------------------------------------------
bool BinTree::insert(Movie* data, Node* &curr) {

	/*

	 POSSIBLE MEMORY LEAK!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


	 */
//	if(data == curr->data){
//		curr->data->increaseStock(data->getAmountIn());
////		data->~Movie();
//		return true;
//	}
	//if root == NULL, so insert and set result to true
	if (curr == NULL) {
		curr = new Node();
		curr->data = data;
		curr->left = NULL;
		curr->right = NULL;
		return true;
	} else if (data < curr->data) {		//go to left recursively
		return insert(data, curr->left);
	} else if (data > curr->data) {		//go to right recursively
		return insert(data, curr->right);
	}
	return false;	//if can't insert data because matching data in the tree
}
