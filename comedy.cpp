//------------------------------- comedy.cpp --------------------------------------
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

Comedy::Comedy(const string& newTitle, const int& newYear)
{
    this->title = newTitle;
    this->year = newYear;
}

Comedy::Comedy(const string& line) {
    parseData(line);
}

Comedy::~Comedy()
{
    
}

bool Comedy::operator==(const Movie& movie) const 
{
	const Comedy& comedyCast = static_cast<const Comedy&>(movie);
	return (title == comedyCast.title && year == comedyCast.year);
}//end of ==

bool Comedy::operator<(const Movie& movie) const {
	const Comedy& comedyCast = static_cast<const Comedy&>(movie);

	if (this->title < comedyCast.title)
    {
        return true;
    }
	else if (this->title == comedyCast.title)
    {
        return (this->year < comedyCast.year);
	}
	else
    {
        return false;
    }
}//end of <

bool Comedy::operator>(const Movie& movie) const {
	return !(*this < movie);
}//end of >

void Comedy::display() const
{
    cout << left << setw(33) << this->title << " "
		 << setw(22) << this->director << " " << setw(5) << this->year << endl;
} //end of display

string Comedy::getInfo() const
{
    ostringstream ss;
    ss << "Comedy: "<< title << " " << director << " " << year;
    return ss.str();
}