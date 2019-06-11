#ifndef CUSTOMERCREATOR_H
#define CUSTOMERCREATOR_H

#include "customer.h"
#include "hashtable.h"

class CustomerCreator 
{
public:
    
    CustomerCreator();
    ~CustomerCreator();
    void createCustomer(ifstream &);
    Customer* getCustomer(const int id);
private:
    HashTable customers;
};

#endif