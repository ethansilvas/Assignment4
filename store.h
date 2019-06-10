//------------------------------- store.h --------------------------------------
//
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: 
//------------------------------------------------------------------------------
// Purpose - 
// -----------------------------------------------------------------------------
// Assumptions: 
// -----------------------------------------------------------------------------

#ifndef STORE_H
#define STORE_H

#include "storeinventory.h"

class Store
{
public:
    void readData(ifstream& movieData);
private:
    StoreInventory inventory;
};

#endif