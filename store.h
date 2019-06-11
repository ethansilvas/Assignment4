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
#include "commandreader.h"
#include "customer.h"
#include "hashtable.h"


class Store
{
public:
    void readData(ifstream& movieData);
    void readCommands(ifstream& commandData);
private:
    StoreInventory inventory;
    StoreInventory* inv = &inventory; //Pointer or reference?
    //Necessary?
    CommandReader commands;
    HashTable customers;
    //Todo: add customer/customer manager to pass into commandreader
};

#endif