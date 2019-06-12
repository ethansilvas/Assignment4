// ----------------------------------- transactionfactory.cpp ---------------------
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: June 11, 2019 
//------------------------------------------------------------------------------
// Purpose - Uses the factory method pattern to create new Transactions.
// -----------------------------------------------------------------------------
// Assumptions: Implemented as factory method with a static pointer to 
// Transaction* createTransaction().
// -----------------------------------------------------------------------------

#include "transactionfactory.h"

/**
 * @brief  Method to create a transaction based on the type
 * @note   B = borrow, R = return, I = new inventory, H - new history
 * @param  type: Character passed in that contains the type of transaction
 * @retval Pointer to the transaction created
 */
Transaction* TransactionFactory::createTransaction(const char& type)
{
    Transaction* transaction = NULL;
    switch (type)
    {
        case 'B':
            transaction = new Borrow();
            break;
        case 'R':
            transaction = new Return();
            break;
        case 'I':
            transaction = new Inventory();
            break;
        case 'H':
            transaction = new History();
            break;
        default:
            transaction = NULL;
            break;
    }
    return transaction; 
}