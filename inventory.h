//------------------------------- inventory.h --------------------------------------
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: June 11, 2019 
//------------------------------------------------------------------------------
// Purpose - Contains implementation for Inventory class which is able to
// display all comedy, drama, and classic movies. Header file for Inventory.
// -----------------------------------------------------------------------------
// Assumptions: Inherits from parent class Transaction.
// -----------------------------------------------------------------------------

#ifndef INVENTORY_H
#define INVENTORY_H

#include "transaction.h"

class Inventory : public Transaction 
{
public: 
    //Constructor and destructor
    Inventory();
    ~Inventory();
    //Class methods
    virtual void processTransaction(const string line, CustomerCreator& CustomerCreator, StoreInventory& inventory);
};

#endif