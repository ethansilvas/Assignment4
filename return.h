#ifndef RETURN_H
#define RETURN_H

#include "transaction.h"

class Return : public Transaction
{
public:
    Return();
    ~Return();

    virtual void processTransaction(const string line, Customer* customer, Inventory* inventory, HashTable& customers);
protected:
    void readTransaction(const string info, Customer* customer, Inventory* inventory);
    void doReturn(Customer* customer, Movie* movieReturn, Movie* movieCopy);
};

#endif