//------------------------------- return.cpp --------------------------------------
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: June 11, 2019 
//------------------------------------------------------------------------------
// Purpose - Contains implementation for the return Transaction.
// -----------------------------------------------------------------------------
// Assumptions: Return inherits from Parent class Transaction. Implement with 
// processTransaction(), doReturn(), and readTransaction().
// -----------------------------------------------------------------------------


#include "return.h"

/**
 * @brief  Default no arg constructor for Return 
 * @note   Initializes errors to ""
 * @retval 
 */
Return::Return() 
{
    errors = "";
}

/**
 * @brief  Destructor for Return
 * @note   
 * @retval 
 */
Return::~Return() 
{

}

/**
 * @brief  Method to process the return transaction
 * @note   
 * @param  line: String with information for transaction
 * @param  customerCreator: Customer manager object
 * @param  inventory: Storeinventory object
 * @retval None
 */
void Return::processTransaction(const string line, CustomerCreator& customerCreator, StoreInventory& inventory)
{
    //hold an id number to check for valid customers
    string currentLine;
    int newID;
    Customer* newCustomer = NULL;

    //attempt to create a customer with the given id
    stringstream ss;
    ss << line;
    ss >> newID;
    newCustomer = customerCreator.getCustomer(newID);

    //with a valid customer, the transaction can be attempted
    if (customerValid(newCustomer, newID))
    {
        getline(ss, currentLine);
        readTransaction(currentLine, newCustomer, inventory);
    }
}

/**
 * @brief  Reads transaction from string passed in
 * @note   Calls methods to execute transactions from the string
 * @param  line: String containing information about transaction
 * @param  customer: Customer to perform the transaction on
 * @param  inventory: Storeinventory object to change movie stock
 * @retval None
 */
void Return::readTransaction(const string line, Customer* customer, StoreInventory& inventory)
{
    stringstream ss;
    ss << line;

    //store information to build movies 
    char movieType, mediaType;
    string movieData1, movieData2;
    string majorActor;
    int month = 0, year = 0;

    //store movies to make sure that a movie is available to return
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

                //read in first and last of actor
                ss >> movieData1;
                majorActor += movieData1;
                majorActor += ' ';
                ss >> movieData1;
                majorActor += movieData1;

                //make copy and attempt return
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

/**
 * @brief  Execute the return operation for the customer 
 * @note   Adds error to transaction if movie does not exist or invalid return
 * @param  customer: Customer returning the movie
 * @param  movieReturn: movie to be returned
 * @param  movieCopy: a temp movie to check for valid returns
 * @retval None
 */
void Return::doReturn(Customer* customer, Movie* movieReturn, Movie* movieCopy)
{
    if (movieReturn != NULL)
    {
        //attempt to return the movie
        bool validReturn = customer->returnMovie(movieReturn);
        if (!validReturn)
        {
            addError("Invalid return: " + customer->getCustomerInfo() + ", " + movieReturn->getInfo());
        }
    }
    else
    {
        addError("Movie does not exist to return: " + movieCopy->getInfo());
    }
}