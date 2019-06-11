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
/* 
    string fuck = "fuck";
    int asd = 1;
    Comedy* a = new Comedy(fuck, asd);
    Comedy* b = new Comedy(fuck, asd);

    cout << "HELLO" << (*a == *b) << endl;
    */

    return 0;
}