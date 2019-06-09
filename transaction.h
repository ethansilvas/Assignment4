#ifndef TRANSACTION_H
#define TRANSACTION_H
using namespace std;
#include <iostream>
#include <fstream>
#include "customer.h" 
#include "inventory.h"


class Transaction
{
    public:
    Transaction();
    virtual ~Transaction();
    virtual void processTransaction(string, Customer*, Inventory*);
    string getErrors();
    static const char DVD = 'D';
    
    protected:
    bool customerValid(Customer*, int);
    string errors = "";
    void addError(string);
};



#endif //TRANSACTION_H