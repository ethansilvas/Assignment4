#include "transaction.h"

Transaction::Transaction()
{
    errors = "";
}

Transaction::~Transaction()
{

}

void Transaction::processTransaction(const string line, Customer* customer, StoreInventory* inventory, HashTable& customers)
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

void Transaction::addError(string err)
{
    errors = "* " + err + "\n";
}
