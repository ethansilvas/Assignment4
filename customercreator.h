//------------------------------- customercreator.h --------------------------------------
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: June 11, 2019 
//------------------------------------------------------------------------------
// Purpose - Class to create and manage customers and add them to the HashTable
// of customers. Header file for CustomerCreator.
// -----------------------------------------------------------------------------
// Assumptions: Implemented as manager class with createCustomer(), getCustomer()
// -----------------------------------------------------------------------------

#ifndef CUSTOMERCREATOR_H
#define CUSTOMERCREATOR_H

#include "customer.h"
#include "hashtable.h"

class CustomerCreator 
{
public:
    //Constructors and Destructor
    CustomerCreator();
    ~CustomerCreator();
    //Public methods for CustomerCreator
    void createCustomer(ifstream &);
    Customer* getCustomer(const int id);
private:
    //Hashtable to store all customers
    HashTable customers;
};

#endif