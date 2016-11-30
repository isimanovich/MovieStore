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
// - NodeData class is responsible for displaying its own data
// ------------------------------------------------------------------------------------------------------------------
ostream &operator<<(ostream& out, const BinTree& tree) {
	//calling private helper function to traverse the tree recursively
	tree.inOrder(out, tree.root);
	out << endl;		//add end of line to the output
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
		out << *curr->data << " ";		//add data to the ostream
		inOrder(out, curr->right);	//recursive call to traverse to the right
	}
}

// -------------------------------------------------- retrieve ------------------------------------------------------
// Description: function to get the NodeData* of a given object in the tree (via pass-by-reference
// parameter) and to report whether the object is found (tree or false).
// Parameters are NodeData and NodeData pointer objects target and result
// Returning boolean to show whether retrieval was successful
// Note: The 2nd parameter in the function signature may initially be garbage. Then if the object is found, it
// will point to the actual object in the tree.
// ------------------------------------------------------------------------------------------------------------------
bool BinTree::retrieve(const NodeData & target, NodeData* &result) {
	return retrieveHelper(target, result, root);
}

// ------------------------------------------ retrieveHelper function -----------------------------------------------
// Description: Recursively traverses the BinTree object in order to find target NodeData object
// Parameters are NodeData, NodeData pointer and Node pointer objects
// Private function
// ------------------------------------------------------------------------------------------------------------------
bool BinTree::retrieveHelper(const NodeData& target, NodeData* &result,
		Node* &curr) {
	//if found object - put it in target and return true
	if (target == *curr->data) {
		result = curr->data;
		return true;
	} else if (target < *curr->data && curr->left != NULL) {//left recursive call
		return retrieveHelper(target, result, curr->left);
	} else if (target > *curr->data && curr->right != NULL) {//right recursive call
		return retrieveHelper(target, result, curr->right);
	}
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
		NodeData* nData = new NodeData(*rhs->data);	//creating new NodeData object with value from rhs tree
		insert(nData);					//inserting NodeData object in lhs tree
		traverseToCopy(rhs->left);					//traverse to left
		traverseToCopy(rhs->right);					//traverse to right
	}
}

// ------------------------------------------------ == operator -----------------------------------------------------
// Description: Operator that compares two BinTree objects and returns whether two objects are equal or not
// Parameter is BinTree object
// Returning boolean as a result of the comparison
// Assumption: Define two trees to be equal if they have the same data and same structure.
// ------------------------------------------------------------------------------------------------------------------
bool BinTree::operator==(const BinTree& rhs) const {
	//returning result of private helper function
	return comparison(root, rhs.root);
}

// ------------------------------------- traverseToCopy helper function ---------------------------------------------
// Description: Recursively traverses the BinTree object and compares values in lhs and rhs trees
// Parameters are Node pointers
// Returning boolean as a result of the comparison
// Private function
// ------------------------------------------------------------------------------------------------------------------
bool BinTree::comparison(Node* lhs, Node* rhs) const {

	//if at the leaf, return true
	if (lhs == NULL && rhs == NULL) {
		return true;
	}
	//else return result of comparison and recursive calls
	if (lhs != NULL && rhs != NULL) {
		return (*lhs->data == *rhs->data && comparison(lhs->left, rhs->left)
				&& comparison(lhs->right, rhs->right));
	}
	return false;
}

// ------------------------------------------------ != operator -----------------------------------------------------
// Description: Operator that compares two BinTree objects and returns whether two objects are equal or not
// Parameter is BinTree object
// Returning boolean as a result of the comparison
// Assumption: Define two trees to be equal if they have the same data and same structure.
// ------------------------------------------------------------------------------------------------------------------
bool BinTree::operator!=(const BinTree& rhs) const {
	//calling == operator to return opposite result of it
	return !(*this == rhs);
}

// -------------------------------------------------- getHeight -----------------------------------------------------
// Description: function to find the height of a given value in the tree.
// Parameter is NodeData(must not be modified)
// Returning int that represents height of a given value
// Notes:
// - do not get to know that the tree is a binary search tree.
// - must solve the problem for a general binary tree where data could be stored anywhere.
// - the height of a node at a leaf is 1, height of a node at the next level is 2, and so on.
// - the height of a value not found is zero.
// ------------------------------------------------------------------------------------------------------------------
int BinTree::getHeight(const NodeData& target) const {
	int count = 0;
	Node* location = NULL;
	//if location found, execute following
	if (findNode(target, root, location)) {
		//calculate height by using recursive calls
		count += heightHelper(count, location);
		return count;
	} else {
		return count;		//return 0 if location is not found
	}
}

// ---------------------------------------- findNode helper function ------------------------------------------------
// Description: Recursively traverses the BinTree to find given value in the tree
// Parameters are NodeData object, current and location Node pointers
// Returns boolean whether object was found or not
// Private function
// ------------------------------------------------------------------------------------------------------------------
bool BinTree::findNode(const NodeData& target, Node* curr,
		Node* &location) const {
	if (curr != NULL) {
		//if found, move here location pointer and return true
		if (target == *curr->data) {
			location = curr;
			return true;
		}
		//go left and go right recursively
		return findNode(target, curr->left, location)
				|| findNode(target, curr->right, location);
	}
	//return false if not found
	return false;
}

// ------------------------------------------ heightHelper function -------------------------------------------------
// Description: Recursively traverses the BinTree to calculate height of the node in the tree
// Parameters are int counter and location Node pointers
// Returns int incremented counter
// Private function
// ------------------------------------------------------------------------------------------------------------------
int BinTree::heightHelper(int count, Node* &location) const {
	if (location != NULL) {
		//go left and right recursively and increment counter
		return (count = 1
				+ max(heightHelper(count, location->left),
						heightHelper(count, location->right)));
	}
	//return 0 if hit NULL
	return 0;
}

// ------------------------------------------------ bstreeToArray ---------------------------------------------------
// Description: Function to fill an array of Nodedata* by using an inorder traversal of the tree.
//				It leaves the tree empty
// Parameter is pointer to NodeData array
// Notes:
// - assume a statically allocated array of 100 NULL elements.
// - no size error checking necessary.
// ------------------------------------------------------------------------------------------------------------------
void BinTree::bstreeToArray(NodeData** storage) {
	//initial counter to traverse array
	int a = -1;
	int* count = &a;
	toArray(storage, root, count);//helper function that traverses array and tree, and copies data to the tree
	this->makeEmpty();				//making tree empty

}

// --------------------------------------------- toArray function ---------------------------------------------------
// Description: Recursively traverses the BinTree and given array in order to copy data from the tree
// Parameters are pointer to storage array, pointer to the current location and int counter
// Private function
// ------------------------------------------------------------------------------------------------------------------
void BinTree::toArray(NodeData** storage, Node* &curr, int* &count) {
	//in order to get data in sorted order, following pattern must be executed
	//if nowhere to go, just end recursion
	if (curr != NULL) {
		toArray(storage, curr->left, count);		//traverse to the left first
		NodeData* data = new NodeData(*curr->data);	//create new DataNode object with data from the tree
		(*count)++;									//increment count
		storage[*count] = data;						//adding data to storage
		toArray(storage, curr->right, count);		//traverse to the right
	}
}

// ------------------------------------------------ arrayToBSTree ---------------------------------------------------
// Description: Function that builds a balanced BinTree from a sorted array of NodeData*
//				leaving the array filled with NULLs
// Parameter is pointer to NodeData array
// Notes:
// - root (recursively) is at (low+high)/2 where low is the lowest subscript of
//	 the array range and high is the highest
// ------------------------------------------------------------------------------------------------------------------
void BinTree::arrayToBSTree(NodeData** storage) {
	this->makeEmpty();				//make tree empty before copying data in it
	int size = 0;					//initial size of array before calculation
	//loop to calculate how far array is filled
	for (;;) {
		if (storage[size] == NULL)
			break;
		else
			size++;
	}
	int low = 0;
	size--;
	toTree(storage, low, size);			//call helper function
}

// --------------------------------------------- toTree function ----------------------------------------------------
// Description: Recursively traverses the BinTree and given array in order to copy data into the tree
// Parameters are pointer to storage array, pointer to the current location and int counter
// Private function
// ------------------------------------------------------------------------------------------------------------------
void BinTree::toTree(NodeData** storage, int low, int high) {
	//insert if lower bound below or equal to higher bound
	if (low <= high) {
		this->insert(storage[(low + high) / 2]);		//insert data into tree
		storage[(low + high) / 2] = NULL;				//placing NULL in array
		toTree(storage, low, ((low + high) / 2 - 1));//splitting array to traverse recursively
		toTree(storage, ((low + high) / 2 + 1), high);//splitting array to traverse recursively
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
// Parameter is pointer to NodeData object
// Returns boolean whether insert was successful
// Note: matching data is being discarded
// ------------------------------------------------------------------------------------------------------------------
bool BinTree::insert(NodeData* data) {
	return insert(data, root);	//calling helper function
}

// --------------------------------------------- insert function ----------------------------------------------------
// Description: Recursively traverses the BinTree in order to insert data
// Parameters are pointer to the tree
// Private function
// ------------------------------------------------------------------------------------------------------------------
bool BinTree::insert(NodeData* data, Node* &curr) {
	//if root == NULL, so insert and set result to true
	if (curr == NULL) {
		curr = new Node();
		curr->data = data;
		curr->left = NULL;
		curr->right = NULL;
		return true;
	} else if (*data < *curr->data) {		//go to left recursively
		return insert(data, curr->left);
	} else if (*data > *curr->data) {		//go to right recursively
		return insert(data, curr->right);
	}
	return false;	//if can't insert data because matching data in the tree
}

//------------------------- displaySideways ---------------------------------
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::displaySideways() const {
	sideways(root, 0);
}

//---------------------------- Sideways -------------------------------------
// Helper method for displaySideways
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::sideways(Node* current, int level) const {
	if (current != NULL) {
		level++;
		sideways(current->right, level);

		// indent for readability, 4 spaces per depth level
		for (int i = level; i >= 0; i--) {
			cout << "    ";
		}

		cout << *current->data << endl;        // display information of object
		sideways(current->left, level);
	}
}
