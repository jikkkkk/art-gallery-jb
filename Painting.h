/* Jack Brady */

#ifndef PAINTING_H
#define PAINTING_H
#include <string>
#include "Exhibit.h"

class Painting : public Exhibit
{
    public:
        Painting();
        Painting(string, bool); //Overloaded constructor with a string and bool as inputs
        Painting(string, int); //Overloaded constructor with a string and int as inputs
        Painting(string, int, int, bool); //Overloaded constructor with a string, two ints and a bool as inputs
        virtual ~Painting();

        bool getNeedsFrame() { return needsFrame; }
        void setNeedsFrame(bool val) { needsFrame = val; }
        int getNofPaintings() { return nofPaintings; }

        void display(); //Overriding display function in parent class

    private:
        bool needsFrame;
        static int nofPaintings;
};

#endif // PAINTING_H
