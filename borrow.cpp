//------------------------------- borrow.cpp --------------------------------------
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: June 11, 2019 
//------------------------------------------------------------------------------
// Purpose - Inherits from Parent class Transaction. Contains implementations for
// methods related to borrowing movies.
// -----------------------------------------------------------------------------
// Assumptions: 
// -----------------------------------------------------------------------------

#include "borrow.h"

/**
 * @brief  Default no arg constructor, initializes error string to ""
 * @note   
 * @retval 
 */
Borrow::Borrow()
{
    errors = "";
}

/**
 * @brief  Destructor for Borrow class
 * @note   
 * @retval 
 */
Borrow::~Borrow()
{
    
}

/**
 * @brief  processes transaction passed in
 * @note   
 * @param  line: String with transaction information from file
 * @param  customerCreator: Customer manager class to create customers
 * @param  inventory: Storeinventory object
 * @retval None
 */
void Borrow::processTransaction(const string line, CustomerCreator& customerCreator, StoreInventory& inventory)
{
    string currentLine;
    int id;
    Customer* newCustomer = NULL;

    stringstream stream;
    stream << line;

    stream >> id;
    newCustomer = customerCreator.getCustomer(id);

    if (customerValid(newCustomer, id))
    {
        getline(stream, currentLine);
        readTransaction(currentLine, newCustomer, inventory);
    }
}

/**
 * @brief  Reads transaction from string
 * @note   
 * @param  line: String with transaction command
 * @param  customer: Customer linked to ID from transaction
 * @param  inventory: Storeinventory object
 * @retval None
 */
void Borrow::readTransaction(const string line, Customer* customer, StoreInventory& inventory)
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
                doBorrow(customer, customerMovie, movieCopy);
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
                doBorrow(customer, customerMovie, movieCopy);
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
                doBorrow(customer, customerMovie, movieCopy);
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

/**
 * @brief  Method to execute borrow action 
 * @note   
 * @param  customer: Customer that is borrowing the movie
 * @param  movieBorrow: Movie being borrowed
 * @param  movieCopy: 
 * @retval None
 */
void Borrow::doBorrow(Customer* customer, Movie* movieBorrow, Movie* movieCopy)
{
    if (movieBorrow != NULL)
    {
        bool validBorrow = customer->borrowMovie(movieBorrow);

        if (!validBorrow)                   
        {
            addError("Invalid borrow: " + customer->getCustomerInfo() + ", " + movieBorrow->getInfo());
        }
    }
    else
    {
        addError("Movie cannot be borrowed: " + movieCopy->getInfo());
    }
}