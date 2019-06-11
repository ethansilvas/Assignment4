#ifndef COMMANDREADER_H
#define COMMANDREADER_H

#include "customercreator.h"
#include "inventory.h"
#include "transactionfactory.h"

class CommandReader
{
public:
    CommandReader();
    ~CommandReader();

    void readCommands(ifstream& file, CustomerCreator& customerCreator, StoreInventory& inventory);
    void displayErrors() const;
private:
    string errors;
};

#endif