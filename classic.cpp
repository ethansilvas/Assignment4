//------------------------------- classic.cpp ----------------------------------
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: June 11, 2019 
//------------------------------------------------------------------------------
// Purpose - Inherits from Parent class Movie. Contains implementations for methods
// related to Classic movies. 
// -----------------------------------------------------------------------------
// Assumptions: 
// -----------------------------------------------------------------------------

#include "classic.h"

/**
 * @brief  Default no arg constructor
 * @note   
 * @retval 
 */
Classic::Classic()
{

} //end default constructor 

/**
 * @brief  Constructor to create Classic movie from parameters
 * @note   
 * @param  newActor: Actor for Classic Movie
 * @param  newMonth: Month for Classic Movie
 * @param  newYear: Year for classic movie
 * @retval 
 */
Classic::Classic(const string& newActor, const int& newMonth, const int& newYear) 
{
    this->majorActor = newActor;
    this->month = newMonth;
    this->year = newYear;
}

/**
 * @brief  Classic Movie constructor using only one string parameter using helper method
 * @note   
 * @param  line: String containing info of Classic movie
 * @retval 
 */
Classic::Classic(const string& line) {
    parseData(line);
}

/**
 * @brief  Destructor for Classic Movie
 * @note   
 * @retval 
 */
Classic::~Classic()
{
    
}

/**
 * @brief  Helper method to parse data for classic movie from string
 * @note   
 * @param  line: string from file with movie info
 * @retval None
 */
void Classic::parseData(const string& line) {
    stringstream ss;
    ss << line;

    string data;

    //get the movie type
    getline(ss, data, ',');
    type = data[0];

    //read the stock
    getline(ss, data, ',');
    stringstream(data) >> stock;

    //read data members
    getline(ss, director, ',');
    getline(ss, title, ',');

    //read in both the first and last name for the actor
    ss >> data;
    majorActor += data;
    majorActor += ' ';       //leave a space between first and last
    ss >> data;
    majorActor += data;

    ss >> month;
    ss >> year;
}

/**
 * @brief  Equality Operator overload to compare 2 movies
 * @note   Classic movies are equal if their year and actor are equal
 * @param  movie: Other movie object to compare this->movie with
 * @retval True if equal, false if not equal
 */
bool Classic::operator==(const Movie& movie) const 
{
	const Classic& classicCast = static_cast<const Classic&>(movie);

	return (year == classicCast.year && month == classicCast.month
		&& majorActor == classicCast.majorActor);
}//end of ==

/**
 * @brief  Comparison operator overload
 * @note   compare in order of year - month - actor
 * @param  movie: Other movie object to compare this->movie with
 * @retval True if less than, false if greater/equal
 */
bool Classic::operator<(const Movie& movie) const 
{
	const Classic& classicCast = static_cast<const Classic&>(movie);

    //year has priority
	if (this->year < classicCast.year)
    {
        return true;
    }
	else if (this->year == classicCast.year)
    {
        //years are equal, compare months
        if (this->month < classicCast.month)
        {
            return true;
        }
        else if (this->month == classicCast.month)
        {
            //year and months are equal, so compare actors
            if (this->majorActor < classicCast.majorActor)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else 
        {
            return false;
        }
	}
	else
    {
        return false;
    }
}//end of <

/**
 * @brief  Operator overload for greater than using less than comparison overload
 * @note   Uses overloaded > operator
 * @param  movie: Other movie object to compare this->movie with
 * @retval 
 */
bool Classic::operator>(const Movie& movie) const 
{
	return !(*this < movie);
}//end of <

/**
 * @brief  Displays classic movie information
 * @note   
 * @retval None
 */
void Classic::display() const 
{
	cout << left << setw(30) << title << " "
		 << setw(18) << director << " " << setw(3) << month << " "
		 << setw(5) << year << " " << majorActor << endl;
}//end display

/**
 * @brief  Returns info of classic movie as string
 * @note   
 * @retval Classic movie information as string
 */
string Classic::getInfo() const 
{
    ostringstream ss;
    ss << "Classic: " << month << " " << year << " " << majorActor <<  " " << title << " " << director;
    return  ss.str();
}