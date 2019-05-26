//------------------------------- BinTree.h ------------------------------------
//
// Ethan Silvas, CSS 343 B
// Creation Date: April 13, 2019
// Date of Last Modification: April 27, 2019
//------------------------------------------------------------------------------
// Purpose - This class will create a binary search tree without a remove
// function. It will be able to read a series of strings from a text file
// to build the tree.
// -----------------------------------------------------------------------------
// Assumptions: There will not be any use of removing anything from the tree,
// and it is assumed that the text file containing all of the strings ends with
// "$$" to signify that the file is done.
// -----------------------------------------------------------------------------

#ifndef BINTREE_H
#define BINTREE_H

#include "nodedata.h"

class BinTree
{
    //overloaded output operator
    friend ostream &operator<<(ostream &outStream, const BinTree &tree);
public:
    //constructors and destructor
    BinTree();
    BinTree(const BinTree& otherTree);
    ~BinTree();

    //operator overloads
    BinTree& operator=(const BinTree &otherTree);
    bool operator==(const BinTree &otherTree) const;
	bool operator!=(const BinTree &otherTree) const;

    //tree operations
    bool isEmpty() const;
    void makeEmpty();
    bool insert(NodeData* newNode);
    bool retrieve(const NodeData &nodeToFind, NodeData* &foundNode) const;
    void displaySideways() const;
    int getHeight(const NodeData &nodeToFind) const;
    void bstreeToArray(NodeData* array[]);
    void arrayToBSTree(NodeData* array[]);
private:
    struct Node
    {
        NodeData* data;
        Node* left;
        Node* right;
    };

    Node* root;

    //constructor helpers
    void deleteTree(Node* subTreeRoot);
    Node* copyTree(const Node* subTreeRoot) const;

    //overload helpers
    bool equalityHelper(Node* first, Node* second) const;

    //tree operation helpers
    void sideways(Node* current, int level) const;
    bool insertHelper(Node*& subTreeRoot, NodeData* newNode);
    void inorderHelper(Node* subTreeRoot) const;
    bool retrieveHelper(Node* subTreeRoot, const NodeData &nodeToFind, NodeData* &foundNode) const;
    int getHeightFinder(Node* subTreeRoot, const NodeData &nodeToFind) const;
    int getHeightCalc(Node* subTreeRoot) const;
    void toArrayHelper(Node* subTreeRoot, NodeData* array[], int& index);
    void toBSTHelper(Node* subTreeRoot, NodeData* array[], int start, int end);
};

#endif
