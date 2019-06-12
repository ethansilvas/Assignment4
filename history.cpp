//------------------------------- history.cpp --------------------------------------
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: 
//------------------------------------------------------------------------------
// Purpose - 
// -----------------------------------------------------------------------------
// Assumptions: 
// -----------------------------------------------------------------------------

#include "history.h"

History::History()
{

}

History::~History()
{

}

void History::processTransaction(const string line, CustomerCreator& customerCreator, StoreInventory& inventory)
{
    int customerID; 
    Customer* customerToFind = NULL;

    stringstream ss;
    ss << line;

    ss >> customerID;
    customerToFind = customerCreator.getCustomer(customerID);

    if (customerValid(customerToFind, customerID))
    {
        customerToFind->displayHistory();
        cout << endl;
    }
}