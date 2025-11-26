/* Jack Brady */

#ifndef EXHIBIT_H
#define EXHIBIT_H
#include <string>
#include "Artist.h"

using namespace std;

class Exhibit
{
    public:
        Exhibit();
        virtual ~Exhibit();
        Exhibit(string);
        Exhibit(string,int);
        Exhibit(string,int,int);
        Exhibit(Exhibit&);

        string getName() { return name; }
        void setName(string val) { name = val; }
        int getYearOfCreation() { return yearOfCreation; }
        void setYearOfCreation(int val) { yearOfCreation = val; }
        int getCost() { return cost; }
        void setCost(int val) { cost = val; }
        Artist* getArtist() { return artistPtr; }
        void setArtist(Artist* val);
        bool getIsAdded () { return isAdded; }
        void setIsAdded (bool val) { isAdded = val; }

        Exhibit& operator=(Exhibit&); //
        friend ostream& operator<<(ostream &cout, Exhibit*); //
        friend bool operator<(Exhibit&, Exhibit&); // Overloading less than operator
        friend bool operator>(Exhibit&, Exhibit&); // Overloading greater than operator
        friend bool operator==(Exhibit&, Exhibit&); // Overloading equal to than operator
        friend bool operator!=(Exhibit&, Exhibit&); // Overloading not equal to than operator


        virtual void display() = 0; //Pure virtual function that makes this class an abstract class

    private:
        string name;
        int yearOfCreation;
        int cost;
        bool isAdded;
        Artist *artistPtr; //Creates a pointer artistPtr from the artist class
};

#endif // EXHIBIT_H
