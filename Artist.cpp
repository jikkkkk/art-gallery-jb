#include "Artist.h"
#include "Exhibit.h"

// default constructor
Artist::Artist()
{
    name = "unknown artist";
}

// overloaded constructor and intialiser list
Artist::Artist(string ne, string ny, int y) : name(ne), nationality(ny), yearOfBirth(y){}
Artist::Artist(string ne, string ny, int y, int c) : name(ne), nationality(ny), yearOfBirth(y), nofCreations(c){}

// display fuction displaying all variables of the object
void Artist::display(){
    cout << "Name of the Artist: " << name << endl
    << "Nationality of the Artist: " << nationality <<endl
    << "Year of Birth: " << yearOfBirth << endl
    << "Number of Creations: " << nofCreations << endl
    << "Creations: " << endl;
    for (Exhibit *e : creations){ //display the set
        cout << e << endl; // use overloaded ostream operator in exhibit
    }
}

void Artist::addCreation(Exhibit *e){
    cout << "Adding creation" << endl;
    creations.insert(e); // use STL function insert to add an element to the set
}

ostream& operator<< (ostream &cout, Artist *a){ // overloaded ostream operator
    cout << "Name of the Artist: " << a->getName() << endl; // display name and year of birth
    cout << "Year of birth: " << a->getYearOfBirth() << endl;
    return cout;
 }

Artist::~Artist(){}
