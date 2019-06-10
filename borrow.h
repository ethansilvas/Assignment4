#ifndef BORROW_H
#define BORROW_H

#include "customer.h"
#include "storeinventory.h"
#include "transaction.h"
#include "hashtable.h"

class Borrow : public Transaction
{
public:
    Borrow();
    ~Borrow();
    virtual void processTransaction(const string line, Customer* customer, StoreInventory* inventory, HashTable& customers);
protected:
    void readTransaction(const string info, Customer* customer, StoreInventory* inventory);
    void doBorrow(Customer* customer, Movie* movieBorrow, Movie* movieCopy);
};

#endif //BORROW_H