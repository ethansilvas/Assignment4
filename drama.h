//------------------------------- drama.h --------------------------------------
//
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: June 11, 2019 
//------------------------------------------------------------------------------
// Purpose - Contains implementations for methods for Drama movies. 
// Inherits from Movie class. Header file for Drama class.
// -----------------------------------------------------------------------------
// Assumptions: 
// -----------------------------------------------------------------------------

#ifndef DRAMA_H
#define DRAMA_H

#include "movie.h"

class Drama : public Movie
{
public:
    //constructors and destructor
    Drama();
    Drama(const string& newTitle, const string& newDirector);
    Drama(const string& line);
    virtual ~Drama();

    //Virtual methods
    virtual void display() const;
    virtual string getInfo() const;

    //Operator overloads
    virtual bool operator==(const Movie& rhs) const;
	virtual bool operator<(const Movie& rhs) const;
    virtual bool operator>(const Movie& rhs) const;
};

#endif