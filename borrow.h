//------------------------------- borrow.h --------------------------------------
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: 
//------------------------------------------------------------------------------
// Purpose - Contains implementations for Borrow methods
// -----------------------------------------------------------------------------
// Assumptions: 
// -----------------------------------------------------------------------------

#ifndef BORROW_H
#define BORROW_H

#include "customercreator.h"
#include "storeinventory.h"
#include "transaction.h"

class Borrow : public Transaction
{
public:
    //Constructur and destructor
    Borrow();
    ~Borrow();
    //Method to process transaction
    virtual void processTransaction(const string line, CustomerCreator& customer, StoreInventory& inventory);
protected:
    //helper methods
    void readTransaction(const string info, Customer* customer, StoreInventory& inventory);
    void doBorrow(Customer* customer, Movie* movieBorrow, Movie* movieCopy);
};

#endif //BORROW_H