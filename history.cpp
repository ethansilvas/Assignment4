#include "history.h"

History::History()
{

}

History::~History()
{

}

void History::processTransaction(const string line, Customer* customer, StoreInventory* inventory, HashTable& customers)
{
    int customerID; 
    Customer* customerToFind = NULL;

    stringstream ss;
    ss << line;

    ss >> customerID;
    customerToFind = customers.getCustomer(customerID);

    if (customerValid(customerToFind, customerID))
    {
        customerToFind->displayHistory();
    }
}