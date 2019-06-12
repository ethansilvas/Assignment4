//------------------------------- drama.cpp --------------------------------------
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

/**
 * @brief  Default no arg constructor for Drama Movie
 * @note   
 * @retval 
 */
Drama::Drama()
{

}

/**
 * @brief  Constructor for Drama Movie using title and director
 * @note   
 * @param  newTitle: Title of the Movie
 * @param  newDirector: Director of the movie
 * @retval 
 */
Drama::Drama(const string& newTitle, const string& newDirector)
{
	this->title = newTitle;
	this->director = newDirector;
}

/**
 * @brief  Constructor for Drama Movie using info from string
 * @note   Uses helper method to parse string
 * @param  line: String with movie information
 * @retval 
 */
Drama::Drama(const string& line) {
    parseData(line);
}

/**
 * @brief  Destructor for Drama Movie
 * @note   
 * @retval 
 */
Drama::~Drama()
{
    
}

/**
 * @brief  Equality operator overload for Drama Movie
 * @note   
 * @param  movie: Movie to compare with this->movie
 * @retval True if equal, false otherwise
 */
bool Drama::operator==(const Movie& movie) const 
{
	const Drama& dramaCast = static_cast<const Drama&>(movie);
	return (this->title == dramaCast.title && this->director == dramaCast.director);
} //end of ==

/**
 * @brief  Comparison operator overload for Drama movie
 * @note   
 * @param  movie: Movie to compare with this->movie
 * @retval True if less than, false otherwise
 */
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

/**
 * @brief  Comparison operator overload for Drama movie
 * @note   Reuses < operator overload and inverts output
 * @param  movie: Movie to compare with this->movie
 * @retval True if greater than, false otherwise
 */
bool Drama::operator>(const Movie& movie) const 
{
	return !(*this < movie);
}// end of >

/**
 * @brief  Method to display Drama Movie information
 * @note   
 * @retval None
 */
void Drama::display() const 
{
	cout << left << setw(33) << title << " " 
		<< setw(22) << director << " " << setw(5) << year << endl;
}//end of display

/**
 * @brief  Accessor method that returns a string with Drama Movie info
 * @note   
 * @retval String containing drama movie info
 */
string Drama::getInfo() const
{
	ostringstream ss;
    ss << "Drama: " << director << " " << title << " " << year;
    return ss.str();
}