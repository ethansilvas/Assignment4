//------------------------------- comedy.cpp --------------------------------------
//
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: June 11, 2019 
//------------------------------------------------------------------------------
// Purpose - Contains implementations for Comedy Movie. Inherits from Parent class
// Movie. 
// -----------------------------------------------------------------------------
// Assumptions: 
// -----------------------------------------------------------------------------

#include "comedy.h"

/**
 * @brief  Default no arg constructor for Comedy Movie
 * @note   
 * @retval 
 */
Comedy::Comedy()
{

} //end default constructor 

/**
 * @brief  Constructor that creates Comedy movie using Title and Year
 * @note   
 * @param  newTitle: Title of the comedy movie
 * @param  newYear: Year of the comedy movie
 * @retval 
 */
Comedy::Comedy(const string& newTitle, const int& newYear)
{
    this->title = newTitle;
    this->year = newYear;
}

/**
 * @brief  Constructor that uses passed in string transaction to create movie
 * @note   
 * @param  line: String transaction that contains movie info
 * @retval 
 */
Comedy::Comedy(const string& line) {
    parseData(line);
}

/**
 * @brief  Destructor for Comedy
 * @note   
 * @retval 
 */
Comedy::~Comedy()
{
    
}

/**
 * @brief  Equality operator overload for Comedy movie
 * @note   
 * @param  movie: Movie to be compared with this->movie
 * @retval True if equal, false otherwise
 */
bool Comedy::operator==(const Movie& movie) const 
{
	const Comedy& comedyCast = static_cast<const Comedy&>(movie);
	return (title == comedyCast.title && year == comedyCast.year);
}//end of ==

/**
 * @brief  Comparison operator overload for Comedy Movie
 * @note   
 * @param  movie: Movie to be compared with this->movie
 * @retval True if less than compared movie, false otherwise
 */
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

/**
 * @brief  Comparison operator overload for comedy movie
 * @note   Reuses < operator overload and inverts output
 * @param  movie: Movie to be compared with this->movie
 * @retval True if greater than, false otherwise
 */
bool Comedy::operator>(const Movie& movie) const {
	return !(*this < movie);
}//end of >

/**
 * @brief  Displays formatted Comedy movie information 
 * @note   
 * @retval None
 */
void Comedy::display() const
{
    cout << left << setw(33) << this->title << " "
		 << setw(22) << this->director << " " << setw(5) << this->year << endl;
} //end of display

/**
 * @brief  Returns information of comedy movie as string
 * @note   
 * @retval String with comedy movie info
 */
string Comedy::getInfo() const
{
    ostringstream ss;
    ss << "Comedy: "<< title << " " << director << " " << year;
    return ss.str();
}