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

Drama::Drama()
{

}

Drama::Drama(const string& newTitle, const string& newDirector)
{
	this->title = newTitle;
	this->director = newDirector;
}

Drama::Drama(const string& line) {
    parseData(line);
}

Drama::~Drama()
{
    
}

bool Drama::operator==(const Movie& movie) const 
{
	const Drama& dramaCast = static_cast<const Drama&>(movie);
	return (this->title == dramaCast.title && this->director == dramaCast.director);
} //end of ==

bool Drama::operator<(const Movie& movie) const 
{
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

bool Drama::operator>(const Movie& movie) const 
{
	return !(*this < movie);
}// end of >

void Drama::display() const 
{ 
	cout << left << setw(33) << title << " " 
		<< setw(22) << director << " " << setw(5) << year << endl;
}//end of display

string Drama::getInfo() const
{
	ostringstream ss;
    ss << "Drama: " << director << " " << title << " " << year;
    return ss.str();
}