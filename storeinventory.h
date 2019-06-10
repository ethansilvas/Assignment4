//------------------------------- inventory.h ----------------------------------
//
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: 
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

class StoreInventory
{
public:
    void processInventory(ifstream & dataFile);
    void displayInventory();

    Movie* retrieveMovie(Movie* movie, const char type);
private:
    BinTree comedyBST;
    BinTree dramaBST;
    BinTree classicBST;
};

#endif