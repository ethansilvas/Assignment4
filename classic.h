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
    Classic(const string& newTitle, const int& newMonth, const int& newYear);
    Classic(const string& line);
	virtual ~Classic();

    //define pure virtuals
    virtual void display() const;
    virtual string getInfo() const;

    //operator overloads
    virtual bool operator==(const Movie& rhs) const;
	virtual bool operator<(const Movie& rhs) const;
    virtual bool operator>(const Movie& rhs) const;

protected:
    //redefine for extra data that needs to be read in 
    void parseData(const string& line);

private:
	string majorActor;
	int month;    
};

#endif