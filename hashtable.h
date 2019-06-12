//------------------------------- hashtable.h --------------------------------------
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: 
//------------------------------------------------------------------------------
// Purpose - 
// -----------------------------------------------------------------------------
// Assumptions: 
// -----------------------------------------------------------------------------

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "customer.h"
#include <fstream>

class HashTable
{
public:
    HashTable();
    ~HashTable();

    Customer* getCustomer(int);
    bool putCustomer(const int, Customer* newCustomer);
private:
    //implementing open hashing, use 97 as B and hash value 
    //largest prime number to 100, will hold all possible remainders
    static const int HASH = 97;

    void buildTable();
    void deleteTable();

    struct HashList
    {
        int key;
        Customer* value;
        HashList* next;
    };

    struct HashEntry
    {
        HashList* head;
    };

    HashEntry table[HASH];
};

#endif