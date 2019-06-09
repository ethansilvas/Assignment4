#ifndef BORROW_H
#define BORROW_H
#include <string>
#include <iostream>
#include <fstream>
#include "customer.h"
#include "inventory.h"
#include "transaction.h"
#include <stdio.h>
using namespace std;

class Borrow : public Transaction
{

    public:
    Borrow();
    ~Borrow();
    virtual void processTransaction(string, Customer&, Inventory&);
    static const char type = 'B';
};

#endif