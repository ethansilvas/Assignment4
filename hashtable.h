//------------------------------- hashtable.h --------------------------------------
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: June 11, 2019 
//------------------------------------------------------------------------------
// Purpose - Contains implementation for a HashTable designed to store customers
// by hashing their ID as the key. Header file for HashTable.
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
    //Constructor and destructor
    HashTable();
    ~HashTable();

    //public methods for hashtable
    Customer* getCustomer(int);
    bool putCustomer(const int, Customer* newCustomer);
private:
    //implementing open hashing, use 97 as B and hash value 
    //largest prime number to 100, will hold all possible remainders
    static const int HASH = 97;

    void buildTable();
    void deleteTable();

    //Structs needed for hashtable
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