//------------------------------- main.cpp -------------------------------------
//
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: June 11, 2019 
//------------------------------------------------------------------------------
// Purpose - Main class for testing. Checks for valid text files and calls
// StoreInventory to process the text files and transactions.
// -----------------------------------------------------------------------------
// Assumptions: Text files are valid and exist in the working directory.
// -----------------------------------------------------------------------------

#include "store.h"

/**
 * @brief  Main method to test reading in from files to process transactions
 * @note   
 * @retval int 0
 */
int main()
{
    Store store;

    ifstream customers("data4customers.txt");
    ifstream movies("data4movies.txt");

    if (!movies || !customers)
    {
        cout << "File not found" << endl;
    }
    else
    {
        store.readData(movies, customers);
    }
    
    ifstream commands("data4commands.txt");
    if (!commands)
    {
        cout << "File not found" << endl;
    }
    else
    {
        store.readCommands(commands);   
    }

    return 0;
}