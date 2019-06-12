//------------------------------- commandreader.cpp --------------------------------------
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: June 11, 2019 
//------------------------------------------------------------------------------
// Purpose - Class that contains methods to read commands from a text file
// and process them using the appropriate methods from CustomerCreator and Store
// Inventory objects. Uses factory pattern to create transactions. Header file for CommandReader. 
// -----------------------------------------------------------------------------
// Assumptions: Implemented as manager class with readCommands(), displayErrors().
// -----------------------------------------------------------------------------

#include "commandreader.h"

/**
 * @brief  Default no arg constructor for commandreader
 * @note   
 * @retval 
 */
CommandReader::CommandReader()
{

}

/**
 * @brief  Destructor for CommandReader object
 * @note   
 * @retval 
 */
CommandReader::~CommandReader()
{

}

/**
 * @brief  Method to read commands from a file
 * @note   Uses helper method to create and process Transaction
 * @param  file: File containing command information 
 * @param  customerCreator: Customer manager to create customers based on commands
 * @param  inventory: Store inventory object to create Movies
 * @retval None
 */
void CommandReader::readCommands(ifstream& file, CustomerCreator& customerCreator, StoreInventory& inventory)
{
    string line;
    Transaction* transaction = NULL;
    char type;

    for (;;)
    {
        file >> type;
        transaction = TransactionFactory::createTransaction(type);
        
        if (file.eof())
        {
            break;
        }

        switch (type)
        {
            case 'B':
            case 'R':
            case 'I':
            case 'H':
                getline(file, line);
                transaction->processTransaction(line, customerCreator, inventory);
                errors += transaction->getErrors();
                delete transaction;
                transaction = NULL;
                break;
            default:
                getline(file, line);
                string invalid(1, type);
                errors += "Invalid transaction type: " + invalid + "\n";
                break;
        }
    }
    delete transaction;
    transaction = NULL;
    displayErrors();
}

/**
 * @brief  Displays allinvalid command errors received during readCommands
 * @note   
 * @retval None
 */
void CommandReader::displayErrors() const
{
    cout << errors;
}