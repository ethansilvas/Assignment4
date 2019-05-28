//------------------------------- classic.h ------------------------------------
//
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: 
//------------------------------------------------------------------------------
// Purpose - 
// -----------------------------------------------------------------------------
// Assumptions: 
// -----------------------------------------------------------------------------

#ifndef CLASSIC_H
#define CLASSIC_H

#include "movie.h"

class Classic : public Movie
{
public:
    Classic();
	Classic(const Classic& rightSide);
    Classic(const string& line);
	~Classic();

    //define pure virtuals
    virtual void display() const;

    //operator overloads
    virtual bool operator==(const Movie& rhs) const;
	virtual bool operator<(const Movie& rhs) const;

protected:
    void parseData(const string& line);

private:
	string majorActor;
	int month;    
};

#endif