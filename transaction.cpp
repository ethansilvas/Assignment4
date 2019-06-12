//------------------------------- transaction.cpp --------------------------------------
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: 
//------------------------------------------------------------------------------
// Purpose - 
// -----------------------------------------------------------------------------
// Assumptions: 
// -----------------------------------------------------------------------------

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
        addError("Invalid Customer ID: " + ss.str());
        return false;
    }
    return true;
}

void Transaction::addError(const string err)
{
    errors = "ERROR: "+  err + "\n";
}
