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

/**
 * @brief  Reads first character of line and creates appropriate movie 
 * @note   Default case breaks switch and does not add movie if the input is anything other than F, D, C
 * @param  line: String with movie information
 * @retval Pointer to the movie created
 */
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