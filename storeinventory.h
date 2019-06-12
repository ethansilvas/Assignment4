//------------------------------- storeinventory.h ----------------------------------
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: June 11, 2019 
//------------------------------------------------------------------------------
// Purpose - Contains implementation to read from a given file and insert into a
// Binary Search Tree per genre of Movie. Also keeps track of all invalid
// movies. Header file for StoreInventory.
// -----------------------------------------------------------------------------
// Assumptions: Assumed to be a manager class and assumed to use factory pattern.
// Implemented with processInventory(), retrieveMovie(), and displayInventory().
// -----------------------------------------------------------------------------

#ifndef STOREINVENTORY_H
#define STOREINVENTORY_H

#include "bintree.h"
#include "moviefactory.h"
#include "movie.h"
#include <fstream>
#include <iomanip>

class StoreInventory
{
public:
    //Utility methods
    void processInventory(ifstream & dataFile);
    void displayInventory();

    Movie* retrieveMovie(Movie* movie, const char type);
private:
    //Data members of class
    int errorCount;
    string errors;
    //helper functions for errors
    void addError(const string error); 
    void displayErrors() const;

    //Trees containing movies per genre
    BinTree comedyBST;
    BinTree dramaBST;
    BinTree classicBST;
};

#endif