#include "return.h"

Return::Return() {}

Return::~Return() {}

void Return::processTransaction(string line, Customer& cust, Inventory& inv)
{
    string currentLine;
    int newID;
    Customer* newCustomer = NULL;

    stringstream ss;
    ss << currentLine;

    ss >> newID;
}