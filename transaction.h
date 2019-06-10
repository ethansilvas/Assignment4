#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "customer.h" 
#include "inventory.h"
#include "hashtable.h"


class Transaction
{
public:
    Transaction();
    virtual ~Transaction();

    virtual void processTransaction(const string line, Customer* cust, Inventory* inv, HashTable& customers);
    string getErrors();  
protected:
    bool customerValid(Customer* cust, const int id);
    string errors;
    void addError(const string error);
};

#endif //TRANSACTION_H