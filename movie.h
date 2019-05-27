//------------------------------- movie.h --------------------------------------
//
// Ethan Silvas, Pranav CSS 343 B
// Creation Date: April 13, 2019
// Date of Last Modification: April 27, 2019
//------------------------------------------------------------------------------
// Purpose - This class will create a binary search tree without a remove
// function. It will be able to read a series of strings from a text file
// to build the tree.
// -----------------------------------------------------------------------------
// Assumptions: There will not be any removing anything from the tree,
// and it is assumed that the text file containing all of the strings ends with
// "$$" to signify that the file is done.
// ----------------------------------------------------------------------------

#ifndef MOVIE_H
#define MOVIE_H

#include <string>
using namespace std;

class Movie 
{
public:
    virtual ~Movie();
    
    //operator overloads
    virtual bool operator<(const Movie* rhs) const = 0;
    virtual bool operator==(const Movie* rhs) const = 0;
protected:
    Movie();

    string director, title;
    int year, stock;
    char type;
};

#endif