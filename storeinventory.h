//------------------------------- storeinventory.h ----------------------------------
//
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: June 11, 2019 
//------------------------------------------------------------------------------
// Purpose - 
// -----------------------------------------------------------------------------
// Assumptions: 
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