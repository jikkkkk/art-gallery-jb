/* Jack Brady */

#ifndef SCULPTURE_H
#define SCULPTURE_H
#include "Exhibit.h"
#include <string>

using namespace std;

class Sculpture : public Exhibit
{
    public:
        Sculpture();
        Sculpture(string); //Overloaded constructor with a string as an input
        Sculpture(string, int); //Overloaded constructor with a string and int as inputs
        Sculpture(string, string); //Overloaded constructor with two strings as inputs
        Sculpture(string, int, int, string); //Overloaded constructor with two strings and two ints as inputs
        virtual ~Sculpture();

        string getMaterials() { return materials; }
        void setMaterials(string val) { materials = val; }
        int getNofSculptures() { return nofSculptures; }

        void display(); // Overriding display function in parent class

    protected:

    private:
        string materials;
        static int nofSculptures;
};

#endif // SCULPTURE_H
