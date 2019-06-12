//------------------------------- customer.cpp --------------------------------------
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: 
//------------------------------------------------------------------------------
// Purpose - 
// -----------------------------------------------------------------------------
// Assumptions: 
// -----------------------------------------------------------------------------

#include "customer.h"

/**
 * @brief  Default no arg constructor. Initializes history list and transaction list
 * to null.
 * @note   
 * @retval 
 */
Customer::Customer() 
{
    historyHead = NULL;
    transactionHead = NULL;
}

/**
 * @brief  Constructor using passed in parameters to create Customer
 * @note   
 * @param  id: Unique ID of the customer
 * @param  last: Lastname of customer
 * @param  first: Firstname of customer
 * @retval 
 */
Customer::Customer(const int id, const string last, const string first) 
{
    this->id = id;
    this->firstName = first;
    this->lastName = last;
    historyHead = NULL;
    transactionHead = NULL;
}

/**
 * @brief  Destructor for customer
 * @note   Sets all appropriate information to null
 * @retval 
 */
Customer::~Customer()
{
    historyNode* current = historyHead;
    while (current != NULL) 
    {
        historyHead = historyHead->next;
        current->movieData = NULL;
        delete current;
        current = historyHead;
    }

    transactionNode* currentTrans = transactionHead;
    while (currentTrans != NULL) 
    {
        transactionHead = transactionHead->next;
        currentTrans->movieData = NULL;
        delete currentTrans;
        currentTrans = transactionHead;
    }
}

/**
 * @brief  Adds a transaction to customer
 * @note   
 * @param  type: Borrow or Return character (B or R)
 * @param  movie: Movie to be borrowed or returned
 * @retval True if successful, false otherwise (TODO false?)
 */
bool Customer::addTransaction(const char type, Movie* movie)
{
    historyNode* newTrans = new historyNode;
    newTrans->movieData = movie;
    newTrans->transType = type;
    newTrans->next = NULL;

    //insert the new transaction at the head of the list
    if (historyHead == NULL)
    {
        historyHead = newTrans;
    }
    else
    {
        //put as new head to reverse
        newTrans->next = historyHead;
        historyHead = newTrans;
    }

    return true;
}

/**
 * @brief  Method for Customer to borrow movie
 * @note   
 * @param  toBorrow: Movie to be borrowed
 * @retval True if successful borrow, false otherwise
 */
bool Customer::borrowMovie(Movie* toBorrow)
{
    if (toBorrow->getStock() != 0 && addBorrow(toBorrow))
    {
        toBorrow->decreaseStock();
        return addTransaction('B', toBorrow);
    }

    return false;
}

/**
 * @brief  Method for customer to return a movie
 * @note   
 * @param  toReturn: Movie to be returned
 * @retval True if successful return, false otherwise
 */
bool Customer::returnMovie(Movie* toReturn)
{
    if (addReturn(toReturn))
    {
        toReturn->increaseStock(1);
        return addTransaction('R', toReturn);
    }

    return false;
}

/**
 * @brief  Display the Customer's transaction history
 * @note   
 * @retval None
 */
void Customer::displayHistory()
{
    historyNode* current = historyHead;

    cout << "Customer: " << id << " " << this->lastName << ", " << this->firstName  << endl; //

    if (current == nullptr) //Verify if logic correct
    {
        cout << "No transactions found" << endl;
        return;
    }

    while (current != NULL)
    {
        if (current->transType == 'B')
        {
            cout << "Borrow: ";
            current->movieData->display();
        }
        else
        {
            cout << "Return: ";
            current->movieData->display();
        } 

        current = current->next;
    }
    
}

/**
 * @brief  Return customer information as a string
 * @note   
 * @retval String with customer information
 */
string Customer::getCustomerInfo() const
{
    ostringstream stringStream;
    stringStream << "Customer ID " << id << ": " << lastName << " " << firstName;
    return  stringStream.str();
}

/**
 * @brief  Add a movie borrowed by customer
 * @note   
 * @param  borrowed: Movie borrowed by customer
 * @retval True if successul, false otherwise
 */
bool Customer::addBorrow(Movie* borrowed)
{
    transactionNode* current = new transactionNode;
    current->movieData = borrowed;
    current->next = NULL;

    if (transactionHead == NULL)
    {
        transactionHead = current;
    }
    else
    {
        current->next = transactionHead;
        transactionHead = current;
    }
}

/**
 * @brief  Add a movie returned by customer
 * @note   
 * @param  movie: Movie returned by customer
 * @retval True if successul, false otherwise
 */
bool Customer::addReturn(Movie* movie)
{
    if (transactionHead == NULL)
    {
        return false;
    }

    transactionNode* current = transactionHead->next;
    transactionNode* previous = transactionHead;

    if (previous->movieData == movie)
    {
        previous->movieData = NULL;
        delete previous;
        transactionHead = current;
        return true;
    }

    while (current != NULL)
    {
        if (current->movieData == movie)
        {
            previous->next = current->next;
            current->movieData = NULL;
            delete current;
            return true;
        }

        previous = current;
        current = current->next;
    }
    return false;
}

/**
 * @brief  Getter method for customerID
 * @note   
 * @retval integer with customer ID
 */
int Customer::getID()
{
    return this->id;
}