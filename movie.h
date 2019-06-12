//------------------------------- movie.h --------------------------------------
//
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: June 11, 2019 
//------------------------------------------------------------------------------
// Purpose - This is an abstract class for Movie to be used in Child Classes
// Drama, Comedy, and Classic. Contains implementation for a general Movie.
// Header file for Movie.
// -----------------------------------------------------------------------------
// Assumptions: Implemented as an abstract class.
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
    //Destructor for movie
    virtual ~Movie();

    //Utility methods
    virtual bool increaseStock(int); 
    virtual bool decreaseStock(); 
    virtual int getStock(); 

    //Pure virtual methods
    virtual void display() const = 0;
    virtual string getInfo() const = 0;

    //Operator overloads
    virtual bool operator<(const Movie& rhs) const = 0;
    virtual bool operator==(const Movie& rhs) const = 0;
    virtual bool operator>(const Movie& rhs) const = 0;
protected:
    //Constructor for Movie
    Movie();
    //Helper functions
    void parseData(const string& line);

    //Class variables
    string director, title;
    int year, stock;
    char type;
};

#endif