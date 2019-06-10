#include "inventory.h"

Inventory::Inventory()
{
    errors = "";
}

Inventory::~Inventory()
{

}

void Inventory::processTransaction(const string line, Customer* customer, StoreInventory* inventory, HashTable& customers)
{
    inventory->displayInventory();
}