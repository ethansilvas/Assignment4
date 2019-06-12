//------------------------------- inventory.cpp --------------------------------------
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: 
//------------------------------------------------------------------------------
// Purpose - 
// -----------------------------------------------------------------------------
// Assumptions: 
// -----------------------------------------------------------------------------

#include "inventory.h"

Inventory::Inventory()
{
    errors = "";
}

Inventory::~Inventory()
{

}

void Inventory::processTransaction(const string line, CustomerCreator& customerCreator, StoreInventory& inventory)
{
    inventory.displayInventory();
}