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

#include "movie.h"

class BinTree
{
public:
    //constructors and destructor
    BinTree();
    ~BinTree();

    //tree operations
    bool isEmpty() const;
    void makeEmpty();
    bool insert(Movie* newNode);
    bool retrieve(const Movie &nodeToFind, Movie* &foundNode) const;
private:
    struct Node
    {
        Movie* data;
        Node* left;
        Node* right;
    };

    Node* root;

    //constructor helpers
    void deleteTree(Node* subTreeRoot);

    //tree operation helpers
    void sideways(Node* current, int level) const;
    bool insertHelper(Node*& subTreeRoot, Movie* newNode);
    void inorderHelper(Node* subTreeRoot) const;
    bool retrieveHelper(Node* subTreeRoot, const Movie &nodeToFind, Movie* &foundNode) const;
};

#endif
