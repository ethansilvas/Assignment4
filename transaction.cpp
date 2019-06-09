#include "transaction.h"

Transaction::Transaction()
{
    errors = "";
}

Transaction::~Transaction()
{

}

void Transaction::processTransaction(string s, Customer* cust, Inventory* inv, HashTable& customers)
{

}

string Transaction::getErrors()
{
    return errors;
}

bool Transaction::customerValid(Customer* cust, int id)
{
    if (cust == nullptr)
    {
        ostringstream stringStream;
        stringStream << id;
        addError("Invalid ID: " + stringStream.str());
        return false;
    }
    return true;
}

void Transaction::addError(string err)
{
    errors = "* " + err + "\n";
}
