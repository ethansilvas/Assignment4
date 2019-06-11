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

void Store::readData(ifstream& movieData, ifstream& customerData)
{
    inventory.processInventory(movieData);
    inventory.displayInventory();
    customerCreator.createCustomer(customerData);
}

void Store::readCommands(ifstream& commandData)
{
    commandReader.readCommands(commandData, customerCreator, inventory);
}