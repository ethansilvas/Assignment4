#ifndef RETURN_H
#define RETURN_H

#include "transaction.h"
#include "inventory.h"
#include "customer.h"

class Return : public Transaction
{
public:
    Return();
    ~Return();

    virtual void processTransaction(string line, Customer& cust, Inventory& inv);

protected:

};

#endif