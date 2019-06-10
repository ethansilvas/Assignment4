//------------------------------- classic.cpp ----------------------------------
//
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: 
//------------------------------------------------------------------------------
// Purpose - 
// -----------------------------------------------------------------------------
// Assumptions: 
// -----------------------------------------------------------------------------

#include "classic.h"

Classic::Classic()
{

} //end default constructor 

Classic::Classic(const string& newActor, const int& newMonth, const int& newYear) 
{
    this->majorActor = newActor;
    this->month = newMonth;
    this->year = newYear;
}

Classic::Classic(const string& line) {
    parseData(line);
}

Classic::~Classic()
{
    
}

void Classic::parseData(const string& line) {
    stringstream ss;
    ss << line;
    string temp;                 // hold sub string from info string
    getline(ss, temp, ',');      // get type of movie (char)
    type = temp[0];
    getline(ss, temp, ',');      // get stock number (int)
    stringstream(temp) >> stock;
    getline(ss, director, ',');  // get director string
    getline(ss, title, ',');     // get title string
    ss >> temp;                  // add second name to first name
    majorActor += temp;
    majorActor += ' ';
    ss >> temp;                 // add second name to first name
    majorActor += temp;
    ss >> month;                // add month
    ss >> year;                 // add month
}

 bool Classic::operator==(const Movie& movie) const{
	const Classic& classicCast = static_cast<const Classic&>(movie);

	return (year == classicCast.year && month == classicCast.month
		&& this->majorActor == classicCast.majorActor);
}//end of ==

bool Classic::operator<(const Movie& movie) const {
	const Classic& classicCast = static_cast<const Classic&>(movie);

	if (this->year < classicCast.year)
    {
        return true;
    }
	else if (this->year == classicCast.year)
    {
        if (this->month < classicCast.month)
        {
            return true;
        }
        else if (this->month == classicCast.month)
        {
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

bool Classic::operator>(const Movie& movie) const {
	return !(*this < movie);
}//end of <

void Classic::display() const {
	
	cout << left << setw(22) << title << " "
		 << setw(18) << director << " "
		 << setw(3) << month << " "
		 << setw(5) << year << " "
		 << majorActor << endl;
}//end display

string Classic::getInfo() const 
{
    ostringstream ss;
    ss << "Classic: " << month << " " << year << " " << majorActor <<  " " << title << " " << director;
    return  ss.str();
}