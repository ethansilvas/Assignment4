// ----------------------------------- transactionfactory.h ---------------------
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: 
//------------------------------------------------------------------------------
// Purpose - 
// -----------------------------------------------------------------------------
// Assumptions: 
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