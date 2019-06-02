//------------------------------- movie.h --------------------------------------
//
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: 
//------------------------------------------------------------------------------
// Purpose - 
// -----------------------------------------------------------------------------
// Assumptions: 
// -----------------------------------------------------------------------------

#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

class Movie 
{
public:
    virtual ~Movie();

    //utility methods
    virtual bool increaseStock(int); 
    virtual bool dicreaseStock(); 
    virtual int getStock(); 
    
    //pure virtuals
    virtual void display() const = 0;

    //operator overloads
    virtual bool operator<(const Movie& rhs) const = 0;
    virtual bool operator==(const Movie& rhs) const = 0;
    virtual bool operator>(const Movie& rhs) const = 0;
protected:
    Movie();

    void parseData(const string& line);

    string director, title;
    int year, stock;
    char type;
};

#endif