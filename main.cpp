//------------------------------- main.cpp -------------------------------------
//
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: 
//------------------------------------------------------------------------------
// Purpose - 
// -----------------------------------------------------------------------------
// Assumptions: 
// -----------------------------------------------------------------------------

#include "store.h"

int main()
{
    Store store;

    ifstream movies("data4movies.txt");
    if (!movies)
    {
        cout << "File not found" << endl;
    }
    else
    {
        store.readData(movies);
    }
    

    return 0;
}