//------------------------------- commandreader.h --------------------------------------
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: June 11, 2019 
//------------------------------------------------------------------------------
// Purpose - Class that contains methods to read commands from a text file
// and process them using the appropriate methods from CustomerCreator and Store
// Inventory objects. Uses factory pattern to create transactions.
// -----------------------------------------------------------------------------
// Assumptions: Implemented as manager class with readCommands(), displayErrors().
// -----------------------------------------------------------------------------

#ifndef COMMANDREADER_H
#define COMMANDREADER_H

#include "customercreator.h"
#include "inventory.h"
#include "transactionfactory.h"

class CommandReader
{
public:
    //Constructor and destructor
    CommandReader();
    ~CommandReader();

    //Public methods 
    void readCommands(ifstream& file, CustomerCreator& customerCreator, StoreInventory& inventory);
    void displayErrors() const;
private:
    //String of errors collected
    string errors;
};

#endif