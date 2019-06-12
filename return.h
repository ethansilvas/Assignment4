// -----------------------return.h-----------------------------------------
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: 
//------------------------------------------------------------------------------
// Purpose - 
// -----------------------------------------------------------------------------
// Assumptions: 
// -----------------------------------------------------------------------------

#ifndef RETURN_H
#define RETURN_H

#include "transaction.h"

class Return : public Transaction
{
public:
    Return();
    ~Return();

    virtual void processTransaction(const string line, CustomerCreator& customerCreator, StoreInventory& inventory);
protected:
    void readTransaction(const string info, Customer* customer, StoreInventory& inventory);
    void doReturn(Customer* customer, Movie* movieReturn, Movie* movieCopy);
};

#endif