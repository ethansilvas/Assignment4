#include "inventory.h"

Inventory::Inventory()
{
    errors = "";
}

Inventory::~Inventory()
{

}

void Inventory::processTransaction(const string line, CustomerCreator& customerCreator, StoreInventory& inventory)
{
    inventory.displayInventory();
}