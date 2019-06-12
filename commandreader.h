//------------------------------- commandreader.h --------------------------------------
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: 
//------------------------------------------------------------------------------
// Purpose - 
// -----------------------------------------------------------------------------
// Assumptions: 
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