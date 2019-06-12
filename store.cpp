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

/**
 * @brief  Method to read data from files
 * @note   Uses storeinventory object and customercreater object to manage customers and movies
 * @param  movieData: Filestream containing text file of movies
 * @param  customerData: Filestream containing text file of customers
 * @retval None
 */
void Store::readData(ifstream& movieData, ifstream& customerData)
{
    inventory.processInventory(movieData);
    customerCreator.createCustomer(customerData);
}

/**
 * @brief  Method to read commands from a file using commandreader object
 * @note   
 * @param  commandData: Filestream containing text file of commands to execute
 * @retval None
 */
void Store::readCommands(ifstream& commandData)
{
    commandReader.readCommands(commandData, customerCreator, inventory);
}