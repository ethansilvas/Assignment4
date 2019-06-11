//------------------------------- movie.cpp ------------------------------------
//
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: 
//------------------------------------------------------------------------------
// Purpose - 
// -----------------------------------------------------------------------------
// Assumptions: 
// -----------------------------------------------------------------------------

#include "movie.h"

// --------------------- Default Constructor -----------------------------------
// sets all data members to thier 0 value 
// -----------------------------------------------------------------------------
Movie::Movie()
{
    this->title = "";
    this->director = "";
    this->year = 0;
    this->stock = 0;
    this->type = ' ';
} //end of default constructor 

// --------------------- destructor --------------------------------------------
// sets all data members to thier 0 value 
// -----------------------------------------------------------------------------
Movie::~Movie() {}

// --------------------- parseData ---------------------------------------------
//  takes a line from the data file and parses it into a movie's data members
// -----------------------------------------------------------------------------
void Movie::parseData(const string& line)
{
    stringstream ss;                 // string reader
    ss << line;                      // insert string info into reader
    string temp;                     //  temp string to parse the string
    getline(ss, temp, ',');          // get movie type
    type = temp[0];                  // assign movie type
    getline(ss, temp, ',');          // get stock
    stringstream(temp) >> stock;  // assign stock
    getline(ss, director, ',');      // assign director
    getline(ss, title, ',');         // assign title
    getline(ss, temp, ',');          // get year
    stringstream(temp) >> year;
} //end of parseData

bool Movie::increaseStock(int addToStock) {
    if (addToStock < 0) 
    { 
        return false; 
    }
    else
    {
        stock += addToStock;
        return true;
    }
}

bool Movie::decreaseStock() {
    if (stock <= 0)
    { 
        return false; 
    }
    else
    {
        stock--;
        return true;
    }
}

int Movie::getStock() {
    return stock;
}

/* 
string Movie::getDirector() const
{
    return this->director;
}

string Movie::getTitle() const
{
    return this->title;
}

int Movie::getYear() const
{
    return this->year;
}
*/