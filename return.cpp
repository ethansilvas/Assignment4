#include "return.h"

Return::Return() {}

Return::~Return() {}

void Return::processTransaction(const string line, Customer* cust, Inventory* inv, HashTable& customers)
{
    string currentLine;
    int newID;
    Customer* newCustomer = NULL;

    stringstream ss;
    ss << currentLine;

    ss >> newID;
}