#include "return.h"

Return::Return() 
{
    errors = "";
}

Return::~Return() {}

void Return::processTransaction(const string line, CustomerCreator& customerCreator, StoreInventory& inventory)
{
    string currentLine;
    int newID;
    Customer* newCustomer = NULL;

    stringstream ss;
    ss << line;

    ss >> newID;
    newCustomer = customerCreator.getCustomer(newID);

    if (customerValid(newCustomer, newID))
    {
        getline(ss, currentLine);
        readTransaction(currentLine, newCustomer, inventory);
    }
}

void Return::readTransaction(const string line, Customer* customer, StoreInventory& inventory)
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

                //get movie and try to return 
                customerMovie = inventory.retrieveMovie(movieCopy, movieType);
                doReturn(customer, customerMovie, movieCopy);
                delete movieCopy;
                movieCopy = NULL;
                break;
            case 'D':
                //read director and title
                getline(ss, movieData2, ',');
                getline(ss, movieData1, ',');

                //create copy and attempt return
                movieCopy = new Drama(movieData1, movieData2);
                customerMovie = inventory.retrieveMovie(movieCopy, movieType);
                doReturn(customer, customerMovie, movieCopy);
                delete movieCopy;
                movieCopy = NULL;
                break;
            case 'C':
                //get month 
                getline(ss, movieData1, ' ');
                getline(ss, movieData1, ' ');
                stringstream(movieData1) >> month;

                //get year
                getline(ss, movieData1, ' ');
                stringstream(movieData1) >> year;

                ss >> movieData1;
                majorActor += movieData1;
                majorActor += ' ';
                ss >> movieData1;
                majorActor += movieData1;

                movieCopy = new Classic(majorActor, month, year);
                customerMovie = inventory.retrieveMovie(movieCopy, movieType);
                doReturn(customer, customerMovie, movieCopy);
                delete movieCopy;
                movieCopy = NULL;
                break;
            default:
                //get the invalid char and print out error message
                getline(ss, movieData1);
                string invalidMovie(1, movieType);
                addError("Invalid movie type: " + invalidMovie + movieData1);
                break;
        }
    }
    else
    {
        //get the invalid char and print error message
        string invalidMedia(1, mediaType);
        getline(ss, movieData1);
        addError("Invalid media type: " + invalidMedia + movieData1);
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
        addError("Movie does not exist to return: " + movieCopy->getInfo()); //
    }
}