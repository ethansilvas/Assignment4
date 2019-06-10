#ifndef BORROW_H
#define BORROW_H
#include <string>
#include <iostream>
#include <fstream>
#include "customer.h"
#include "storeinventory.h"
#include "transaction.h"
#include <stdio.h>
using namespace std;

class Borrow : public Transaction
{

    public:
    Borrow();
    ~Borrow();
    virtual void processTransaction(string, Customer*, StoreInventory*, HashTable&);
    static const char type = 'B';

    protected:

    void borrowMovie(Customer*, Movie*, Movie*);
    void readTransaction(string info, Customer* cust, StoreInventory* inv);
};

#endif //BORROW_H