//------------------------------- inventory.cpp --------------------------------------
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: June 11, 2019 
//------------------------------------------------------------------------------
// Purpose - Contains implementation for Inventory class which is able to
// display all comedy, drama, and classic movies.
// -----------------------------------------------------------------------------
// Assumptions: Inherits from parent class Transaction.
// -----------------------------------------------------------------------------

#include "inventory.h"

/**
 * @brief  Default no arg constructor for Inventory
 * @note   Sets errors to ""
 * @retval 
 */
Inventory::Inventory()
{
    errors = "";
}

/**
 * @brief  Destructor for Inventory
 * @note   
 * @retval 
 */
Inventory::~Inventory()
{

}

/**
 * @brief  Method to process transaction in inventory
 * @note   Calls function from StoreInventory object
 * @param  line: String containing transaction information
 * @param  customerCreator: Customer manager object
 * @param  inventory: Storeinventory object
 * @retval None
 */
void Inventory::processTransaction(const string line, CustomerCreator& customerCreator, StoreInventory& inventory)
{
    inventory.displayInventory();
}