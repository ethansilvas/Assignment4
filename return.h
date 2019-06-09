#ifndef RETURN_H
#define RETURN_H

#include "transaction.h"

class Return : public Transaction
{
public:
    Return();
    ~Return();

    virtual void processTransaction(const string line, Customer* cust, Inventory* inv, HashTable& customers);

protected:

};

#endif