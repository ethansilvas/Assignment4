#ifndef BORROW_H
#define BORROW_H

#include "customercreator.h"
#include "storeinventory.h"
#include "transaction.h"

class Borrow : public Transaction
{
public:
    Borrow();
    ~Borrow();
    virtual void processTransaction(const string line, CustomerCreator& customer, StoreInventory& inventory);
protected:
    void readTransaction(const string info, Customer* customer, StoreInventory& inventory);
    void doBorrow(Customer* customer, Movie* movieBorrow, Movie* movieCopy);
};

#endif //BORROW_H