//------------------------------- customercreator.cpp --------------------------------------
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: 
//------------------------------------------------------------------------------
// Purpose - 
// -----------------------------------------------------------------------------
// Assumptions: 
// -----------------------------------------------------------------------------

#include "customercreator.h"

CustomerCreator::CustomerCreator() 
{
    
}

CustomerCreator::~CustomerCreator() 
{
    
}

void CustomerCreator::createCustomer(ifstream& file) {
    for (;;) 
    {
        int id;
        string last;
        string first;
        string temp;
        
        getline(file, temp, ' ');
        stringstream(temp) >> id;
        getline(file, last, ' ');
        getline(file, first);
        
        if (file.eof()) break;
        
        Customer* newCustomer = new Customer(id, last, first);
        bool validCustomer = customers.putCustomer(id, newCustomer);
        if (!validCustomer)
        {
            delete newCustomer;
        }
    }
}

Customer* CustomerCreator::getCustomer(const int id) 
{
    Customer* customer = customers.getCustomer(id);
    return customer;
}