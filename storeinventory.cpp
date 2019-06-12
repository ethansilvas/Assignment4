//------------------------------- storeinventory.cpp --------------------------------------
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: June 11, 2019 
//------------------------------------------------------------------------------
// Purpose - Contains implementation to read from a given file and insert into a
// Binary Search Tree per genre of Movie. Also keeps track of all invalid
// movies.
// -----------------------------------------------------------------------------
// Assumptions: Assumed to be a manager class and assumed to use factory pattern.
// Implemented with processInventory(), retrieveMovie(), and displayInventory().
// -----------------------------------------------------------------------------

#include "storeinventory.h"

/**
 * @brief  Method to process inventory from file passed in
 * @note   
 * @param  dataFile: File containing data to be processed in the inventory
 * @retval None
 */
void StoreInventory::processInventory(ifstream& dataFile)
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
                addError(line);
                break;
        }
    }
}

/**
 * @brief  Displays formatted inventory of all genres of movies
 * @note   
 * @retval None
 */
void StoreInventory::displayInventory() //
{
    cout << "------------------------------------------------------------------" << endl <<
		"IN TITLE                             DIRECTOR              YEAR" << endl <<
		"------------------------------------------------------------------" << endl;
    comedyBST.inorderDisplay();
    cout << "------------------------------------------------------------------" << endl <<
		"IN TITLE                             DIRECTOR              YEAR" << endl <<
		"------------------------------------------------------------------" << endl;
    dramaBST.inorderDisplay();
    cout << "----------------------------------------------------------------------" << endl <<
		"IN TITLE                             DIRECTOR          MO  YEAR  ACTOR" << endl <<
		"----------------------------------------------------------------------" << endl;
    classicBST.inorderDisplay();
}

/**
 * @brief  Method to retrieve a specific movie of type Drama, Comedy or Classic
 * @note   
 * @param  movie: Movie to be retrieved
 * @param  type: Type of movie to be retrieved
 * @retval 
 */
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

/**
 * @brief  Method to add error using string
 * @note   
 * @param  error: String containing errors
 * @retval None
 */
void StoreInventory::addError(const string error)
{

    ostringstream temp;
    errors += "ERROR: ";
    errors += temp.str() + ") ";
    errors += error;
    errors += "\n";
} 

/**
 * @brief  Method to display all errors
 * @note   
 * @retval None
 */
void StoreInventory::displayErrors() const
{
    cout << errors;
}