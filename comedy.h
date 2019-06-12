//------------------------------- comedy.h --------------------------------------
//
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: June 11, 2019 
//------------------------------------------------------------------------------
// Purpose - Header file for Comedy. Contains implementations for Comedy Movie.
// Inherits from Parent class Movie. 
// -----------------------------------------------------------------------------
// Assumptions: 
// -----------------------------------------------------------------------------

#ifndef COMEDY_H
#define COMEDY_H

#include "movie.h"

class Comedy : public Movie
{
public:
    //constructors and destructors 
    Comedy();
    Comedy(const string& newTitle, const int& newYear);
    Comedy(const string& line);
    virtual ~Comedy();

    //Virtual functions
    virtual void display() const;
    virtual string getInfo() const;

    //Operator overloads
    virtual bool operator==(const Movie& rhs) const;
	virtual bool operator<(const Movie& rhs) const;
    virtual bool operator>(const Movie& rhs) const;
};

#endif