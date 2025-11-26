#include "Sculpture.h"
#include <iostream>

int Sculpture::nofSculptures = 0; //Initializing of a static member

Sculpture::Sculpture()
{
    nofSculptures++; //Increments the static data member
}

Sculpture::Sculpture(string n, string m): Exhibit(n), materials(m){ //Overload constructor with an initializer list
    nofSculptures++;
}

Sculpture::Sculpture(string n, int y): Exhibit(n, y)
{
    nofSculptures++;
}

Sculpture::Sculpture(string n, int y, int c, string m): Exhibit(n, y, c), materials(m)
{
    nofSculptures++;
}

void Sculpture::display(){

    cout << "Type: Sculpture" << endl;
    Exhibit::display(); //This brings you to the display function of Exhibit constructor
    cout << "Materials: " << materials << endl;
    cout << endl;

}

Sculpture::~Sculpture()
{
    //dtor
}
