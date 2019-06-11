#include "hashtable.h"

HashTable::HashTable()
{
    buildTable();
}

void HashTable::buildTable()
{
    for (int i = 0; i < HASH; i++)
    {
        table[i].head = NULL;
    }
}

HashTable::~HashTable()
{
    deleteTable();
}

void HashTable::deleteTable()
{
    for (int i = 0; i < HASH; i++)
    {
        if (table[i].head != NULL)
        {
            HashList* current = table[i].head;

            while (table[i].head != NULL)
            {
                table[i].head = table[i].head->next;
                delete current->value;
                delete current;
                current = NULL;
                current = table[i].head;
            }
        }
    }
}

bool HashTable::putCustomer(const int key, Customer* newCustomer)
{
    if (key < 0 || key > 9999)
    {
        return false;
    }

    int hashValue = key % HASH;

    HashList* newNode = new HashList;
    newNode->value = newCustomer;
    newNode->key = key;
    newNode->next = NULL;

    if (table[hashValue].head == NULL)
    {
        newNode->next = table[hashValue].head;
        table[hashValue].head = newNode;
    }
    else
    {
        HashList* current = table[hashValue].head;

        while (current->next != NULL)
        {
            if (key == current->key)
            {
                delete newNode->value;
                delete newNode;
                newNode = NULL;
                return false;
            }
            current = current->next;
        }
        current->next = newNode;
    }
    return true;
}

Customer* HashTable::getCustomer(const int key)
{
    if (key < 0 || key > 9999)
    {
        return NULL;
    }

    int hashValue = key % HASH;

    if (table[hashValue].head == NULL)
    {
        return NULL;
    }
    else
    {
        HashList* newNode = table[hashValue].head;

        while (newNode != NULL)
        {
            if (key == newNode->key)
            {
                return newNode->value;
            }
            newNode = newNode->next;
        }
    }
    return NULL;
}

void HashTable::print()
{
    for (int i = 0; i < HASH; i++)
    {
        if (table[i].head != NULL)
        {
            HashList* current = table[i].head;
            
            while (current != NULL)
            {
                cout << current->value->getCustomerInfo() << endl;
                current = current->next;
            }
        }
    }
}

/* 
void HashTable::insertCustomers(ifstream& file)
{
    //while the file has data to read
    while(!file.eof()) {

        //create a new customer
        Customer* temp = new Customer;

        //if we are able to create a new Customer, aka all the data is correct
        if (temp->createCustomer(file)){
            if(!file.eof()) {

                this->putCustomer(temp->getID(), temp);
            }
            else
            {
                delete temp;
            }
        }
        else
        {
            delete temp;
        }
    }
}
*/