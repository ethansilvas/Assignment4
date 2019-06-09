#include "inventory.h"

void Inventory::processInventory(ifstream& dataFile)
{
    string line;

    for (;;)
    {
        getline(dataFile, line);

        if (dataFile.eof())
        {
            break;
        }

        Movie* current = MovieFactory::createMovie(line);

        switch (line[0])
        {
            case 'F':
                comedyBST.insert(current);
                break;
            case 'D':
                dramaBST.insert(current);
                break;
            case 'C':
                classicBST.insert(current);
                break;
            default:
                break;
        }
    }
}

void Inventory::displayInventory()
{
    comedyBST.inorderDisplay();
    dramaBST.inorderDisplay();
    classicBST.inorderDisplay();
}

Movie* Inventory::retriveMovie(Movie* movie, const char type)
{
    switch (type)
    {
        case 'D':
            return dramaBST.retrieve(movie);
            break;
        case 'F':
            return comedyBST.retrieve(movie);
            break;
        case 'C':
            return classicBST.retrieve(movie);
            break;
        default:
            break;
    }
    return NULL;
}