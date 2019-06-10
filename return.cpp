#include "return.h"

Return::Return() {}

Return::~Return() {}

void Return::processTransaction(const string line, Customer* customer, Inventory* inventory, HashTable& customers)
{
    string currentLine;
    int newID;
    Customer* newCustomer = NULL;

    stringstream ss;
    ss << currentLine;

    ss >> newID;
    newCustomer = customers.getCustomer(newID);

    if (customerValid(newCustomer, newID))
    {
        getline(ss, currentLine);
        
    }
}

void Return::readTransaction(const string line, Customer* customer, Inventory* inventory)
{
    stringstream ss;
    ss << line;

    char movieType, mediaType;
    string movieData1, movieData2;
    string majorActor;
    int month = 0, year = 0;
    Movie* movieCopy = NULL;
    Movie* customerMovie = NULL;

    ss >> mediaType;

    if (mediaType == 'D')
    {
        ss >> movieType;

        switch (movieType)
        {
            case 'F':
                //read title and year
                getline(ss, movieData2, ',');
                getline(ss, movieData1);
                
                //hold the year and make a new comedy with it
                stringstream(movieData1) >> year;
                movieCopy = new Comedy(movieData2, year);
                customerMovie = inventory->retriveMovie(movieCopy, movieType);

                

        }
    }
}

void Return::doReturn(Customer* customer, Movie* movieReturn, Movie* movieCopy)
{
    if (movieReturn != NULL)
    {
        bool validReturn = customer->returnMovie(movieReturn);
        if (!validReturn)
        {
            addError(customer->getCustomerInfo() + "/n" + "Invalid return: " + movieReturn->getInfo());
        }
    }
    else
    {
        addError("Movie does not exist to return: " + movieCopy->getInfo());
    }
    
}