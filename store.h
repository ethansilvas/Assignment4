//------------------------------- store.h --------------------------------------
//
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: June 11, 2019 
//------------------------------------------------------------------------------
// Purpose - Has implementations to create store from text files and commands.
// Header file for Store.
// -----------------------------------------------------------------------------
// Assumptions: Implemented as manager class with readData() and readCommands().
// -----------------------------------------------------------------------------

#ifndef STORE_H
#define STORE_H

#include "storeinventory.h"
#include "commandreader.h"
#include "customercreator.h"
#include "hashtable.h"


class Store
{
public:
    //Public functions to read files
    void readData(ifstream& movieData, ifstream& customerData);
    void readCommands(ifstream& commandData);
private:
    //Private objects
    StoreInventory inventory;
    CommandReader commandReader;
    CustomerCreator customerCreator;
};

#endif