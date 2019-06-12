//------------------------------- transaction.cpp --------------------------------------
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: June 11, 2019 
//------------------------------------------------------------------------------
// Purpose - Used as a parent class for Borrow and Return. Has general implementations
// for Transactions. 
// -----------------------------------------------------------------------------
// Assumptions: Implemented as a parent class with processTransaction() and getErrors().
// -----------------------------------------------------------------------------

#include "transaction.h"

/**
 * @brief  No arg constructor for Transaction
 * @note   Sets errors to ""
 * @retval 
 */
Transaction::Transaction()
{
    errors = "";
}

/**
 * @brief  Destructor for Transaction
 * @note   
 * @retval 
 */
Transaction::~Transaction()
{

}

/**
 * @brief  Method to process transaction (to be overloaded by child classes)
 * @note   
 * @param  line: String with transaction information
 * @param  customerCreator: Customer manager object
 * @param  inventory: Store inventory object
 * @retval None
 */
void Transaction::processTransaction(const string line, CustomerCreator& customerCreator, StoreInventory& inventory)
{

}

/**
 * @brief  Accessor for Errors
 * @note   
 * @retval all errors returned as string
 */
string Transaction::getErrors()
{
    return errors;
}

/**
 * @brief  Helper method to check if customer is valid
 * @note   Assumes that customers are not null if they are valid
 * @param  customer: Pointer to customer passed in 
 * @param  id: ID of customer
 * @retval True if customer is valid, false if customer is invalid
 */
bool Transaction::customerValid(Customer* customer, const int id)
{
    if (customer == nullptr)
    {
        ostringstream ss;
        ss << id;
        addError("Invalid Customer ID: " + ss.str());
        return false;
    }

    return true;
}

/**
 * @brief  Method to add error to errors string
 * @note   
 * @param  err: String containing error
 * @retval None
 */
void Transaction::addError(const string err)
{
    errors = "ERROR: "+  err + "\n";
}
