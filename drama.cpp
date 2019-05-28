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

#include "drama.h"

Drama::Drama(const Drama& other)
{
    this->title = other.title;
    this->director = other.director;
    this->year = other.year;
    this->type = other.type;
    this->stock = other.stock;
}

Drama::Drama(const string& line) {
    parseData(line);
}


bool Drama::operator==(const Movie& movie) const{
	const Drama& dramaCast = static_cast<const Drama&>(movie);
	return (this->title == dramaCast.title && this->director == dramaCast.director);
} //end of ==

 bool Drama::operator<(const Movie& movie) const {
	const Drama& dramaCast = static_cast<const Drama&>(movie);

	if (this->director < dramaCast.director){
		return true;
	}
	else if (this->director == dramaCast.director)
    {
        return (this->title < dramaCast.title);
	}
	else
    {
        return false;
    }
}// end of <

void Drama::display() const { 
	cout << left << setw(22) << title << " "
		 << setw(18) << director << " "
		<< setw(5) << year << endl;
}//end of display