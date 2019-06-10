#include "commandreader.h"

void CommandReader::readCommands(ifstream& file, Customer* customer, StoreInventory* inventory, HashTable& customers)
{
    string line;
    Transaction* transaction = NULL;
    char type;

    for (;;)
    {
        file >> type;
        transaction = TransactionFactory::createTransaction(type);
        
        if (file.eof())
        {
            break;
        }

        switch (type)
        {
            case 'B':
            case 'R':
            case 'I':
            case 'H':
                getline(file, line);
                transaction->processTransaction(line, customer, inventory, customers);
                errors += transaction->getErrors();
                delete transaction;
                transaction = NULL;
                break;
            default:
                getline(file, line);
                string invalid(1, type);
                errors += "* Invalid transaction type: " + invalid + "\n";
                break;
        }
    }
    delete transaction;
    transaction = NULL;
    displayErrors();
}

void CommandReader::displayErrors() const
{
    cout << errors;
}