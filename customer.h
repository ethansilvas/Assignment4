//------------------------------- customer.h --------------------------------------
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: June 11, 2019 
//------------------------------------------------------------------------------
// Purpose - Contains implementation for the Customer class. This class stores
// Transaction history, ID, firstname, last name, and all customer related
// information. Header file for Customer.
// -----------------------------------------------------------------------------
// Assumptions: 
// -----------------------------------------------------------------------------

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <fstream>
#include "movie.h"

class Customer
{
public:

//Constructors and destructor
Customer();
Customer(const int id, const string last, const string first);
~Customer();

//Public methods for Customer
bool addTransaction(const char type, Movie* movie);
bool borrowMovie(Movie* toBorrow);
bool returnMovie(Movie* toReturn);


void displayHistory();
string getCustomerInfo() const;

int getID();

private:
    //data members for a customer
    int id;
    string firstName;
    string lastName;

    //helper methods for transactions 
    bool addBorrow(Movie* borrowed);
    bool addReturn(Movie* returned);

    //create a node for a list of a customer's history 
    struct historyNode
    {
        Movie* movieData;
        historyNode* next;
        char transType;
    };
    historyNode* historyHead;

    //create a node for the list of transactions to fulfill
    struct transactionNode
    {
        Movie* movieData;
        transactionNode* next;
        char transType;
    };
    transactionNode* transactionHead;
};

#endif