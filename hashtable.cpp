//------------------------------- hashtable.cpp --------------------------------------
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: June 11, 2019 
//------------------------------------------------------------------------------
// Purpose - Contains implementation for a HashTable designed to store customers
// by hashing their ID as the key. 
// Implements open hashing with linked lists
// -----------------------------------------------------------------------------
// Assumptions: The customer ID is between Positive and less than 10000. 
// -----------------------------------------------------------------------------

#include "hashtable.h"

/**
 * @brief  No arg constructor for hashtable
 * @note   Calls constructor to create hashtable and fill with nulls
 * @retval 
 */
HashTable::HashTable()
{
    buildTable();
}

/**
 * @brief  Helper method for no arg constructor, fills all values with NULL
 * @note   Initiates the head of each linked list
 * @retval None
 */
void HashTable::buildTable()
{
    for (int i = 0; i < HASH; i++)
    {
        table[i].head = NULL;
    }
}

/**
 * @brief  Destructor for HashTable
 * @note   Calls helper method to delete HashTable
 * @retval 
 */
HashTable::~HashTable()
{
    deleteTable();
}

/**
 * @brief  Helper method for destructor
 * @note   Traverses through HashTable and deletes all values
 * @retval None
 */
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

/**
 * @brief  Method to insert customer into HashTable
 * @note   Keys are assumed to be 1000 < x < 9999
 * @param  key: Key to be used for insert (Customer ID)
 * @param  newCustomer: Customer to be added
 * @retval True if successful insert, false otherwise
 */
bool HashTable::putCustomer(const int key, Customer* newCustomer)
{
    if (key < 0 || key > 9999)
    {
        return false;
    }

    //hash is both the size and B value
    int hashValue = key % HASH;

    //create a new node for the list
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
        //traverse until the end of the current list
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

/**
 * @brief  Getter method for Customer using key
 * @note   
 * @param  key: Key used to get customer
 * @retval Pointer to customer requested
 */
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
        //traverse until the customer is found, using the hashvalue to compare
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