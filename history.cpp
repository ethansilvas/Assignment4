//------------------------------- history.cpp --------------------------------------
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: June 11, 2019 
//------------------------------------------------------------------------------
// Purpose - Implementation that is able to process and display
// history for customers. 
// -----------------------------------------------------------------------------
// Assumptions: Customer passed in to get history is non null, 
// Inherits from Parent class Transaction.
// -----------------------------------------------------------------------------

#include "history.h"

/**
 * @brief  Default noarg constructor for History
 * @note   
 * @retval 
 */
History::History()
{

}

/**
 * @brief  Destructor for History
 * @note   
 * @retval 
 */
History::~History()
{

}

/**
 * @brief  Process transaction passed in
 * @note   
 * @param  line: String with transaction info
 * @param  customerCreator: Customer manager to manage customers
 * @param  inventory: Store inventory object
 * @retval None
 */
void History::processTransaction(const string line, CustomerCreator& customerCreator, StoreInventory& inventory)
{
    int customerID; 
    Customer* customerToFind = NULL;

    stringstream ss;
    ss << line;

    //attempt to find the customer, and print out their history if it is valid
    ss >> customerID;
    customerToFind = customerCreator.getCustomer(customerID);

    if (customerValid(customerToFind, customerID))
    {
        customerToFind->displayHistory();
        cout << endl;
    }
}