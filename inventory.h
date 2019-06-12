//------------------------------- inventory.h --------------------------------------
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

#include "transaction.h"

class Inventory : public Transaction 
{
public: 
    Inventory();
    ~Inventory();

    virtual void processTransaction(const string line, CustomerCreator& CustomerCreator, StoreInventory& inventory);
};

#endif