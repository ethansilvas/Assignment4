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
    //Constructor and destructor
    Return();
    ~Return();

    //Class method to process transaction
    virtual void processTransaction(const string line, CustomerCreator& customerCreator, StoreInventory& inventory);
protected:
    //Protected helper methods
    void readTransaction(const string info, Customer* customer, StoreInventory& inventory);
    void doReturn(Customer* customer, Movie* movieReturn, Movie* movieCopy);
};

#endif