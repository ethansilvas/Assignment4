//------------------------------- drama.h --------------------------------------
//
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: 
//------------------------------------------------------------------------------
// Purpose - 
// -----------------------------------------------------------------------------
// Assumptions: 
// -----------------------------------------------------------------------------

#ifndef DRAMA_H
#define DRAMA_H

#include "movie.h"

class Drama : public Movie
{
public:
    //constructors 
    Drama();
    Drama(const string& newTitle, const string& newDirector);
    Drama(const string& line);
    virtual ~Drama();

    //define pure virtuals
    virtual void display() const;
    virtual string getInfo();

    //operator overloads
    virtual bool operator==(const Movie& rhs) const;
	virtual bool operator<(const Movie& rhs) const;
    virtual bool operator>(const Movie& rhs) const;
};

#endif