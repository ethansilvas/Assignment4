#include "commandreader.h"

CommandReader::CommandReader()
{

}

CommandReader::~CommandReader()
{

}

void CommandReader::readCommands(ifstream& file, CustomerCreator& customerCreator, StoreInventory& inventory)
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
                transaction->processTransaction(line, customerCreator, inventory);
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