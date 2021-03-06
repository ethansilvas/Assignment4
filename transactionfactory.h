// ----------------------------------- transactionfactory.h ---------------------
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: June 11, 2019 
//------------------------------------------------------------------------------
// Purpose - Uses the factory method pattern to create new Transactions.
// Header file for TransactionFactory
// -----------------------------------------------------------------------------
// Assumptions: Implemented as factory method with a static pointer to 
// Transaction* createTransaction().
// -----------------------------------------------------------------------------

#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H

#include "transaction.h"
#include "borrow.h"
#include "return.h"
#include "history.h"
#include "inventory.h"

class TransactionFactory
{
public:
    //Method to create transaction
    static Transaction* createTransaction(const char& type);
};

#endif