
#ifndef ARTIST_H
#define ARTIST_H
#include <string>
#include <iostream>
#include <set>
#include <algorithm>
//#include "Exhibit.h"
class Exhibit;

using namespace std;

class Artist
{
    public:
        Artist();
        Artist(string, string, int);
        Artist(string, string, int, int);
        virtual ~Artist();

        string getName() { return name; }
        void setName(string val) { name = val; }
        string getNationality() { return nationality; }
        void setNationality(string val) { nationality = val; }
        int getYearOfBirth() { return yearOfBirth; }
        void setYearOfBirth(int val) { yearOfBirth = val; }
        int getNofCreations () { return nofCreations; }
        void setNofCreations (int val)
        {
            //data integrity check (artist must have at least 1 creation)
            if (val > 0){
                nofCreations = val;
            }
            else{
                string e = "The number of creations must be greater than 0";
                throw e;
            }
        }

        friend ostream& operator<< (ostream &cout, Artist*); // overloaded ostream operator
        void addCreation(Exhibit*); // function to add Exhibit* to the set
        void display();

    private:
        string name;
        string nationality;
        int yearOfBirth;
        int nofCreations;
        set<Exhibit*> creations; //set with creations of the artist [1 to many aggregation realtionship]
};

#endif // ARTIST_H
