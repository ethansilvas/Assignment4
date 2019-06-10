#include "borrow.h"

Borrow::Borrow()
{
    errors = "";
}

Borrow::~Borrow()
{
    
}

void Borrow::processTransaction(string s, Customer* cust, Inventory* inv, HashTable& ht)
{
    string tmp;
    int id;
    //Customer * customer = nullptr;
    stringstream stream;
    stream << s;

    stream >> id;

    if (customerValid(cust, id))
    {
        getline(stream, tmp);
        readTransaction(tmp, cust, inv);
    }

}

void Borrow::borrowMovie(Customer*, Movie*, Movie*)
{
    
}

void Borrow::readTransaction(string info, Customer* cust, Inventory* inv)
{
    stringstream stream;
    char movie, media;
    string tmp1, tmp2, majorActor;
    int year=0, month=0;
    Movie* tempMovie = nullptr;
    Movie* custMovie = nullptr;

    stream << info;
    stream >> media;

    if (media == DVD)
    {
        stream >> movie;
        switch (movie)
        {
            case 'C':
                getline(stream, tmp1, ' ');
                getline(stream, tmp1, ' ');
                stringstream(tmp1) >> month;
                getline(stream, tmp1, ' ');
                stringstream(tmp1) >> year;
                stream >> tmp1;

                majorActor = majorActor + tmp1 + ' ';
                stream >> tmp1;
                majorActor += tmp1;

                //tempMovie = new Classic(majorActor, month, year); //Add constructor
                //custMovie = 

        }
    }
}