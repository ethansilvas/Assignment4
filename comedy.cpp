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

#include "comedy.h"

// --------------------- Default Constructor -----------------------------------
//  
// -----------------------------------------------------------------------------
Comedy::Comedy()
{

} //end default constructor 

Comedy::Comedy(const Comedy& other)
{
    this->title = other.title;
    this->director = other.director;
    this->year = other.year;
    this->type = other.type;
    this->stock = other.stock;
}

Comedy::Comedy(const string& line) {
    parseData(line);
}

bool Comedy::operator==(const Movie& movie) const {
	const Comedy& comedyCast = static_cast<const Comedy&>(movie);
	return (title == comedyCast.title && year == comedyCast.year);
}//end operator ==

bool Comedy::operator<(const Movie& movie) const {
	const Comedy& comedyCast = static_cast<const Comedy&>(movie);

	if (title < comedyCast.title)
    {
        return true;
    }
	else if (title == comedyCast.title)
    {
        return (year < comedyCast.year);
	}
	else
    {
        return false;
    }
}//end operator <