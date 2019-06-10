#include "customer.h"

Customer::Customer() 
{
    historyHead = NULL;
}

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

bool Customer::borrowMovie(Movie* toBorrow)
{
    if (toBorrow->getStock() != 0 && addBorrow(toBorrow))
    {
        toBorrow->decreaseStock();
        return addTransaction('B', toBorrow);
    }

    return false;
}

bool Customer::returnMovie(Movie* toReturn)
{
    if (addReturn(toReturn))
    {
        toReturn->increaseStock(1);
        return addTransaction('R', toReturn);
    }

    return false;
}

void Customer::displayHistory()
{
    historyNode* current = historyHead;

    cout << this->firstName << " " << this->lastName << endl;

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
    }
}

string Customer::getCustomerInfo() const
{
    return id + " " + lastName + " " + firstName;
}

bool Customer::createCustomer(ifstream &infile) 
{

    //read in the customer's ID
    infile >> this->id;

    if(this->id >= 0){

        //read in the customer's last name followed by their first name
        infile >> this->lastName;
        infile >> this->firstName;

        //return true to indicate that all fields were successfully populated
        return true;

    }
    else
    {

        //print an error, since we received an invalid ID
        cout << "ERROR: " << this->id
             << " is not a valid customer ID." << endl;

        //return false to indicate that the data given to populate the
        // Customer was not valid
        return false;

    }
}

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

int Customer::getID()
{
    return this->id;
}