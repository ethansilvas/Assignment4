//------------------------------- movie.cpp ------------------------------------
//
// Ethan Silvas, Pranav Sakthivel CSS 343 B
// Creation Date: May 26, 2019
// Date of Last Modification: June 11, 2019 
//------------------------------------------------------------------------------
// Purpose - This is an abstract class for Movie to be used in Child Classes
// Drama, Comedy, and Classic. Contains implementation for a general Movie.
// -----------------------------------------------------------------------------
// Assumptions: Implemented as an abstract class.
// -----------------------------------------------------------------------------

#include "movie.h"

/**
 * @brief  Default no arg constructor for Movie
 * @note   Initializes all data members
 * @retval 
 */
Movie::Movie()
{
    this->title = "";
    this->director = "";
    this->year = 0;
    this->stock = 0;
    this->type = ' ';
} //end of default constructor 

/**
 * @brief  Destructor for Movie
 * @note   
 * @retval 
 */
Movie::~Movie() 
{

}

/**
 * @brief  Reads line and parses the data 
 * @note   
 * @param  line: String passed in
 * @retval None
 */
void Movie::parseData(const string& line)
{
    stringstream ss;
    ss << line;

    string data;

    //get the movieType
    getline(ss, data, ',');
    this->type = data[0];

    //read in stock 
    getline(ss, data, ',');
    stringstream(data) >> this->stock;

    //read in data members 
    getline(ss, director, ',');
    getline(ss, title, ',');
    getline(ss, data, ',');
    stringstream(data) >> this->year;
} //end of parseData

/**
 * @brief  Increase stock of movie
 * @note   
 * @param  addToStock: Stock count to increase by
 * @retval True if stock was increased successfully, false otherwise
 */
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

/**
 * @brief  Decrease stock of movie by 1
 * @note   
 * @retval True if stock was decreased successfully, false otherwise
 */
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

/**
 * @brief  Accessor method that returns stock of Movie
 * @note   
 * @retval stock count as integer
 */
int Movie::getStock() {
    return stock;
}