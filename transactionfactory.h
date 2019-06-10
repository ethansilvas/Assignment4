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
    static Transaction* createTransaction(const char& type);
};

#endif