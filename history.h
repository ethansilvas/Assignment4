#ifndef HISTORY_H
#define HISTORY_H

#include "transaction.h"

class History : public Transaction
{
public:
    History();
    ~History();

    virtual void processTransaction(const string line, Customer* customer, StoreInventory* inventory, HashTable& customers);
};

#endif