#include "Painting.h"
#include <iostream>

int Painting::nofPaintings = 0; //Initializing of a static member

Painting::Painting()
{
    nofPaintings++; //Increments the static data member
}

Painting::Painting(string n, bool f): Exhibit(n), needsFrame(f){ //Overload constructor with an initializer list
    nofPaintings++;
}

Painting::Painting(string n, int y): Exhibit(n,y){
    nofPaintings++;
}

Painting::Painting(string n, int y, int c, bool f): Exhibit(n,y,c), needsFrame(f){
    nofPaintings++;
}


void Painting::display(){

    cout << "Type: Painting" << endl;
    Exhibit::display();
    if(needsFrame == true){ //If statement which displays whether or not the painting needs a frame
        cout << "This painting will require a frame" << endl;
    }
    else{
        cout << "This painting will not require a frame" << endl;
    }
    cout << endl;
}

Painting::~Painting()
{
    //dtor
}
