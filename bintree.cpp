//------------------------------- BinTree.cpp ----------------------------------
//
// Ethan Silvas, CSS 343 B
// Creation Date: April 13, 2019
// Date of Last Modification: April 27, 2019
//------------------------------------------------------------------------------
// Purpose - This class will create a binary search tree without a remove
// function. It will be able to read a series of strings from a text file
// to build the tree.
// -----------------------------------------------------------------------------
// Assumptions: There will not be any removing anything from the tree,
// and it is assumed that the text file containing all of the strings ends with
// "$$" to signify that the file is done.
// ----------------------------------------------------------------------------

#include "bintree.h"

// --------------------- Default Constructor -----------------------------------
// sets the root of the tree to NULL
// -----------------------------------------------------------------------------
BinTree::BinTree()
{
    this->root = NULL;
} //end fo default constructor

// --------------- Copy constructor --------------------------------------------
// copy constructor for BinTree that makes a deep copy of the arg tree
// -----------------------------------------------------------------------------
BinTree::BinTree(const BinTree& otherTree)
{
    //make sure otherTree isnt this
    if (this != &otherTree)
    {
        this->root = copyTree(otherTree.root);
    }
} //end of copy constructor

// ----------------------- copyTree --------------------------------------------
// helper method to copy a tree given a root node
// -----------------------------------------------------------------------------
BinTree::Node* BinTree::copyTree(const Node* subTreeRoot) const
{
    Node* newTreePtr = NULL;

    if (subTreeRoot != NULL)
    {
        //set pointer to given root
        newTreePtr = new Node;
        newTreePtr->data = new NodeData(*subTreeRoot->data);

        //recur through left and right
        newTreePtr->left = (copyTree(subTreeRoot->left));
        newTreePtr->right = (copyTree(subTreeRoot->right));
    }

    return newTreePtr;
} //end of copyTree

// --------------------- Destructor --------------------------------------------
// deletes a tree and sets the root to NULL
// usese deleteTree helper method
// -----------------------------------------------------------------------------
BinTree::~BinTree()
{
    this->makeEmpty();
} //end of destructor

// --------------------------------- isEmpty -----------------------------------
// returns if the tree is empty or not
// -----------------------------------------------------------------------------
bool BinTree::isEmpty() const
{
    return (this->root == NULL);
} //end of isEmpty

// --------------------------------- makeEmpty ---------------------------------
// no-arg method to clear a tree, calls previously defined deleteTree 
// -----------------------------------------------------------------------------
void BinTree::makeEmpty()
{
    deleteTree(this->root);
} //end of makeEmpty

// ------------------------------ deleteTree -----------------------------------
// helper method to delete an entire tree and set the root to NULL
// -----------------------------------------------------------------------------
void BinTree::deleteTree(Node* subTreeRoot)
{
    if (subTreeRoot != NULL)
    {
        deleteTree(subTreeRoot->left);
        deleteTree(subTreeRoot->right);

        //delete data and set to NULL, do the same with the Node
        delete subTreeRoot->data;
        subTreeRoot->data = NULL;
        delete subTreeRoot;
        subTreeRoot = NULL;
    }

    this->root = NULL;
} //end of deleteTree

// --------------------------------- = -----------------------------------------
// overloads = operator to set calling tree to arg tree
// uses helper method copyTree just as the copy constructor
// -----------------------------------------------------------------------------
BinTree& BinTree::operator=(const BinTree &otherTree)
{
    //make sure that arg tree is not the calling tree
    if (this != &otherTree)
    {
        makeEmpty();
        this->root = this->copyTree(otherTree.root);
    }

    return *this;
} //end of overloaded =

// --------------------------------- == ----------------------------------------
// compares two trees to see if they are exactly the same
// calls equalityHelper
// -----------------------------------------------------------------------------
bool BinTree::operator==(const BinTree &otherTree) const
{
    //check if they are both null or if they are the same object
    if (this == &otherTree || (this->root == NULL && otherTree.root == NULL))
    {
        return true;
    }
    else
    {
        return equalityHelper(this->root, otherTree.root);
    }    
} //end of overloaded ==

// --------------------------- equalityHelper ----------------------------------
// checks equality of two trees by examining equal nodes and structure
// of the tree itself
// compares the values of two given nodes which should both be in the same place
// of the tree
// -----------------------------------------------------------------------------
bool BinTree::equalityHelper(Node* first, Node* second) const
{
    //base cases are when one or both of the nodes are null
    if (first == NULL && second == NULL)
    {
        //got to the end of the tree without returning false
        return true;
    }
    else if ((first == NULL && second != NULL) || (first != NULL && second == NULL))
    {
        //unequal nodes, return false
        return false;
    }
    else 
    {
        //recur down the tree
        if (*first->data == *second->data && equalityHelper(first->left, second->left) 
            && equalityHelper(first->right, second->right)) 
        {
            return true; 
        }

        return false;
    }
} //end of equalityHelper

// --------------------------------- != ----------------------------------------
// compares two trees to see if they not equal
// considers structure and equal node data 
// calls overloaded == operator
// -----------------------------------------------------------------------------
bool BinTree::operator!=(const BinTree &otherTree) const
{
    return !(*this == otherTree);
} //end of overloaded !=

// ------------------------- retrieve ------------------------------------------
// finds a given node in the tree if it exists, calls retrieveHelper
// returns the item in the foundNode NodeData
// returns true if an item is found
// -----------------------------------------------------------------------------
bool BinTree::retrieve(const NodeData &nodeToFind, NodeData* &foundNode) const
{
    return retrieveHelper(this->root, nodeToFind, foundNode);
} //end of retrieve

// ------------------------- retrieveHelper ------------------------------------
// recurs through the tree to find a given node 
// returns true if item is found and returns item through foundNode
// -----------------------------------------------------------------------------
bool BinTree::retrieveHelper(Node* subTreeRoot, const NodeData &nodeToFind, NodeData* &foundNode) const
{
    //recur through left and right until it is found, or a null node is hit
    if (subTreeRoot == NULL)
    {
        return false;
    }
    else if (nodeToFind == *subTreeRoot->data) 
    {
        foundNode = subTreeRoot->data;
        return true;
    }
    else if (nodeToFind < *subTreeRoot->data)
    {
        return retrieveHelper(subTreeRoot->left, nodeToFind, foundNode);
    }
    else
    {
        return retrieveHelper(subTreeRoot->right, nodeToFind, foundNode);
    }
} //end of retrieveHelper

// ------------------------- getHeight ------------------------------------------
// finds the height of a given node in the tree if it exists in the tree
// returns the value of the height, or returns 0 if not found 
// calls getHeightHelper to see if the node exists in the tree
// Precondition: this method does not assume that the tree is a BST, instead it 
// assumes that it could be a general binary tree
// -----------------------------------------------------------------------------
int BinTree::getHeight(const NodeData &nodeToFind) const
{
    return getHeightFinder(this->root, nodeToFind);
} //end of getHeight

// ------------------------- getHeightFinder -----------------------------------
// finds the given node, if it exists, to find the height of it 
// calls getHeightCalc to find the height if the node is found
// -----------------------------------------------------------------------------
int BinTree::getHeightFinder(Node* subTreeRoot, const NodeData &nodeToFind) const
{
    if (subTreeRoot == NULL)
    {
        //node is not in tree so return 0
        return 0;
    }
    else if (*subTreeRoot->data == nodeToFind)
    {
        //node is found so find the height of it
        return getHeightCalc(subTreeRoot);
    }
    else
    {
        //search left and right for the node, and return the height if found
        return max(getHeightFinder(subTreeRoot->left, nodeToFind), 
            getHeightFinder(subTreeRoot->right, nodeToFind));
    }
    
    
} //end of getHeightHelper

// ------------------------- getHeightFinder -----------------------------------
// when a node in getHeightFinder is found, this method finds the height of
// that node
// -----------------------------------------------------------------------------
int BinTree::getHeightCalc(Node* subTreeRoot) const
{
    if (subTreeRoot == NULL)
    {
        //hit the end of the tree so exit recursion with 0
        return 0;
    }
    else
    {
        //recur to add up the height from the node to the bottom
        return 1 + max(getHeightCalc(subTreeRoot->left), getHeightCalc(subTreeRoot->right));
    }
} //end of getHeightCalc

// ------------------------------- bstreeToArray -------------------------------
// fills an array with the calling bst, and leaves the bst empty 
// fills using inorder traversal
// Precondition: array size will be less than 100
// does not check for any size errors 
// calls toArrayHelper
// ----------------------------------------------------------------------------- 
void BinTree::bstreeToArray(NodeData* array[]){
	int i = 0;
	toArrayHelper(this->root, array, i);
	deleteTree(this->root);
} //end of bstreeToArray

// ------------------------- toArrayHelper -------------------------------------
// adds elements to the array using inorder traversal
// keeps track of index while recurring 
// -----------------------------------------------------------------------------
void BinTree::toArrayHelper(Node* subTreeRoot, NodeData* array[], int& index){
	if (subTreeRoot != NULL)
    {
		toArrayHelper(subTreeRoot->left, array, index);

        //set element of index to node data, clear memory, and increment index
        array[index] = subTreeRoot->data;
        subTreeRoot->data = NULL;
        index++;

		toArrayHelper(subTreeRoot->right, array, index);
	}
} //end of toArrayHelper

// ------------------------- arrayToBSTree -------------------------------------
// sets calling bst to arg array, and creates a balanced binary tree
// Preconditions: the array is sorted, and <=100 size
// -----------------------------------------------------------------------------
void BinTree::arrayToBSTree(NodeData* array[])
{
    //clear tree if not already
    this->makeEmpty(); 

    //to get the high value, iterate through array counting all the !NULL values
    int high = 0;
    for(int i = 0; i < 100; i++)   
    {
        if (array[i] != NULL)
        {
            high++; 
        }
    }

    toBSTHelper(this->root, array, 0, high - 1);
} //end of arrayToBSTree

// ------------------------- toBSTHelper ---------------------------------------
// fills in tree using (start + end) / 2 logic 
// start and end are referring to lowest/highest subscript of the array 
// which were found in arrayToBSTree
// -----------------------------------------------------------------------------
void BinTree::toBSTHelper(Node* subTreeRoot, NodeData* array[], int start, int end)
{
    if (start > end)
    {
        subTreeRoot = NULL; 
    }
    else
    {
        //insert the middle value of the array into the BST 
        int mid = (start + end) / 2;

        //make sure to clear the array
        NodeData* newNode = array[mid];
        array[mid] = NULL;

        insert(newNode);   
        toBSTHelper(subTreeRoot, array, start, mid - 1);  
        toBSTHelper(subTreeRoot, array, mid + 1, end);
    }
} //end of toBSTHelper

// ------------------------- insert --------------------------------------------
// inserts a given node into the calling BST, calls insertHelper
// returns true upon a successful insert
// -----------------------------------------------------------------------------
bool BinTree::insert(NodeData* newNode)
{
    return insertHelper(this->root, newNode);
} //end of insert

// ------------------------- insertHelper --------------------------------------
// inserts a new node into the BST given a NodeData pointer
// inserts based on NodeData string values
// uses iterative insert method for BST
// Post-condition: all duplicates are discarded
// -----------------------------------------------------------------------------
bool BinTree::insertHelper(Node*& subTreeRoot, NodeData* newNode)
{
    //create new node to insert into the tree
    Node* insert = new Node;
    insert->data = newNode;
    insert->left = NULL;
    insert->right = NULL;

    //check if the tree is empty
    if (subTreeRoot == NULL)
    {
        subTreeRoot = insert;
        return true;
    }
    else
    {
        //traverse tree to find the appropriate spot
        Node* current = subTreeRoot;
        while (true)
        {
            //check if the newNode is greater, less than, or equal to 
            if (*newNode < *current->data)
            {
                if (current->left == NULL)
                {
                    current->left = insert;
                    return true;
                }
                else
                {
                    current = current->left;
                }
                
            }
            else if (*newNode > *current->data)
            {
                if (current->right == NULL)
                {
                    current->right = insert;
                    return true;
                }
                else 
                {
                    current = current->right;
                }
            }
            else if (*newNode == *current->data)
            {
                //duplicates are discarded
                delete insert;
                return false;
            }
        }
    }
} //end of insertHelper

// --------------------------------- << ----------------------------------------
// outputs the tree using inorder traversal
// NodeData is responisible for its own output
// calls inorderHelper
// -----------------------------------------------------------------------------
ostream &operator<<(ostream &outStream, const BinTree &tree)
{
    //call inorderHelper to print tree, and then print a line
    tree.inorderHelper(tree.root);
    outStream << endl;
    return outStream;
} //end of overloaded << 

// ----------------------------- inorderHelper ---------------------------------
// prints out the tree using inorder traversal
// displays tree items on one line, with a space between each item
// -----------------------------------------------------------------------------
void BinTree::inorderHelper(Node* subTreeRoot) const
{
    if (subTreeRoot != NULL)
    {
        inorderHelper(subTreeRoot->left);
        cout << *subTreeRoot->data << " ";
        inorderHelper(subTreeRoot->right);
    }
} //end of inorderHelper

// ------------------------ displaySideways ---------------------------------
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
// code from Min Chen
// -----------------------------------------------------------------------------
void BinTree::displaySideways() const {
	sideways(root, 0);
} //end of displaySideways

// --------------------------- Sideways -------------------------------------
// Helper method for displaySideways
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
// code from Min Chen
// -----------------------------------------------------------------------------
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
} //end of sidways
