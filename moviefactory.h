//------------------------------- moviefactory.h -------------------------------
//
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: June 11, 2019 
//------------------------------------------------------------------------------
// Purpose - MovieFactory class has implementations to create Movies from an input string.
// Header file for MovieFactory.
// -----------------------------------------------------------------------------
// Assumptions: Implemented using factory method pattern
// -----------------------------------------------------------------------------

#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H

#include "movie.h"
#include "drama.h"
#include "comedy.h"
#include "classic.h"
#include <string>

class MovieFactory 
{
public:
    //Method to create movie
    static Movie* createMovie(const string& line);
};

#endif 