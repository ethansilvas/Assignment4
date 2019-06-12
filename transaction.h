// ----------------------------------- transaction.h ---------------------------
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: 
//------------------------------------------------------------------------------
// Purpose - 
// -----------------------------------------------------------------------------
// Assumptions: 
// -----------------------------------------------------------------------------

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "customercreator.h" 
#include "storeinventory.h"
#include "hashtable.h"


class Transaction
{
public:
    Transaction();
    virtual ~Transaction();

    virtual void processTransaction(const string line, CustomerCreator& customerCreator, StoreInventory& inventory);
    string getErrors();  
protected:
    bool customerValid(Customer* customer, const int id);
    string errors;
    void addError(const string error);
};

#endif //TRANSACTION_H