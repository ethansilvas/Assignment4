//------------------------------- comedy.h --------------------------------------
//
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: 
//------------------------------------------------------------------------------
// Purpose - 
// -----------------------------------------------------------------------------
// Assumptions: 
// -----------------------------------------------------------------------------

#ifndef COMEDY_H
#define COMEDY_H

#include "movie.h"

class Comedy : public Movie
{
public:
    //constructors 
    Comedy();
    Comedy(const Comedy& other);
    Comedy(const string& line);
    ~Comedy();

    //define pure virtuals
    virtual void display() const;

    //operator overloads
    virtual bool operator==(const Movie& rhs) const;
	virtual bool operator<(const Movie& rhs) const;
    virtual bool operator>(const Movie& rhs) const;
};

#endif