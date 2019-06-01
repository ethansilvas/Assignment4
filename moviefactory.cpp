//------------------------------- moviefactory.cpp -----------------------------
//
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: 
//------------------------------------------------------------------------------
// Purpose - 
// -----------------------------------------------------------------------------
// Assumptions: 
// -----------------------------------------------------------------------------

#include "moviefactory.h"

Movie* MovieFactory::createMovie(const string& line)
{
    Movie* movie = NULL;
    switch (line[0])
    {
        case 'F':
            movie = (Movie*) new Comedy(line);
            break;
        case 'D':
            movie =  (Movie*) new Drama(line);
            break;
        case 'C':
            movie = (Movie*) new Classic(line);
            break;
        default:
            movie = NULL;
            break;
    }
    return movie;
}