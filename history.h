//------------------------------- history.h --------------------------------------
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: 
//------------------------------------------------------------------------------
// Purpose - 
// -----------------------------------------------------------------------------
// Assumptions: 
// -----------------------------------------------------------------------------

#ifndef HISTORY_H
#define HISTORY_H

#include "transaction.h"

class History : public Transaction
{
public:
    History();
    ~History();

    virtual void processTransaction(const string line, CustomerCreator& customerCreator, StoreInventory& inventory);
};

#endif