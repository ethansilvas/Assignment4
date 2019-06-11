#include "transaction.h"

Transaction::Transaction()
{
    errors = "";
}

Transaction::~Transaction()
{

}

void Transaction::processTransaction(const string line, CustomerCreator& customerCreator, StoreInventory& inventory)
{

}

string Transaction::getErrors()
{
    return errors;
}

bool Transaction::customerValid(Customer* customer, const int id)
{
    if (customer == nullptr)
    {
        ostringstream ss;
        ss << id;
        addError("Invalid ID: " + ss.str());
        return false;
    }
    return true;
}

void Transaction::addError(const string err)
{
    errors = err + "\n";
}
