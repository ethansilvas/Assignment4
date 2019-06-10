#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "customer.h" 
#include "storeinventory.h"
#include "hashtable.h"


class Transaction
{
public:
    Transaction();
    virtual ~Transaction();

    virtual void processTransaction(const string line, Customer* customer, StoreInventory* inventory, HashTable& customers);
    string getErrors();  
protected:
    bool customerValid(Customer* customer, const int id);
    string errors;
    void addError(const string error);
};

#endif //TRANSACTION_H