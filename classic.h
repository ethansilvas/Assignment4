//------------------------------- classic.h ------------------------------------
//
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: June 11, 2019 
//------------------------------------------------------------------------------
// Purpose - Header file for Classic. Contains implementations for methods
// related to Classic movies. 
// -----------------------------------------------------------------------------
// Assumptions: Inherits from Parent class Movie.
// -----------------------------------------------------------------------------

#ifndef CLASSIC_H
#define CLASSIC_H

#include "movie.h"

class Classic : public Movie
{
public:
    //Constructors and Destructors
    Classic();
    Classic(const string& newTitle, const int& newMonth, const int& newYear);
    Classic(const string& line);
	virtual ~Classic();

    //Virtual functions
    virtual void display() const;
    virtual string getInfo() const;

    //Operator overloads
    virtual bool operator==(const Movie& rhs) const;
	virtual bool operator<(const Movie& rhs) const;
    virtual bool operator>(const Movie& rhs) const;

protected:
    //Helper methods for additional data
    void parseData(const string& line);

private:
    //Private class variables
	string majorActor;
	int month;    
};

#endif