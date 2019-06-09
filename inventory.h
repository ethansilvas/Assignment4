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

#ifndef INVENTORY_H
#define INVENTORY_H

#include "bintree.h"
#include "moviefactory.h"
#include "movie.h"
#include <fstream>

class Inventory
{
public:
    void processInventory(ifstream & dataFile);
    void displayInventory();

    Movie* retriveMovie(Movie* movie, const char type);
private:
    BinTree comedyBST;
    BinTree dramaBST;
    BinTree classicBST;
};

#endif