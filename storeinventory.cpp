#include "storeinventory.h"

void StoreInventory::processInventory(ifstream& dataFile)
{
    errorCount = 0;
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
                addError(line);
                break;
        }
    }
}

void StoreInventory::displayInventory() //
{
    cout << "--------------------------------------------------------------" << endl <<
		"IN TITLE                             DIRECTOR              YEAR" << endl <<
		"---------------------------------------------------------------------" << endl;
    comedyBST.inorderDisplay();
    cout << "--------------------------------------------------------------" << endl <<
		"IN TITLE                             DIRECTOR              YEAR" << endl <<
		"---------------------------------------------------------------------" << endl;
    dramaBST.inorderDisplay();
    cout << "--------------------------------------------------------------" << endl <<
		"IN TITLE                          DIRECTOR          MO  YEAR  ACTOR" << endl <<
		"---------------------------------------------------------------------" << endl;
    classicBST.inorderDisplay();
}

Movie* StoreInventory::retrieveMovie(Movie* movie, const char type)
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

void StoreInventory::addError(const string error)
{
    errorCount++;
    ostringstream temp;
    temp << errorCount;
    errors += "ERROR: "; //
    errors += temp.str() + ") ";
    errors += error;
    errors += "\n";
} 

void StoreInventory::displayErrors() const
{
    cout << errors;
}