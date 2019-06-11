//------------------------------- BinTree.cpp ----------------------------------
//
// Ethan Silvas, CSS 343 B
// Creation Date: April 13, 2019
// Date of Last Modification: April 27, 2019
//
// Reused class from assignment 2
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

// ------------------------- retrieve ------------------------------------------
// finds a given node in the tree if it exists, calls retrieveHelper
// returns the item in the foundNode Movie
// returns true if an item is found
// -----------------------------------------------------------------------------
Movie* BinTree::retrieve(const Movie* nodeToFind) //, Movie* &foundNode) const
{
    return retrieveHelper(this->root, nodeToFind); //, foundNode);
} //end of retrieve

// ------------------------- retrieveHelper ------------------------------------
// recurs through the tree to find a given node 
// returns true if item is found and returns item through foundNode
// -----------------------------------------------------------------------------
Movie* BinTree::retrieveHelper(Node*& subTreeRoot, const Movie* nodeToFind) //, Movie* &foundNode) const
{
    //recur through left and right until it is found, or a null node is hit
    if (subTreeRoot == NULL)
    {
        return NULL;
    }
    else if (*nodeToFind == *subTreeRoot->data) 
    {
        return subTreeRoot->data;
    }
    else if (*nodeToFind < *subTreeRoot->data)
    {
        return retrieveHelper(subTreeRoot->left, nodeToFind); //, foundNode);
    }
    else
    {
        return retrieveHelper(subTreeRoot->right, nodeToFind); //, foundNode);
    }
} //end of retrieveHelper

// ------------------------- insert --------------------------------------------
// inserts a given node into the calling BST, calls insertHelper
// returns true upon a successful insert
// -----------------------------------------------------------------------------
bool BinTree::insert(Movie* newNode)
{
    return insertHelper(this->root, newNode);
} //end of insert

// ------------------------- insertHelper --------------------------------------
// inserts a new node into the BST given a Movie pointer
// inserts based on Movie string values
// uses iterative insert method for BST
// Post-condition: all duplicates are discarded
// -----------------------------------------------------------------------------
bool BinTree::insertHelper(Node*& subTreeRoot, Movie* newNode)
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
                //duplicates are discarded, but stock is increased
                bool newStock = current->data->increaseStock(newNode->getStock());
                delete insert;
                return newStock;
            }
        }
    }
} //end of insertHelper

void BinTree::inorderDisplay()
{
    inorderHelper(this->root);
    cout << endl;
}

void BinTree::inorderHelper(Node* subTreeRoot) const
{
    if (subTreeRoot != NULL)
    {
        inorderHelper(subTreeRoot->left);
        cout << setw(2) << subTreeRoot->data->getStock(); //setw 2
        subTreeRoot->data->display();
        inorderHelper(subTreeRoot->right);
    }
}