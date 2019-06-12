//------------------------------- history.h --------------------------------------
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: June 11, 2019 
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
//Constructor and destructor
    History();
    ~History();
//Class method to process transaction passed in
    virtual void processTransaction(const string line, CustomerCreator& customerCreator, StoreInventory& inventory);
};

#endif