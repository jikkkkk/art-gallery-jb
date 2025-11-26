#include "Exhibit.h"
#include <iostream>

Exhibit::Exhibit() {
    artistPtr = new Artist(); //Dynamically allocates memory on the heap for a pointer
    isAdded = false;
};

Exhibit::Exhibit(string n) : name(n){
    artistPtr = new Artist(); //Dynamically allocates memory on the heap for a pointer
    isAdded = false;
}

Exhibit::Exhibit(string n,int y){
    name = n;
    yearOfCreation = y;
    artistPtr = new Artist(); //Dynamically allocates memory on the heap for a pointer
    isAdded = false;
}

Exhibit::Exhibit(string n, int y, int c): name(n), yearOfCreation(y), cost(c){
    artistPtr = new Artist(); //Dynamically allocates memory on the heap for a pointer
    isAdded = false;
}

Exhibit::Exhibit(Exhibit &e){
    cout << "Copy constructor Exhibit" << endl; // Copy constructor is used here to initialize a new object from an exisitng one
    name = e.name;
    yearOfCreation = e.yearOfCreation;
    cost = e.cost;
    isAdded = false;
    if (!artistPtr){
        delete artistPtr;
    }
    artistPtr = new Artist();
    artistPtr->setNationality(e.getArtist()->getNationality());
    artistPtr->setName(e.getArtist()->getName());
    artistPtr->setYearOfBirth(e.getArtist()->getYearOfBirth());
    try {
        artistPtr->setNofCreations(e.getArtist()->getNofCreations());
    }
    catch (string e){
        cout << e << endl;
    }
}

Exhibit::~Exhibit(){
    delete artistPtr;
    artistPtr = NULL; // The address that pointer points to contains free memory
}

void Exhibit::setArtist(Artist*aPtr){ //Function setting the data members for each artist object
    if (!artistPtr){
        delete artistPtr; // deallocates the memory on the heap for this pointer
    }
    artistPtr = new Artist();
    artistPtr->setNationality(aPtr->getNationality()); //Pointer artistPtr points to a function which sets the nationality of an artist
    artistPtr->setName(aPtr->getName()); //Pointer artistPtr points to a function which sets the name of an artist
    artistPtr->setYearOfBirth(aPtr->getYearOfBirth()); //Pointer artistPtr points to a function which sets the name of an artist
    try{
        artistPtr->setNofCreations(aPtr->getNofCreations());
    }
    catch (string e){
        cout << e << endl;
    } //Pointer artistPtr points to a function which sets the name of an artist
}

void Exhibit::display(){
    cout << "Name: " << name << endl;
    if (artistPtr->getName() != "unknown artist"){ //Only displaying artist for Exhibits that have an artist set to them
        cout << artistPtr;
    }else{
        cout << "Artist Unknown" << endl;
    }
    cout << "Year of creation: " << yearOfCreation << endl;
    cout << "Cost: " << cost << endl;
}

Exhibit& Exhibit::operator=(Exhibit &other){
    cout << "Assignment Operator Exhibit" << endl;
    name = other.name;
    yearOfCreation = other.yearOfCreation;
    cost = other.cost;
    isAdded = false;
        if (!artistPtr){
        delete artistPtr;
    }
    artistPtr = new Artist();
    artistPtr->setNationality(other.getArtist()->getNationality());
    artistPtr->setName(other.getArtist()->getName());
    artistPtr->setYearOfBirth(other.getArtist()->getYearOfBirth());
    try {
        artistPtr->setNofCreations(other.getArtist()->getNofCreations());
    }
    catch (string e){
        cout << e << endl;
    }
    return *this;
}

ostream& operator<< (ostream &cout, Exhibit *e){
    cout << "Artist: " << e->artistPtr->getName() << endl;
    cout << "Name of the Creation: " << e->getName() << endl;
    cout << "Year of Creation: " << e->getYearOfCreation() << endl;
    return cout;
 }

bool operator<(Exhibit &e1, Exhibit &e2){ //Function takes in two exhibit objects and uses less than operator to compare them based on the year of creation
    cout << "Calling overloaded < operator" << endl;
    return(e1.getYearOfCreation() < e2.getYearOfCreation());
}

bool operator>(Exhibit& e1, Exhibit& e2){ //Function takes in two exhibit objects and uses greater than operator to compare them based on the year of creation
    cout << "Calling overloaded > operator" << endl;
    return(e1.getYearOfCreation() > e2.getYearOfCreation());
}

bool operator==(Exhibit& e1, Exhibit& e2){ //Function takes in two exhibit objects and uses equal to operator to compare them based on the year of creation
    cout << "Calling overloaded == operator" << endl;
    return(e1.getYearOfCreation() == e2.getYearOfCreation());
}

bool operator!=(Exhibit& e1, Exhibit& e2){ //Function takes in two exhibit objects and uses not equal to operator to compare them based on the year of creation
    cout << "Calling overloaded != operator" << endl;
    return!(e1==e2);
}
