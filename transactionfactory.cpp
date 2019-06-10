#include "transactionfactory.h"

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