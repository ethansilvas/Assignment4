//------------------------------- store.cpp ------------------------------------
//
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: 
//------------------------------------------------------------------------------
// Purpose - 
// -----------------------------------------------------------------------------
// Assumptions: 
// -----------------------------------------------------------------------------

#include "store.h"


void Store::readData(ifstream& movieData)
{
    inventory.processInventory(movieData);
    inventory.displayInventory();
}

void Store::readCommands(ifstream& commandData)
{
    //TODO: pass in Customer
    commands.readCommands(commandData, customer, inv, customers);
}