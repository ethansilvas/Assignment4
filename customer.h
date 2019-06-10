#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <fstream>
#include "movie.h"

class Customer
{
public:

Customer();
~Customer();

bool addTransaction(const char type, Movie* movie);
bool borrowMovie(Movie* toBorrow);
bool returnMovie(Movie* toReturn);

void displayHistory();
string getCustomerInfo() const;
bool createCustomer(ifstream& file);

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