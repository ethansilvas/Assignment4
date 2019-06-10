#ifndef INVENTORY_H
#define INVENTORY_H

#include "transaction.h"

class Inventory : public Transaction 
{
public: 
    Inventory();
    ~Inventory();

    virtual void processTransaction(const string line, Customer* customer, StoreInventory* inventory, HashTable& customers);
};

#endif