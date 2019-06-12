//------------------------------- customercreator.cpp --------------------------------------
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: June 11, 2019 
//------------------------------------------------------------------------------
// Purpose - Contains implementations to create and manage customers and add them to the HashTable
// of customers. 
// -----------------------------------------------------------------------------
// Assumptions: Implemented as manager class with createCustomer(), getCustomer()
// -----------------------------------------------------------------------------

#include "customercreator.h"

/**
 * @brief  No arg constructor for CustomerCreator
 * @note   
 * @retval 
 */
CustomerCreator::CustomerCreator() 
{
    
}

/**
 * @brief  Destructor for CustomerCreator
 * @note   
 * @retval 
 */
CustomerCreator::~CustomerCreator() 
{
    
}

/**
 * @brief  Create customer using filestream
 * @note   Read values from file and insert into new customer
 * @param  file: Text file containing information to create a customer
 * @retval None
 */
void CustomerCreator::createCustomer(ifstream& file) {
    for (;;) 
    {

        int id;
        string first, last, temp;
        
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

/**
 * @brief  Accessor method to get customer 
 * @note   
 * @param  id: Look up customer using ID
 * @retval Pointer to Customer looked up by ID
 */
Customer* CustomerCreator::getCustomer(const int id) 
{
    Customer* customer = customers.getCustomer(id);
    return customer;
}