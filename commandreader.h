#ifndef COMMANDREADER_H
#define COMMANDREADER_H

#include "customer.h"
#include "inventory.h"
#include "transactionfactory.h"

class CommandReader
{
public:
    CommandReader();
    ~CommandReader();

    void readCommands(ifstream& file, Customer* customer, StoreInventory* inventory, HashTable& customers);
    void displayErrors() const;
private:
    string errors;
};

#endif